/*
  ==============================================================================

    MIDI.h
    Created: 20 Nov 2019 8:40:19pm
    Author:  synthly

  ==============================================================================
*/

#ifndef SYNTHLYOS_MIDI_H
#define SYNTHLYOS_MIDI_H

#include <queue>

class MIDI :    public Component,
                private MidiInputCallback
{
public:

    typedef std::queue<MidiMessage> MIDIQueue;


    MIDI()
            : //keyboardComponent (keyboardState, MidiKeyboardComponent::horizontalKeyboard),
              startTime (Time::getMillisecondCounterHiRes() * 0.001)
    {
        setOpaque (true);

        //MIDI INPUT LABEL
        addAndMakeVisible (midiInputListLabel);
        midiInputListLabel.setText ("MIDI Input:", dontSendNotification);
        midiInputListLabel.attachToComponent (&midiInputList, true);

        //COMBO BOX
        addAndMakeVisible (midiInputList);
        midiInputList.setTextWhenNoChoicesAvailable ("No MIDI Inputs Enabled");

        //Get HW level MIDI devices
        auto midiInputs = MidiInput::getAvailableDevices();

        /*
        //Store names of MIDI inputs in string array
        StringArray midiInputNames;
        for (auto input : midiInputs)
            midiInputNames.add (input.name);

        //Set the COMBO BOX to the available midi input names array
        midiInputList.addItemList (midiInputNames, 1);
        midiInputList.onChange = [this] { setMidiInput (midiInputList.getSelectedItemIndex()); };

        // find the first enabled device and use that by default
        for (auto input : midiInputs)
        {
            if (deviceManager.isMidiInputDeviceEnabled (input.identifier))
            {
                setMidiInput (midiInputs.indexOf (input));
                break;
            }
        }

        // if no enabled devices were found just use the first one in the list
        if (midiInputList.getSelectedId() == 0)
            setMidiInput (0);

         */

        //Make visible VIRTUAL KEYBOARD
        //addAndMakeVisible (keyboardComponent);

        //Add listener to MidiKeyboardState, since the class inherits MidiKeyboardStateListener
        //keyboardState.addListener (this);

        setMidiInput(1);


        //Display output for MIDI MESSAGES BOX
        addAndMakeVisible (midiMessagesBox);
        midiMessagesBox.setMultiLine (true);
        midiMessagesBox.setReturnKeyStartsNewLine (true);
        midiMessagesBox.setReadOnly (true);
        midiMessagesBox.setScrollbarsShown (true);
        midiMessagesBox.setCaretVisible (false);
        midiMessagesBox.setPopupMenuEnabled (true);
        midiMessagesBox.setColour (TextEditor::backgroundColourId, Colour (0x32ffffff));
        midiMessagesBox.setColour (TextEditor::outlineColourId, Colour (0x1c000000));
        midiMessagesBox.setColour (TextEditor::shadowColourId, Colour (0x16000000));

        setSize (600, 400);
    }

    ~MIDI() override
    {
        //keyboardState.removeListener (this);
        deviceManager.removeMidiInputDeviceCallback (MidiInput::getAvailableDevices()[midiInputList.getSelectedItemIndex()].identifier, this);
    }

    void paint (Graphics& g) override
    {
        g.fillAll (Colours::black);
    }

    void resized() override
    {
        auto area = getLocalBounds();

        midiInputList    .setBounds (area.removeFromTop (36).removeFromRight (getWidth() - 150).reduced (8));
        //keyboardComponent.setBounds (area.removeFromTop (80).reduced(8));
        //midiMessagesBox  .setBounds (area.reduced (8));
    }

    MIDIQueue& getMidiQueue()
    {
        return stepsPressed;
    }


private:


    //From MainContentComponent helper function to decode Midi Message
    static String getMidiMessageDescription (const MidiMessage& m)
    {
        if (m.isNoteOn())           return "Note on "          + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
        if (m.isNoteOff())          return "Note off "         + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3);
        if (m.isProgramChange())    return "Program change "   + String (m.getProgramChangeNumber());
        if (m.isPitchWheel())       return "Pitch wheel "      + String (m.getPitchWheelValue());
        if (m.isAftertouch())       return "After touch "      + MidiMessage::getMidiNoteName (m.getNoteNumber(), true, true, 3) +  ": " + String (m.getAfterTouchValue());
        if (m.isChannelPressure())  return "Channel pressure " + String (m.getChannelPressureValue());
        if (m.isAllNotesOff())      return "All notes off";
        if (m.isAllSoundOff())      return "All sound off";
        if (m.isMetaEvent())        return "Meta event";

        if (m.isController())
        {
            String name (MidiMessage::getControllerName (m.getControllerNumber()));

            if (name.isEmpty())
                name = "[" + String (m.getControllerNumber()) + "]";

            return "Controller " + name + ": " + String (m.getControllerValue());
        }

        return String::toHexString (m.getRawData(), m.getRawDataSize());
    }

    //From MainContentComponent
    void logMessage (const String& m)
    {
        midiMessagesBox.moveCaretToEnd();
        midiMessagesBox.insertTextAtCaret (m + newLine);
    }

    //From MainContentComponent Constructor
    void setMidiInput (int index)
    {
        Array<MidiDeviceInfo> list = MidiInput::getAvailableDevices(); //get devices from HW

        //Remove previous MIDI input listener
        deviceManager.removeMidiInputDeviceCallback(list[lastInputIndex].identifier, this);

        //Get object
        MidiDeviceInfo newInput = list[index];

        //Check to make sure if the selected input MIDI is already enabled
        if (! deviceManager.isMidiInputDeviceEnabled (newInput.identifier))
            //Enable MIDI input once condition is asserted above
            deviceManager.setMidiInputDeviceEnabled (newInput.identifier, true);

        //Add new MIDI input listener for the selected MIDI input
        deviceManager.addMidiInputDeviceCallback (newInput.identifier, this);

        //Sets the combobox to the selected MIDI input
        midiInputList.setSelectedId (index + 1, dontSendNotification);

        lastInputIndex = index;
    }

    //From MidiInputCallback

    // These methods handle callbacks from the midi device + on-screen keyboard..
    void handleIncomingMidiMessage (MidiInput* source, const MidiMessage& message) override
    {
        //ScopedValueSetter changes a variable momentarily until the static variable goes out of scope
        const ScopedValueSetter<bool> scopedInputFlag (isAddingFromMidiInput, true);

        //Send MIDI message to MidiKeyboardState to "handle"
        keyboardState.processNextMidiEvent (message);

        //Add the incoming MIDI msg from HW into the message handler class
        postMessageToList (message, source->getName());

        stepsPressed.push(message);
    }

    /*
    //FOR VIRTUAL KEYBOARD
    //From MidiKeyboardStateListener
    void handleNoteOn (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        //when handleIncomingMidiMessage is running, this variable will be true, and if statement will not run
        if (! isAddingFromMidiInput)
        {
            auto m = MidiMessage::noteOn (midiChannel, midiNoteNumber, velocity);

            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
            postMessageToList (m, "On-Screen Keyboard");
        }
    }

    //From MidiKeyboardStateListener
    void handleNoteOff (MidiKeyboardState*, int midiChannel, int midiNoteNumber, float velocity) override
    {
        if (! isAddingFromMidiInput)
        {
            auto m = MidiMessage::noteOff (midiChannel, midiNoteNumber);
            m.setTimeStamp (Time::getMillisecondCounterHiRes() * 0.001);
            postMessageToList (m, "On-Screen Keyboard");
        }
    }
    */

    // This is used to dispach an incoming message to the message thread
    class IncomingMessageCallback   : public CallbackMessage
    {
    public:
        IncomingMessageCallback (MIDI* o, const MidiMessage& m, const String& s)
                : owner (o), message (m), source (s)
        {}

        void messageCallback() override
        {
            if (owner != nullptr)
                owner->addMessageToList (message, source);
        }

        Component::SafePointer<MIDI> owner;
        MidiMessage message;
        String source;
    };


    //From MainContentComponent
    void postMessageToList (const MidiMessage& message, const String& source)
    {
        //IncomingMessageCallback::post() adds the object to the queue that is handled
        //by MessageManager class (super class of CallbackMessage, which is super class of IncomingMsgCallback)
        (new IncomingMessageCallback (this, message, source))->post();

        //Once the MessageManager class finds it in the queue, it will call messageCallback() on message thread
        //After calling messageCallback(), IncomingMessageCallback object in the heap will be deleted

    }

    //From MainContentComponent
    void addMessageToList (const MidiMessage& message, const String& source)
    {
        auto time = message.getTimeStamp() - startTime;

        auto hours   = ((int) (time / 3600.0)) % 24;
        auto minutes = ((int) (time / 60.0)) % 60;
        auto seconds = ((int) time) % 60;
        auto millis  = ((int) (time * 1000.0)) % 1000;

        auto timecode = String::formatted ("%02d:%02d:%02d.%03d",
                                           hours,
                                           minutes,
                                           seconds,
                                           millis);

        auto description = getMidiMessageDescription (message);

        String midiMessageString (timecode + "  -  " + description + " (" + source + ")"); // [7]
        logMessage (midiMessageString);
    }

    AudioDeviceManager deviceManager;
    ComboBox midiInputList;
    Label midiInputListLabel;
    int lastInputIndex = 0;
    bool isAddingFromMidiInput = false;

    MidiKeyboardState keyboardState;
    //MidiKeyboardComponent keyboardComponent;

    TextEditor midiMessagesBox;
    double startTime;

    //FOR PATTERN
    MIDIQueue stepsPressed;

};

#endif