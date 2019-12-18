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

#include "StepLights.h"

#include <memory>


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
StepLights::StepLights ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    textButton = std::make_unique<TextButton> ("new button");
    addAndMakeVisible (textButton.get());
    textButton->setButtonText (String());
    textButton->addListener (this);
    textButton->setColour (TextButton::buttonColourId, Colour (0xff704a4a));
    textButton->setColour (TextButton::buttonOnColourId, Colours::yellow);

    textButton2.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton2.get());
    textButton2->setButtonText (String());
    textButton2->addListener (this);
    textButton2->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton3.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton3.get());
    textButton3->setButtonText (String());
    textButton3->addListener (this);
    textButton3->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton4.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton4.get());
    textButton4->setButtonText (String());
    textButton4->addListener (this);
    textButton4->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton5.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton5.get());
    textButton5->setButtonText (String());
    textButton5->addListener (this);
    textButton5->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton6.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton6.get());
    textButton6->setButtonText (String());
    textButton6->addListener (this);
    textButton6->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton7.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton7.get());
    textButton7->setButtonText (String());
    textButton7->addListener (this);
    textButton7->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton8.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton8.get());
    textButton8->setButtonText (String());
    textButton8->addListener (this);
    textButton8->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton9.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton9.get());
    textButton9->setButtonText (String());
    textButton9->addListener (this);
    textButton9->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton10.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton10.get());
    textButton10->setButtonText (String());
    textButton10->addListener (this);
    textButton10->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton11.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton11.get());
    textButton11->setButtonText (String());
    textButton11->addListener (this);
    textButton11->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton12.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton12.get());
    textButton12->setButtonText (String());
    textButton12->addListener (this);
    textButton12->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton13.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton13.get());
    textButton13->setButtonText (String());
    textButton13->addListener (this);
    textButton13->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton14.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton14.get());
    textButton14->setButtonText (String());
    textButton14->addListener (this);
    textButton14->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton15.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton15.get());
    textButton15->setButtonText (String());
    textButton15->addListener (this);
    textButton15->setColour (TextButton::buttonColourId, Colour (0xff704a4a));

    textButton16.reset (new TextButton ("new button"));
    addAndMakeVisible (textButton16.get());
    textButton16->setButtonText (String());
    textButton16->addListener (this);
    textButton16->setColour (TextButton::buttonColourId, Colour (0xff704a4a));


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 10);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

StepLights::~StepLights()
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
void StepLights::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void StepLights::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    textButton->setBounds (proportionOfWidth (0.0256f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton2->setBounds (proportionOfWidth (0.0856f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton3->setBounds (proportionOfWidth (0.1457f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton4->setBounds (proportionOfWidth (0.2058f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton5->setBounds (proportionOfWidth (0.2659f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton6->setBounds (proportionOfWidth (0.3259f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton7->setBounds (proportionOfWidth (0.3860f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton8->setBounds (proportionOfWidth (0.4460f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton9->setBounds (proportionOfWidth (0.5061f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton10->setBounds (proportionOfWidth (0.5651f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton11->setBounds (proportionOfWidth (0.6251f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton12->setBounds (proportionOfWidth (0.6852f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton13->setBounds (proportionOfWidth (0.7453f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton14->setBounds (proportionOfWidth (0.8053f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton15->setBounds (proportionOfWidth (0.8654f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    textButton16->setBounds (proportionOfWidth (0.9255f), proportionOfHeight (0.2500f), proportionOfWidth (0.0501f), proportionOfHeight (0.5000f));
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void StepLights::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == textButton.get())
    {
        //[UserButtonCode_textButton] -- add your button handler code here..
        //[/UserButtonCode_textButton]
    }
    else if (buttonThatWasClicked == textButton2.get())
    {
        //[UserButtonCode_textButton2] -- add your button handler code here..
        //[/UserButtonCode_textButton2]
    }
    else if (buttonThatWasClicked == textButton3.get())
    {
        //[UserButtonCode_textButton3] -- add your button handler code here..
        //[/UserButtonCode_textButton3]
    }
    else if (buttonThatWasClicked == textButton4.get())
    {
        //[UserButtonCode_textButton4] -- add your button handler code here..
        //[/UserButtonCode_textButton4]
    }
    else if (buttonThatWasClicked == textButton5.get())
    {
        //[UserButtonCode_textButton5] -- add your button handler code here..
        //[/UserButtonCode_textButton5]
    }
    else if (buttonThatWasClicked == textButton6.get())
    {
        //[UserButtonCode_textButton6] -- add your button handler code here..
        //[/UserButtonCode_textButton6]
    }
    else if (buttonThatWasClicked == textButton7.get())
    {
        //[UserButtonCode_textButton7] -- add your button handler code here..
        //[/UserButtonCode_textButton7]
    }
    else if (buttonThatWasClicked == textButton8.get())
    {
        //[UserButtonCode_textButton8] -- add your button handler code here..
        //[/UserButtonCode_textButton8]
    }
    else if (buttonThatWasClicked == textButton9.get())
    {
        //[UserButtonCode_textButton9] -- add your button handler code here..
        //[/UserButtonCode_textButton9]
    }
    else if (buttonThatWasClicked == textButton10.get())
    {
        //[UserButtonCode_textButton10] -- add your button handler code here..
        //[/UserButtonCode_textButton10]
    }
    else if (buttonThatWasClicked == textButton11.get())
    {
        //[UserButtonCode_textButton11] -- add your button handler code here..
        //[/UserButtonCode_textButton11]
    }
    else if (buttonThatWasClicked == textButton12.get())
    {
        //[UserButtonCode_textButton12] -- add your button handler code here..
        //[/UserButtonCode_textButton12]
    }
    else if (buttonThatWasClicked == textButton13.get())
    {
        //[UserButtonCode_textButton13] -- add your button handler code here..
        //[/UserButtonCode_textButton13]
    }
    else if (buttonThatWasClicked == textButton14.get())
    {
        //[UserButtonCode_textButton14] -- add your button handler code here..
        //[/UserButtonCode_textButton14]
    }
    else if (buttonThatWasClicked == textButton15.get())
    {
        //[UserButtonCode_textButton15] -- add your button handler code here..
        //[/UserButtonCode_textButton15]
    }
    else if (buttonThatWasClicked == textButton16.get())
    {
        //[UserButtonCode_textButton16] -- add your button handler code here..
        //[/UserButtonCode_textButton16]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="StepLights" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="10">
  <BACKGROUND backgroundColour="ffffffff"/>
  <TEXTBUTTON name="new button" id="694e1983ac89470c" memberName="textButton"
              virtualName="" explicitFocusOrder="0" pos="2.558% 25% 5.006% 50%"
              bgColOff="ff704a4a" bgColOn="ffffff00" buttonText="" connectedEdges="0"
              needsCallback="1" radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="7326b87f67a6699f" memberName="textButton2"
              virtualName="" explicitFocusOrder="0" pos="8.565% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="9d9133f5236ca30e" memberName="textButton3"
              virtualName="" explicitFocusOrder="0" pos="14.572% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="a7c2a0cfae67e1a1" memberName="textButton4"
              virtualName="" explicitFocusOrder="0" pos="20.578% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d603b44410e603fd" memberName="textButton5"
              virtualName="" explicitFocusOrder="0" pos="26.585% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="12885613e4a0820f" memberName="textButton6"
              virtualName="" explicitFocusOrder="0" pos="32.592% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="71b5c0bb433595e7" memberName="textButton7"
              virtualName="" explicitFocusOrder="0" pos="38.598% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="673a85bd934ace2b" memberName="textButton8"
              virtualName="" explicitFocusOrder="0" pos="44.605% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="51da563dfb5e7f1f" memberName="textButton9"
              virtualName="" explicitFocusOrder="0" pos="50.612% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="d732e0ca37fcefa3" memberName="textButton10"
              virtualName="" explicitFocusOrder="0" pos="56.507% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="c429679b54706ebc" memberName="textButton11"
              virtualName="" explicitFocusOrder="0" pos="62.514% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="67da6ad4a475ea87" memberName="textButton12"
              virtualName="" explicitFocusOrder="0" pos="68.521% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="6d633308bb2f826b" memberName="textButton13"
              virtualName="" explicitFocusOrder="0" pos="74.527% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="475affff2271888d" memberName="textButton14"
              virtualName="" explicitFocusOrder="0" pos="80.534% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="70e9dfb84659a688" memberName="textButton15"
              virtualName="" explicitFocusOrder="0" pos="86.541% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <TEXTBUTTON name="new button" id="ac771b12be7195d" memberName="textButton16"
              virtualName="" explicitFocusOrder="0" pos="92.547% 25% 5.006% 50%"
              bgColOff="ff704a4a" buttonText="" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

