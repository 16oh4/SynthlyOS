//
// Created by synthly on 10/4/19.
//

#ifndef SYNTHLYOS_APPHEADER_H
#define SYNTHLYOS_APPHEADER_H


class AppHeader : public Component
{
public:
    AppHeader()
    {
        //appName.setButtonText(name);
        //addAndMakeVisible(appName, 0);

        initLabels();

    }
    void paint(Graphics& g) override
    {
        //the background of the header
        g.fillAll(Colours::ghostwhite);

    }
    void resized() override
    {
        auto area = getLocalBounds();

        //Establish constants
        auto appNameWidth = getWidth()/6;
        auto appNameHeight = getHeight();
        auto appNameMargin = getHeight()/10;

        //Add the Home Title button at the far left
        appLabel.setBounds(area.removeFromLeft(appNameWidth).reduced(appNameMargin));
    }

    void setAppLabel(const String& name)
    {
        appLabel.setText(name, NotificationType::dontSendNotification);
    }


private:
    //VARIABLES
    Label appLabel;

    const String appName = "Footer";

    void initLabels()
    {
        //add current app name
        appLabel.setText("HOME", dontSendNotification);
        appLabel.setJustificationType(Justification::centredLeft);
        addAndMakeVisible(appLabel, 0);

    }
};





#endif //SYNTHLYOS_APPHEADER_H