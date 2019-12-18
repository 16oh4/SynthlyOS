//
// Created by synthly on 10/4/19.
//

#ifndef SYNTHLYOS_HOMESCREEN_H
#define SYNTHLYOS_HOMESCREEN_H

#include "Helpers.h"

class Homescreen : public Component
{
public:
    Homescreen()
    {

        //Register listeners to broadcasters
        //Homescreen is a listener because it inherits listener class
        //effectsButton.addListener(this);

        //VOID to setup ImageButtons and make them visible
        initImageButtons();

        //VOID to setup Labels and make them visible
        initLabels();


    }

    ~Homescreen() override
    {
        setLookAndFeel(nullptr);
        //effectsButton.removeListener(this); //remove the listener (good practice)
    }

    void effectsAction()
    {
        auto currentTime = Time::getCurrentTime();
        auto currentTimeString = currentTime.toString(true, true);

        effectsLabel.setText(currentTimeString, dontSendNotification);
    }

    void paint(Graphics& g) override
    {
        g.setColour(Colours::darkblue);
        g.fillRect(buttonArea);
    }


    void resized() override
    {
        auto area = getLocalBounds();
        //Gather information about main window
        auto appButtonWidth     = area.getWidth()/3;
        auto appButtonHeight    = area.getHeight()/3;
        auto appTextHeight      = appButtonHeight/10;
        auto appButtonMargin    = appButtonHeight/8; //same as text height

         //SETUP FIRST DRAWER
        auto firstDrawer = area.removeFromTop(appButtonHeight-appButtonMargin);

        //Draw each app square
        auto appChunk = firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin);
        effectsButton.setBounds(appChunk);
        effectsTButton.setBounds(appChunk);

        mixerButton.setBounds(firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));
        midiButton.setBounds(firstDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));

        // Draw text for each app square
        // Everytime removeFrom function is called, the caller is permanently changed!!
        // getLocalBounds() returns the size of component at coord (0,0)
        // getBounds() returns the location of component with respect to top left of parent

        auto firstDrawerText = area.removeFromTop(appButtonMargin);

        effectsLabel.setBounds(firstDrawerText.removeFromLeft(appButtonWidth));
        mixerLabel.setBounds(firstDrawerText.removeFromLeft(appButtonWidth));
        midiLabel.setBounds(firstDrawerText.removeFromLeft(appButtonWidth));

        //SETUP SECOND DRAWER
        auto secondDrawer = area.removeFromTop(appButtonHeight-appButtonMargin);

        wavesButton.setBounds(secondDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));
        tracksButton.setBounds(secondDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));
        patternButton.setBounds(secondDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));

        //Draw Labels for Apps
        auto secondDrawerText = area.removeFromTop(appButtonMargin);

        wavesLabel.setBounds(secondDrawerText.removeFromLeft(appButtonWidth));
        tracksLabel.setBounds(secondDrawerText.removeFromLeft(appButtonWidth));
        patternLabel.setBounds(secondDrawerText.removeFromLeft(appButtonWidth));

        //SETUP THIRD DRAWER
        auto thirdDrawer = area.removeFromTop(appButtonHeight-appButtonMargin);

        samplerButton.setBounds(thirdDrawer.removeFromLeft(appButtonWidth).reduced(appButtonMargin));

        //Draw Labels for Apps
        auto thirdDrawerText = area.removeFromTop(appButtonMargin);
        samplerLabel.setBounds(thirdDrawerText.removeFromLeft(appButtonWidth));
    }

    ImageButton effectsButton, mixerButton, midiButton, wavesButton,
            tracksButton, patternButton, samplerButton;

private:
    //Internal Components
    //TODO: change TextButton to image button to display app

    TextButton effectsTButton;

    Label effectsLabel, mixerLabel, midiLabel, wavesLabel, tracksLabel, patternLabel, samplerLabel;

    Rectangle<int> buttonArea;

    const String appName = "Home";


    void initImageButtons()
    {
        Helpers::setupImageButton(effectsButton, "effects_png");
        addAndMakeVisible(effectsButton, 0);
        //addAndMakeVisible(effectsTButton, 0);

        Helpers::setupImageButton(mixerButton, "mixer_png");
        addAndMakeVisible(mixerButton, 0);

        Helpers::setupImageButton(midiButton, "midi_png");
        addAndMakeVisible(midiButton, 0);

        Helpers::setupImageButton(wavesButton, "waves_png");
        addAndMakeVisible(wavesButton, 0);

        Helpers::setupImageButton(tracksButton, "tracks_png");
        addAndMakeVisible(tracksButton, 0);

        Helpers::setupImageButton(patternButton, "pattern_png");
        addAndMakeVisible(patternButton, 0);

        Helpers::setupImageButton(samplerButton, "sampler_png");
        addAndMakeVisible(samplerButton, 0);
    }

    void initLabels()
    {
        effectsLabel.setText("EFFECTS", NotificationType::dontSendNotification);
        effectsLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(effectsLabel, 0);

        mixerLabel.setText("MIXER", NotificationType::dontSendNotification);
        mixerLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(mixerLabel,0);

        midiLabel.setText("MIDI", NotificationType::dontSendNotification);
        midiLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(midiLabel,0);

        wavesLabel.setText("WAVES", NotificationType::dontSendNotification);
        wavesLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(wavesLabel, 0);

        tracksLabel.setText("TRACKS", NotificationType::dontSendNotification);
        tracksLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(tracksLabel,0);

        patternLabel.setText("PATTERN", NotificationType::dontSendNotification);
        patternLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(patternLabel,0);

        samplerLabel.setText("SAMPLER", NotificationType::dontSendNotification);
        samplerLabel.setJustificationType(Justification::centredTop);
        addAndMakeVisible(samplerLabel,0);
    }
};

#endif //SYNTHLYOS_HOMESCREEN_H