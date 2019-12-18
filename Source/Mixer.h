/*
  ==============================================================================

    Mixer.h
    Created: 25 Nov 2019 12:23:57pm
    Author:  synthly

  ==============================================================================
*/

#pragma once
#include "Pattern.h"

class Mixer : public MixerAudioSource, public Component
{
public:
    Mixer()
    {
        inst1 = std::make_unique<Pattern>();
        addAndMakeVisible(*inst1);

        //inst2 = std::make_unique<Pattern>();
        //addAndMakeVisible(*inst2);

    }
    ~Mixer()
    {

    }

    void resized() override
    {
        auto fullArea = getLocalBounds();
        auto fullAreaHeight = fullArea.getHeight();

        inst1->setBounds(fullArea.removeFromTop(fullAreaHeight));
        //inst2->setBounds(fullArea.removeFromTop(fullAreaHeight/4));
        //inst1->setBounds(fullArea.removeFromTop(fullAreaHeight/4));
        //inst2->setBounds(fullArea.removeFromTop(fullAreaHeight/4));
    }
    void paint(Graphics& g) override
    {

    }
    void prepareToPlay(int samplesPerBlockExpected, double sampleRate) override
    {
        Logger::outputDebugString("Prepare to play for MIXER");

        inst1->prepareToPlay(samplesPerBlockExpected, sampleRate);
        //inst2->prepareToPlay(samplesPerBlockExpected, sampleRate);

        addInputSource(inst1.get(), false);
        //addInputSource(inst2.get(), false);
    }
    void releaseResources() override
    {
        inst1 = nullptr;
        //inst2 = nullptr;
    }
private:
    std::unique_ptr<Pattern> inst1;
    //std::unique_ptr<Pattern> inst2;
};