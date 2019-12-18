/*
  ==============================================================================

    Pattern.h
    Created: 7 Nov 2019 2:21:03pm
    Author:  synthly

  ==============================================================================
*/

#ifndef SYNTHLYOS_PATTERN_H
#define SYNTHLYOS_PATTERN_H

#include <cmath>
#include "Steps.h"
#include "StepLights.h"
#include "MIDI.h"

class Pattern : public Component, public AudioSource, public Thread, public MessageManagerLock {
public:
    Pattern() : Thread("Pattern Thread") {
        //INSTRUMENT1
        addAndMakeVisible(inst1_steps);

        inst1_openButton.onClick = [this] {
            inst1_openButtonClicked();
        };
        inst1_openButton.setButtonText("LOAD");
        inst1_openButton.setColour(TextButton::buttonColourId, Colours::slategrey);
        addAndMakeVisible(inst1_openButton);

        inst1_clearButton.onClick = [this] {
            inst1_clearButtonClicked();
        };
        inst1_clearButton.setButtonText("CLEAR");
        inst1_clearButton.setColour(TextButton::buttonColourId, Colours::slategrey);
        addAndMakeVisible(inst1_clearButton);

        inst1_Offset = 0;


        //BPM CONTROL
        bpmControl.onValueChange = [this] {
            bpmControlValueChanged();
        };

        bpmControl.setRange(60, 220);
        bpmControl.setValue(120, NotificationType::dontSendNotification);

        bpmControl.setSliderStyle(Slider::SliderStyle::LinearHorizontal);
        bpmControl.setColour(Slider::textBoxBackgroundColourId, Colours::slategrey);
        addAndMakeVisible(bpmControl);

        //STEPLIGHTS
        addAndMakeVisible(stepLights);

        //Sequencer init
        step = 0;
        seqOffset = 0;

        //Thread and AudioSource init
        formatManager.registerBasicFormats();
        startThread();
    }

    ~Pattern() override {
        stopThread(4000);


        //delete seqSteps;
        //seqSteps = nullptr;
    }

    //COMPONENT FUNCTIONS
    void resized() override {
        auto area = getLocalBounds();

        auto margin = area.getHeight() / 10;
        auto blockHeight = area.getHeight() / 5;
        //Add a margin by removing blank space
        //area.removeFromBottom(margin);

        //Setup controls
        auto controlArea = area.removeFromTop(margin);
        auto controlWidth = controlArea.getWidth() / 5;
        auto controlMargin = controlArea.getHeight() / 10;

        bpmControl.setBounds(controlArea.removeFromLeft(controlWidth).reduced(controlMargin));
        stepLights.setBounds(controlArea.removeFromRight(controlWidth * 4).reduced(controlMargin));

        //Setup first instrument
        auto instArea = area;
        auto instWidth = area.getWidth() / 5 * 4;
        auto instMargin = area.getHeight() / 50;

        inst1_steps.setBounds(area.removeFromRight(instWidth).reduced(instMargin));
        inst1_openButton.setBounds(area.removeFromLeft(instWidth / 8).reduced(instMargin));
        inst1_clearButton.setBounds(area.removeFromLeft(instWidth / 8).reduced(instMargin));
        //inst1_openButton.setBounds(area.removeFromLeft(instWidth/4).reduced(instMargin));

        /*
        auto seqArea = area.removeFromTop(blockHeight); //leave some room!
        auto seqWidth = seqArea.getWidth()/5*4;
        auto seqMargin = seqArea.getHeight()/10;

        inst1_steps.setBounds(seqArea.removeFromRight(seqWidth).reduced(seqMargin));
        inst1_openButton.setBounds(seqArea.removeFromLeft(seqWidth/4).reduced(seqMargin));
        //inst1_clearButton.setBounds(seqArea.removeFromLeft(seqWidth/8).reduced(seqMargin));
         */
    }

    void paint(Graphics &g) override {

    }

    //AUDIO SOURCE FUNCTIONS
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override {
        Logger::outputDebugString("Prepare to Play for PATTERN");
        currentSampleRate = (float) sampleRate;

        //Initialize sequencer variables
        bpm = (int) bpmControl.getValue();
        msPerBeat = 60000.0f / (float) bpm;
        msPerStep = msPerBeat / 4;
        samplesPerBeat = std::floor(msPerBeat * currentSampleRate / 1000);
        samplesPerBar = 4 * samplesPerBeat;
        samplesPerStep = samplesPerBeat / 4;

        String diagnostic =
                "BPM: " + String(bpm) + "\n" +
                "MS PER BEAT: " + String(msPerBeat) + "\n" +
                "MS PER STEP: " + String(msPerStep) + "\n" +
                "SAMPLES PER BEAT: " + String(samplesPerBeat) + "\n" +
                "SAMPLES PER BAR: " + String(samplesPerBar) + "\n" +
                "SAMPLES PER STEP: " + String(samplesPerStep) + "\n";

        Logger::outputDebugString(diagnostic);
    }

    void releaseResources() override {
        inst1_currentBuffer = nullptr;
    }

    void getNextAudioBlock(const AudioSourceChannelInfo &bufferToFill) override {
        //get reference to inst1_currentBuffer because user might be changing the file
        ThreadBuffer::Ptr usedCurrentBuffer(inst1_currentBuffer);

        //Clear output if source is not producing data
        if (usedCurrentBuffer == nullptr) {
            bufferToFill.clearActiveBufferRegion();
            //Logger::outputDebugString("NULL CURRENT BUFFER");
            return;
        }

        //Get data from INPUT buffer
        AudioBuffer<float> *inputBuffer = inst1_currentBuffer->getAudioBuffer();
        int inst1_Channels = inputBuffer->getNumChannels();
        int inst1_SamplesRem;

        //Get data from OUTPUT buffer
        int outputOffset = 0;
        int outputChannels = bufferToFill.buffer->getNumChannels();
        int outputSamplesRem = bufferToFill.numSamples;

        //Loop variables
        int samplesToProcess;

        //While the output buffer still has room
        while (outputSamplesRem > 0) {
            //How many samples need to be processed still
            inst1_SamplesRem = inputBuffer->getNumSamples() - inst1_Offset;
            samplesToProcess = jmin(inst1_SamplesRem, outputSamplesRem);

            //Process each channel
            for (auto channel = 0; channel < outputChannels; channel++) {
                bufferToFill.buffer->copyFrom(
                        //OUTPUT
                        channel,
                        bufferToFill.startSample + outputOffset,

                        //SOURCE
                        *inputBuffer,
                        channel % outputChannels,
                        inst1_Offset,
                        samplesToProcess
                );
            }

            //Update input and output buffer offsets after processing samples
            outputOffset += samplesToProcess;
            inst1_Offset += samplesToProcess;

            //How many samples do we still need to process?
            outputSamplesRem -= samplesToProcess;
        }

        //After filling up the output buffer, keep track of the offset we read from input buffer
        usedCurrentBuffer->offset = inst1_Offset;
    }

    int getStep() {
        return step;
    }

    void setStep(const int& a)
    {
        step = a;
    }
private:

    void checkPath()
    {
        String path;
        path.swapWith(inst1_chosenPath);

        if(path.isNotEmpty())
        {
            File wavFile(path);
            std::unique_ptr<AudioFormatReader> reader(formatManager.createReaderFor(wavFile));

            if(reader != nullptr)
            {
                ThreadBuffer::Ptr refBuffer = new ThreadBuffer(
                        wavFile.getFileName(),
                        (int) reader->numChannels,
                        (int) reader->lengthInSamples
                );

                //Copy WAV data to ThreadBuffer
                reader->read(
                        //DEST
                        refBuffer->getAudioBuffer(),
                        0,

                        //SOURCE
                        (int) reader->lengthInSamples,
                        0,
                        true,
                        true
                );

                //step = 0
                inst1_currentBuffer = refBuffer;

                //Add ThreadBuffer to array to keep track
                inst1_Buffers.add(refBuffer);

                //Set button to green
                const MessageManagerLock mmlock; //for having a "lock" on message thread temporarily
                inst1_openButton.setColour(TextButton::buttonColourId, Colours::green);
                inst1_openButton.setButtonText(wavFile.getFileName());

            } else{
                Logger::outputDebugString("Reader returned null");
            }
        } else{
            //Logger::outputDebugString("WAV path is incorrect" + path);
        }

    }

    void checkBuffers()
    {
        //Iterate over the inst1_Buffers array and remove entries until two are left
        for(auto i = inst1_Buffers.size(); --i>=0;)
        {
            //If there are two or more references, delete them since we already loaded the file
            if(inst1_Buffers.getUnchecked(i)->getReferenceCount() > 1)
            {
                inst1_Buffers.remove(i);
            }
        }
    }

    void bpmControlValueChanged()
    {
        //Initialize sequencer variables
        bpm = (int) bpmControl.getValue();
        msPerBeat = 60000.0f / (float) bpm;
        msPerStep = msPerBeat/4;
        samplesPerBeat = std::floor(msPerBeat * currentSampleRate / 1000);
        samplesPerBar = 4 * samplesPerBeat;
        samplesPerStep = samplesPerBeat / 4;

        String diagnostic =
                "BPM: " + String(bpm) + "\n" +
                "MS PER BEAT: " + String(msPerBeat) + "\n" +
                "MS PER STEP: " + String(msPerStep) + "\n" +
                "SAMPLES PER BEAT: " + String(samplesPerBeat) + "\n" +
                "SAMPLES PER BAR: " + String(samplesPerBar) + "\n" +
                "SAMPLES PER STEP: " + String(samplesPerStep) + "\n";

        Logger::outputDebugString(diagnostic);
    }

    void inst1_openButtonClicked()
    {
        FileChooser chooser("Select .WAV File", {}, "*.wav");
        if(chooser.browseForFileToOpen())
        {
            auto wavFile = chooser.getResult();
            auto wavPath = wavFile.getFullPathName();

            inst1_chosenPath.swapWith(wavPath);

            //Wake up the thread to checkPath() then checkBuffers()
            notify();
        }
    }

    void inst1_clearButtonClicked()
    {
        //setting the buffer to null will delete the data since its a smart ptr
        inst1_currentBuffer = nullptr;

        //Set button to green
        const MessageManagerLock mmlock; //for having a "lock" on message thread temporarily
        inst1_openButton.setColour(TextButton::buttonColourId, Colours::slategrey);
        inst1_openButton.setButtonText("LOAD");

        inst1_steps.resetSteps();
    }

    void checkMidi()
    {
        if(!midiQueue.empty())
        {
            MidiMessage msg = midiQueue.front();
            midiQueue.pop();

            int msgNum = msg.getNoteNumber();
            String msgName = juce::MidiMessage::getMidiNoteName(
                    msgNum,
                    true,
                    true,
                    3);

            Logger::outputDebugString("MIDI NAME: " + msgName + " NUM: " + String(msgNum) + " ON: " + String((int)msg.isNoteOn()));

            if(msg.isNoteOn())
            {
                const MessageManagerLock mmlock;
                inst1_steps.clickButton(msgNum);
            }

        }
    }

    void checkLights()
    {
        //Locks the message thread for the scope of this activation record!!!
        const MessageManagerLock mmlock;
        stepLights.updateStepLights(step);
    }

    void run() override
    {
        Logger::outputDebugString("START THREAD");

        while(!threadShouldExit())
        {
            checkPath();
            checkBuffers();
            checkMidi();
            checkLights();

            //PROCESS STEPS HERE
            if(inst1[step])
            {
                inst1_Offset = 0;
            }

            //Logger::outputDebugString("SEQ OFFSET: " + String(seqOffset) + " STEP: " + String(step));

            wait(msPerStep); //update time by one step

            seqOffset += samplesPerStep; //update offset ot be used by getNextAudioBlock()
            step++;

            if(step == 16)
            {
                step = 0;
                seqOffset = 0;
            }


        }
    }


    class ThreadBuffer : public ReferenceCountedObject
    {
    public:
        typedef ReferenceCountedObjectPtr<ThreadBuffer> Ptr;

        ThreadBuffer(const String& nameBuffer, int numChannels, int numSamples)
            : name(nameBuffer), buffer(numChannels, numSamples)
        {

        }

        ~ThreadBuffer()
        {

        }

        AudioBuffer<float>* getAudioBuffer()
        {
            return &buffer;
        }

        int offset = 0;

    private:
        String name;
        AudioBuffer<float> buffer;
    };

    const String appName = "Pattern";

    struct Instrument
    {
        Steps stepsComponent;
        Steps::StepState& steps = stepsComponent.getStepStates();
    };

    //MIDI
    MIDI midi;
    MIDI::MIDIQueue& midiQueue = midi.getMidiQueue();

    //SEQUENCING
    StepLights stepLights;
    Slider bpmControl;

    float currentSampleRate;
    float msPerBeat;
    float msPerStep;
    int samplesPerBeat;
    int samplesPerBar;
    int samplesPerStep;
    int bpm;

    int seqOffset;
    int step;

    //INSTRMENT 1
    Steps inst1_steps;
    Steps::StepState& inst1 = inst1_steps.getStepStates();
    int inst1_Offset;

    //FILE IO
    TextButton inst1_openButton;
    TextButton inst1_clearButton;
    String inst1_chosenPath;

    //READING WAVS
    AudioFormatManager formatManager;
    ReferenceCountedArray<ThreadBuffer> inst1_Buffers;
    ThreadBuffer::Ptr inst1_currentBuffer;
};
#endif