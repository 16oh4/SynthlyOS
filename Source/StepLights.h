/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.4

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include <bitset>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class StepLights  : public Component,
                    public Button::Listener
{
public:
    //==============================================================================
    StepLights ();
    ~StepLights();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    typedef std::bitset<16> lights;


    void updateStepLights(int step)
    {
        switch(step)
        {
            case 0:
                textButton16->setColour(TextButton::buttonColourId, Colours::brown);

                textButton->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 1:
                textButton->setColour(TextButton::buttonColourId, Colours::brown);

                textButton2->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 2:
                textButton2->setColour(TextButton::buttonColourId, Colours::brown);

                textButton3->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 3:
                textButton3->setColour(TextButton::buttonColourId, Colours::brown);

                textButton4->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 4:
                textButton4->setColour(TextButton::buttonColourId, Colours::brown);

                textButton5->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 5:
                textButton5->setColour(TextButton::buttonColourId, Colours::brown);

                textButton6->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 6:
                textButton6->setColour(TextButton::buttonColourId, Colours::brown);

                textButton7->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 7:
                textButton7->setColour(TextButton::buttonColourId, Colours::brown);

                textButton8->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 8:
                textButton8->setColour(TextButton::buttonColourId, Colours::brown);

                textButton9->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 9:
                textButton9->setColour(TextButton::buttonColourId, Colours::brown);

                textButton10->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 10:
                textButton10->setColour(TextButton::buttonColourId, Colours::brown);

                textButton11->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 11:
                textButton11->setColour(TextButton::buttonColourId, Colours::brown);

                textButton12->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 12:
                textButton12->setColour(TextButton::buttonColourId, Colours::brown);

                textButton13->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 13:
                textButton13->setColour(TextButton::buttonColourId, Colours::brown);

                textButton14->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 14:
                textButton14->setColour(TextButton::buttonColourId, Colours::brown);

                textButton15->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;
            case 15:
                textButton15->setColour(TextButton::buttonColourId, Colours::brown);

                textButton16->setColour(TextButton::buttonColourId, Colours::lightyellow);
                break;

        }
    }


    std::unique_ptr<TextButton>& getTextButton()
    {
        return textButton;
    }

    std::unique_ptr<TextButton>& getTextButton2()
    {
        return textButton2;
    }


    std::unique_ptr<TextButton>& getTextButton3()
    {
        return textButton3;
    }

    std::unique_ptr<TextButton>& getTextButton4()
    {
        return textButton4;
    }

    std::unique_ptr<TextButton>& getTextButton5()
    {
        return textButton5;
    }

    std::unique_ptr<TextButton>& getTextButton6()
    {
        return textButton6;
    }

    std::unique_ptr<TextButton>& getTextButton7()
    {
        return textButton7;
    }

    std::unique_ptr<TextButton>& getTextButton8()
    {
        return textButton8;
    }

    std::unique_ptr<TextButton>& getTextButton9()
    {
        return textButton9;
    }

    std::unique_ptr<TextButton>& getTextButton10()
    {
        return textButton10;
    }

    std::unique_ptr<TextButton>& getTextButton11()
    {
        return textButton11;
    }

    std::unique_ptr<TextButton>& getTextButton12()
    {
        return textButton12;
    }

    std::unique_ptr<TextButton>& getTextButton13()
    {
        return textButton13;
    }

    std::unique_ptr<TextButton>& getTextButton14()
    {
        return textButton14;
    }

    std::unique_ptr<TextButton>& getTextButton15()
    {
        return textButton15;
    }

    std::unique_ptr<TextButton>& getTextButton16()
    {
        return textButton16;
    }
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<TextButton> textButton;
    std::unique_ptr<TextButton> textButton2;
    std::unique_ptr<TextButton> textButton3;
    std::unique_ptr<TextButton> textButton4;
    std::unique_ptr<TextButton> textButton5;
    std::unique_ptr<TextButton> textButton6;
    std::unique_ptr<TextButton> textButton7;
    std::unique_ptr<TextButton> textButton8;
    std::unique_ptr<TextButton> textButton9;
    std::unique_ptr<TextButton> textButton10;
    std::unique_ptr<TextButton> textButton11;
    std::unique_ptr<TextButton> textButton12;
    std::unique_ptr<TextButton> textButton13;
    std::unique_ptr<TextButton> textButton14;
    std::unique_ptr<TextButton> textButton15;
    std::unique_ptr<TextButton> textButton16;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (StepLights)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

