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
#include <unordered_map>
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class Steps  : public Component,
               public Button::Listener
{
public:
    //==============================================================================
    Steps ();
    ~Steps();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.

    typedef std::bitset<16> StepState;
    //typedef std::unordered_map<int, std::unique_ptr<TextButton>&> ButtonMap;

    //typedef std::unique_ptr<StepState> StepStatePtr;

    StepState& getStepStates()
    {
        return stepStates;
    }

    void clickButton(int note);
    void resetSteps();


    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    StepState stepStates;
    //ButtonMap buttonMap;

    enum MIDISteps
    {
        STEP0=40,
        STEP1=41,
        STEP2=42,
        STEP3=43,

        STEP4=48,
        STEP5=49,
        STEP6=50,
        STEP7=51,

        STEP8=36,
        STEP9=37,
        STEP10=38,
        STEP11=39,

        STEP12=44,
        STEP13=45,
        STEP14=46,
        STEP15=47
    };

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
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Steps)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

