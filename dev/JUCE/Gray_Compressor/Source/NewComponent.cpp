/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.2.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "NewComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
NewComponent::NewComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (threshKnob = new Slider ("thresh"));
    threshKnob->setRange (0, 10, 0);
    threshKnob->setSliderStyle (Slider::Rotary);
    threshKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    threshKnob->addListener (this);

    threshKnob->setBounds (40, 376, 100, 100);

    addAndMakeVisible (ratioKnob = new Slider ("ratio"));
    ratioKnob->setRange (0, 10, 0);
    ratioKnob->setSliderStyle (Slider::Rotary);
    ratioKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    ratioKnob->addListener (this);

    ratioKnob->setBounds (168, 376, 100, 100);

    addAndMakeVisible (attackKnob = new Slider ("attack"));
    attackKnob->setRange (0, 10, 0);
    attackKnob->setSliderStyle (Slider::Rotary);
    attackKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackKnob->addListener (this);

    attackKnob->setBounds (296, 376, 100, 100);

    addAndMakeVisible (releaseKnob = new Slider ("release"));
    releaseKnob->setRange (0, 10, 0);
    releaseKnob->setSliderStyle (Slider::Rotary);
    releaseKnob->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseKnob->addListener (this);

    releaseKnob->setBounds (424, 376, 100, 100);

    addAndMakeVisible (gainReduction = new Slider ("gainReduction"));
    gainReduction->setRange (-96, 12, 5);
    gainReduction->setSliderStyle (Slider::LinearVertical);
    gainReduction->setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainReduction->addListener (this);

    gainReduction->setBounds (16, 64, 50, 300);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Compressor")));
    label->setFont (Font (45.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (Label::textColourId, Colour (0xffdee5ee));
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (178, 12, 225, 63);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("label text")));
    label2->setFont (Font (20.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2->setBounds (193, 216, 150, 24);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

NewComponent::~NewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    threshKnob = nullptr;
    ratioKnob = nullptr;
    attackKnob = nullptr;
    releaseKnob = nullptr;
    gainReduction = nullptr;
    label = nullptr;
    label2 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void NewComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff343941));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void NewComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void NewComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == threshKnob)
    {
        //[UserSliderCode_threshKnob] -- add your slider handling code here..
        //[/UserSliderCode_threshKnob]
    }
    else if (sliderThatWasMoved == ratioKnob)
    {
        //[UserSliderCode_ratioKnob] -- add your slider handling code here..
        //[/UserSliderCode_ratioKnob]
    }
    else if (sliderThatWasMoved == attackKnob)
    {
        //[UserSliderCode_attackKnob] -- add your slider handling code here..
        //[/UserSliderCode_attackKnob]
    }
    else if (sliderThatWasMoved == releaseKnob)
    {
        //[UserSliderCode_releaseKnob] -- add your slider handling code here..
        //[/UserSliderCode_releaseKnob]
    }
    else if (sliderThatWasMoved == gainReduction)
    {
        //[UserSliderCode_gainReduction] -- add your slider handling code here..
        //[/UserSliderCode_gainReduction]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="NewComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ff343941"/>
  <SLIDER name="thresh" id="d0ef40364add3a3a" memberName="threshKnob" virtualName=""
          explicitFocusOrder="0" pos="40 376 100 100" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="ratio" id="2fb5131b06adf40f" memberName="ratioKnob" virtualName=""
          explicitFocusOrder="0" pos="168 376 100 100" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="attack" id="fdc701d6910d601b" memberName="attackKnob" virtualName=""
          explicitFocusOrder="0" pos="296 376 100 100" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="release" id="6428e34b59854bcd" memberName="releaseKnob"
          virtualName="" explicitFocusOrder="0" pos="424 376 100 100" min="0.00000000000000000000"
          max="10.00000000000000000000" int="0.00000000000000000000" style="Rotary"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <SLIDER name="gainReduction" id="70a1482d80c315a2" memberName="gainReduction"
          virtualName="" explicitFocusOrder="0" pos="16 64 50 300" min="-96.00000000000000000000"
          max="12.00000000000000000000" int="5.00000000000000000000" style="LinearVertical"
          textBoxPos="TextBoxBelow" textBoxEditable="1" textBoxWidth="80"
          textBoxHeight="20" skewFactor="1.00000000000000000000" needsCallback="1"/>
  <LABEL name="new label" id="c32d490dd7e68c48" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="178 12 225 63" textCol="ffdee5ee"
         edTextCol="ff000000" edBkgCol="0" labelText="Compressor" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="45.00000000000000000000" kerning="0.00000000000000000000"
         bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="537ae1d4824ebbab" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="193 216 150 24" edTextCol="ff000000"
         edBkgCol="0" labelText="label text" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="20.00000000000000000000"
         kerning="0.00000000000000000000" bold="0" italic="0" justification="33"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
