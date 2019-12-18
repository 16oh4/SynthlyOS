
#pragma once //only compile this file once!
#include <list>
#include "Mixer.h"

#include "Palette.h"
#include "Homescreen.h"
#include "AppHeader.h"
#include "AppFooter.h"
//#include "MIDI.h"


//==============================================================================
class MainContentComponent  :   public AudioAppComponent
{
public:

    MainContentComponent()
    {
        initOS();
        initListeners();

        setSize(1024,600);
        setAudioChannels(0,2);
    }

    ~MainContentComponent() override
    {
        shutdownAudio();
    }

    void resized() override
    {
        //CONSTANTS
        auto area = getLocalBounds();
        auto headerHeight = getHeight()/16;
        auto footerHeight = getHeight()/12;

        //SET HEADER AND FOOTER
        header.setBounds(area.removeFromTop(headerHeight));
        footer.setBounds(area.removeFromBottom(footerHeight));

        //SET APPS
        auto appArea = area;
        auto appHeight = area.getHeight();
        auto appWidth = area.getWidth();

        home.setBounds(appArea);
        mixer.setBounds(appArea);
        //pattern2.setBounds(appArea);
        //midi.setBounds(area);

    }

    void paint(Graphics& g) override
    {
        g.fillAll(Colours::white);
    }

    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override
    {
        Logger::outputDebugString("Prepare to Play for MAIN");
        mixer.prepareToPlay(samplesPerBlockExpected, sampleRate);
        //pattern2.prepareToPlay(samplesPerBlockExpected, sampleRate);
    }

    void getNextAudioBlock (const AudioSourceChannelInfo& bufferToFill) override
    {
        mixer.getNextAudioBlock(bufferToFill);
        //pattern2.getNextAudioBlock(bufferToFill);
    }

    void releaseResources() override {}



private:
    //Tools
    Palette     palette;

    //Child components
    AppHeader   header;
    AppFooter   footer;
    Homescreen  home;
    Mixer     mixer;
    //Pattern     pattern2;


    //MIDI midi;

    void initOS()
    {
        setLookAndFeel(&palette);

        //SET HOME HEADER AND FOOTER BEHIND EVERYTHING
        addAndMakeVisible(header,0);
        addAndMakeVisible(footer,0);
        addAndMakeVisible(home, 0);

        //SETUP APPS IN FRONT OF EVERYTHING
        addChildComponent(mixer, 1);
        //addChildComponent(mixer2, 1);
        //addChildComponent(midi, 1);

    }


    void initListeners()
    {
        footer.cubeButton.onClick = [this]
        {
            cubeOnClick();
        };

        home.patternButton.onClick = [this]
        {
            mixerOnClick();
        };

        home.midiButton.onClick = [this]
        {
            midiOnClick();
        };

    }

    void cubeOnClick()
    {
        Logger::outputDebugString("HOME BUTTON CLICKED");
        header.setAppLabel("HOME");

        //arrangeVisibility(home);

        home.setVisible(true);
        //midi.setVisible(false);
        mixer.setVisible(false);
        //mixer2.setVisible(false);
    }

    void mixerOnClick()
    {

        Logger::outputDebugString("PATTERN CLICKED");
        header.setAppLabel("PATTERN");

        //arrangeVisibility(pattern);

        mixer.setVisible(true);
        //mixer2.setVisible(true);
        //midi.setVisible(false);
        home.setVisible(false);

    }

    void midiOnClick()
    {
        Logger::outputDebugString("MIDI CLICKED");
        header.setAppLabel("MIDI");

        //midi.setVisible(true);
        mixer.setVisible(false);
        home.setVisible(false);
    }

    //This method rearranges the visibility of the current application with
    //Respect to the rest of the components
    //pass in const reference to prevent copying and modifying
    void arrangeVisibility(const Component& clicked)
    {
        /*
        //USING LIST FOR SEARCH RATHER THAN CASTING
        //std::list<Component>::iterator
        AppList::iterator it = find(synthlyApps.begin(), synthlyApps.end(), clicked);

        synthlyApps.erase(it); //erase the app from the list since were running it now

        //Now, set the visibility to false for everything else!
        //for(auto i = synthlyApps.begin(); i != synthlyApps.end(); i++)
        for(auto & synthlyApp : synthlyApps)
        {
            (synthlyApp).setVisible(false);
        }
        */

        //DYNAMIC CAST WITH POINTER
        if(dynamic_cast<const Homescreen*> (&clicked) != nullptr)
        {
            Logger::outputDebugString("HOMESCREEN IS OBJECT!");

            mixer.setVisible(false);

        }

        if(dynamic_cast<const Mixer*> (&clicked) != nullptr)
        {
            Logger::outputDebugString("PATTERN IS OBJECT!");

            //HIDE EVERY OTHER APP
            home.setVisible(false);
        }

        /*
        //DYNAMIC CAST WITH REFERENCE
        try {
            auto& G = dynamic_cast<const Homescreen&> (clicked);
        }
        catch (const std::bad_cast& e)
        {
            Logger::outputDebugString("Failed home cast");
            Logger::outputDebugString(e.what());
        }
        catch (...){

        }
        */
    }


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainContentComponent)
};