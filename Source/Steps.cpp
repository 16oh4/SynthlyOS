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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "Steps.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
Steps::Steps ()
{
    //[Constructor_pre] You can add your own custom stuff here..

    //buttonMap.insert(std::make_pair(40, textButton));

    //[/Constructor_pre]

    textButton.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton.get());
    textButton->setButtonText (String());
    textButton->addListener (this);

    textButton2.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton2.get());
    textButton2->setButtonText (String());
    textButton2->addListener (this);

    textButton3.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton3.get());
    textButton3->setButtonText (String());
    textButton3->addListener (this);

    textButton4.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton4.get());
    textButton4->setButtonText (String());
    textButton4->addListener (this);

    textButton5.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton5.get());
    textButton5->setButtonText (String());
    textButton5->addListener (this);
    textButton5->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton6.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton6.get());
    textButton6->setButtonText (String());
    textButton6->addListener (this);
    textButton6->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton7.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton7.get());
    textButton7->setButtonText (String());
    textButton7->addListener (this);
    textButton7->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton8.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton8.get());
    textButton8->setButtonText (String());
    textButton8->addListener (this);
    textButton8->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton9.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton9.get());
    textButton9->setButtonText (String());
    textButton9->addListener (this);

    textButton10.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton10.get());
    textButton10->setButtonText (String());
    textButton10->addListener (this);

    textButton11.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton11.get());
    textButton11->setButtonText (String());
    textButton11->addListener (this);

    textButton12.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton12.get());
    textButton12->setButtonText (String());
    textButton12->addListener (this);

    textButton13.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton13.get());
    textButton13->setButtonText (String());
    textButton13->addListener (this);
    textButton13->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton14.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton14.get());
    textButton14->setButtonText (String());
    textButton14->addListener (this);
    textButton14->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton15.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton15.get());
    textButton15->setButtonText (String());
    textButton15->addListener (this);
    textButton15->setColour (TextButton::buttonColourId, Colour (0xff0b906a));

    textButton16.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton16.get());
    textButton16->setButtonText (String());
    textButton16->addListener (this);
    textButton16->setColour (TextButton::buttonColourId, Colour (0xff0b906a));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..

    //Before clicked() callback, the textbutton will be toggled
    textButton->setClickingTogglesState(true);
    textButton2->setClickingTogglesState(true);
    textButton3->setClickingTogglesState(true);
    textButton4->setClickingTogglesState(true);

    textButton5->setClickingTogglesState(true);
    textButton6->setClickingTogglesState(true);
    textButton7->setClickingTogglesState(true);
    textButton8->setClickingTogglesState(true);

    textButton9->setClickingTogglesState(true);
    textButton10->setClickingTogglesState(true);
    textButton11->setClickingTogglesState(true);
    textButton12->setClickingTogglesState(true);

    textButton13->setClickingTogglesState(true);
    textButton14->setClickingTogglesState(true);
    textButton15->setClickingTogglesState(true);
    textButton16->setClickingTogglesState(true);


    //Logger::outputDebugString(stepStates.to_string());

    //[/Constructor]
}

Steps::~Steps()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    textButton = nullptr;
    textButton2 = nullptr;
    textButton3 = nullptr;
    textButton4 = nullptr;
    textButton5 = nullptr;
    textButton6 = nullptr;
    textButton7 = nullptr;
    textButton8 = nullptr;
    textButton9 = nullptr;
    textButton10 = nullptr;
    textButton11 = nullptr;
    textButton12 = nullptr;
    textButton13 = nullptr;
    textButton14 = nullptr;
    textButton15 = nullptr;
    textButton16 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void Steps::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    {
        float x = static_cast<float> (proportionOfWidth (0.0000f)), y = static_cast<float> (proportionOfHeight (0.0000f)), width = static_cast<float> (proportionOfWidth (1.0000f)), height = static_cast<float> (proportionOfHeight (1.0000f));
        Colour fillColour = Colours::grey;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRoundedRectangle (x, y, width, height, 9.000f);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void Steps::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (proportionOfWidth (0.0234f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton2->setBounds (proportionOfWidth (0.0834f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton3->setBounds (proportionOfWidth (0.1435f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton4->setBounds (proportionOfWidth (0.2025f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton5->setBounds (proportionOfWidth (0.2625f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton6->setBounds (proportionOfWidth (0.3226f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton7->setBounds (proportionOfWidth (0.3815f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton8->setBounds (proportionOfWidth (0.4438f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton9->setBounds (proportionOfWidth (0.5039f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton10->setBounds (proportionOfWidth (0.5628f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton11->setBounds (proportionOfWidth (0.6229f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton12->setBounds (proportionOfWidth (0.6830f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton13->setBounds (proportionOfWidth (0.7419f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton14->setBounds (proportionOfWidth (0.8042f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton15->setBounds (proportionOfWidth (0.8643f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    textButton16->setBounds (proportionOfWidth (0.9233f), proportionOfHeight (0.1503f), proportionOfWidth (0.0501f), proportionOfHeight (0.6994f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void Steps::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        stepStates[0] = ~stepStates[0];

        if(stepStates[0])
        {
            //Logger::outputDebugString("STEP0 is HIGH");
            textButton->setColour(TextButton::buttonColourId, Colours::black);
            textButton->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            //Logger::outputDebugString("STEP0 is LOW");
            textButton->setColour(TextButton::buttonColourId, Colours::white);
            textButton->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2.get())
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        stepStates[1] = ~stepStates[1];

        if(stepStates[1])
        {
            textButton2->setColour(TextButton::buttonColourId, Colours::black);
            textButton2->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton2->setColour(TextButton::buttonColourId, Colours::white);
            textButton2->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3.get())
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        stepStates[2] = ~stepStates[2];

        if(stepStates[2])
        {
            textButton3->setColour(TextButton::buttonColourId, Colours::black);
            textButton3->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton3->setColour(TextButton::buttonColourId, Colours::white);
            textButton3->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4.get())
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        stepStates[3] = ~stepStates[3];

        if(stepStates[3])
        {
            textButton4->setColour(TextButton::buttonColourId, Colours::black);
            textButton4->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton4->setColour(TextButton::buttonColourId, Colours::white);
            textButton4->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton5.get())
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        stepStates[4] = ~stepStates[4];

        if(stepStates[4])
        {
            textButton5->setColour(TextButton::buttonColourId, Colours::black);
            textButton5->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton5->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton5->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == textButton6.get())
    {
        //[UserButtonCode_textButton6] -- add your button handler code here..
        stepStates[5] = ~stepStates[5];

        if(stepStates[5])
        {
            textButton6->setColour(TextButton::buttonColourId, Colours::black);
            textButton6->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton6->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton6->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }


        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton6]
    }
    else if (buttonThatWasClicked == textButton7.get())
    {
        //[UserButtonCode_textButton7] -- add your button handler code here..
        stepStates[6] = ~stepStates[6];

        if(stepStates[6])
        {
            textButton7->setColour(TextButton::buttonColourId, Colours::black);
            textButton7->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton7->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton7->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton7]
    }
    else if (buttonThatWasClicked == textButton8.get())
    {
        //[UserButtonCode_textButton8] -- add your button handler code here..
        stepStates[7] = ~stepStates[7];

        if(stepStates[7])
        {
            textButton8->setColour(TextButton::buttonColourId, Colours::black);
            textButton8->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton8->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton8->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton8]
    }
    else if (buttonThatWasClicked == textButton9.get())
    {
        //[UserButtonCode_textButton9] -- add your button handler code here..
        stepStates[8] = ~stepStates[8];

        if(stepStates[8])
        {
            textButton9->setColour(TextButton::buttonColourId, Colours::black);
            textButton9->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton9->setColour(TextButton::buttonColourId, Colours::white);
            textButton9->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton9]
    }
    else if (buttonThatWasClicked == textButton10.get())
    {
        //[UserButtonCode_textButton10] -- add your button handler code here..
        stepStates[9] = ~stepStates[9];

        if(stepStates[9])
        {
            textButton10->setColour(TextButton::buttonColourId, Colours::black);
            textButton10->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton10->setColour(TextButton::buttonColourId, Colours::white);
            textButton10->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton10]
    }
    else if (buttonThatWasClicked == textButton11.get())
    {
        //[UserButtonCode_textButton11] -- add your button handler code here..
        stepStates[10] = ~stepStates[10];

        if(stepStates[10])
        {
            textButton11->setColour(TextButton::buttonColourId, Colours::black);
            textButton11->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton11->setColour(TextButton::buttonColourId, Colours::white);
            textButton11->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton11]
    }
    else if (buttonThatWasClicked == textButton12.get())
    {
        //[UserButtonCode_textButton12] -- add your button handler code here..
        stepStates[11] = ~stepStates[11];

        if(stepStates[11])
        {
            textButton12->setColour(TextButton::buttonColourId, Colours::black);
            textButton12->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton12->setColour(TextButton::buttonColourId, Colours::white);
            textButton12->setColour(TextButton::buttonOnColourId, Colours::white);
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton12]
    }
    else if (buttonThatWasClicked == textButton13.get())
    {
        //[UserButtonCode_textButton13] -- add your button handler code here..
        stepStates[12] = ~stepStates[12];

        if(stepStates[12])
        {
            textButton13->setColour(TextButton::buttonColourId, Colours::black);
            textButton13->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton13->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton13->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton13]
    }
    else if (buttonThatWasClicked == textButton14.get())
    {
        //[UserButtonCode_textButton14] -- add your button handler code here..
        stepStates[13] = ~stepStates[13];

        if(stepStates[13])
        {
            textButton14->setColour(TextButton::buttonColourId, Colours::black);
            textButton14->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton14->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton14->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton14]
    }
    else if (buttonThatWasClicked == textButton15.get())
    {
        //[UserButtonCode_textButton15] -- add your button handler code here..
        stepStates[14] = ~stepStates[14];

        if(stepStates[14])
        {
            textButton15->setColour(TextButton::buttonColourId, Colours::black);
            textButton15->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            textButton15->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
            textButton15->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton15]
    }
    else if (buttonThatWasClicked == textButton16.get())
    {
        //[UserButtonCode_textButton16] -- add your button handler code here..
        stepStates[15] = ~stepStates[15];

        if(stepStates[15])
        {
            textButton16->setColour(TextButton::buttonColourId, Colours::black);
            textButton16->setColour(TextButton::buttonOnColourId, Colours::black);
        }
        else
        {
            //textButton16->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
           // textButton16->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
        }

        //Logger::outputDebugString(stepStates.to_string());
        //[/UserButtonCode_textButton16]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void Steps::clickButton(int note) {
    switch(note)
    {
        case STEP0:
            buttonClicked(textButton.get());
            break;
        case STEP1:
            buttonClicked(textButton2.get());
            break;
        case STEP2:
            buttonClicked(textButton3.get());
            break;
        case STEP3:
            buttonClicked(textButton4.get());
            break;
        case STEP4:
            buttonClicked(textButton5.get());
            break;
        case STEP5:
            buttonClicked(textButton6.get());
            break;
        case STEP6:
            buttonClicked(textButton7.get());
            break;
        case STEP7:
            buttonClicked(textButton8.get());
            break;
        case STEP8:
            buttonClicked(textButton9.get());
            break;
        case STEP9:
            buttonClicked(textButton10.get());
            break;
        case STEP10:
            buttonClicked(textButton11.get());
            break;
        case STEP11:
            buttonClicked(textButton12.get());
            break;
        case STEP12:
            buttonClicked(textButton13.get());
            break;
        case STEP13:
            buttonClicked(textButton14.get());
            break;
        case STEP14:
            buttonClicked(textButton15.get());
            break;
        case STEP15:
            buttonClicked(textButton16.get());
            break;
    }
}

void Steps::resetSteps()
{
    stepStates.reset();

    textButton->setColour(TextButton::buttonColourId, Colours::white);
    textButton->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton2->setColour(TextButton::buttonColourId, Colours::white);
    textButton2->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton3->setColour(TextButton::buttonColourId, Colours::white);
    textButton3->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton4->setColour(TextButton::buttonColourId, Colours::white);
    textButton4->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton5->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton5->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton6->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton6->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton7->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton7->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton8->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton8->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton9->setColour(TextButton::buttonColourId, Colours::white);
    textButton9->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton10->setColour(TextButton::buttonColourId, Colours::white);
    textButton10->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton11->setColour(TextButton::buttonColourId, Colours::white);
    textButton11->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton12->setColour(TextButton::buttonColourId, Colours::white);
    textButton12->setColour(TextButton::buttonOnColourId, Colours::white);

    textButton13->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton13->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton14->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton14->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton15->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton15->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));

    textButton16->setColour(TextButton::buttonColourId, Colour (0xff0b906a));
    textButton16->setColour(TextButton::buttonOnColourId, Colour (0xff0b906a));
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="Steps" componentName="" parentClasses="public Component"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="0" initialWidth="600"
                 initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <ROUNDRECT pos="0% 0% 100% 100%" cornerSize="9.0" fill="solid: ff808080"
               hasStroke="0"/>
  </BACKGROUND>
  <TEXTBUTTON name="new button" id="694e1983ac89470c" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="2.336% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="7326b87f67a6699f" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="8.343% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="9d9133f5236ca30e" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="14.349% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a7c2a0cfae67e1a1" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="20.245% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d603b44410e603fd" memberName="textButton5"
              virtualName="" explicitFocusOrder="0" pos="26.251% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="12885613e4a0820f" memberName="textButton6"
              virtualName="" explicitFocusOrder="0" pos="32.258% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="71b5c0bb433595e7" memberName="textButton7"
              virtualName="" explicitFocusOrder="0" pos="38.154% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="673a85bd934ace2b" memberName="textButton8"
              virtualName="" explicitFocusOrder="0" pos="44.383% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="51da563dfb5e7f1f" memberName="textButton9"
              virtualName="" explicitFocusOrder="0" pos="50.389% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d732e0ca37fcefa3" memberName="textButton10"
              virtualName="" explicitFocusOrder="0" pos="56.285% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c429679b54706ebc" memberName="textButton11"
              virtualName="" explicitFocusOrder="0" pos="62.291% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="67da6ad4a475ea87" memberName="textButton12"
              virtualName="" explicitFocusOrder="0" pos="68.298% 15.033% 5.006% 69.935%"
              buttonText="" connectedEdges="0" needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6d633308bb2f826b" memberName="textButton13"
              virtualName="" explicitFocusOrder="0" pos="74.194% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="475affff2271888d" memberName="textButton14"
              virtualName="" explicitFocusOrder="0" pos="80.423% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="70e9dfb84659a688" memberName="textButton15"
              virtualName="" explicitFocusOrder="0" pos="86.429% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ac771b12be7195d" memberName="textButton16"
              virtualName="" explicitFocusOrder="0" pos="92.325% 15.033% 5.006% 69.935%"
              bgColOff="ff0b906a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

