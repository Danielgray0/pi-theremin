/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
Gray_compressorAudioProcessorEditor::Gray_compressorAudioProcessorEditor (Gray_compressorAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    addAndMakeVisible (threshKnob);
    threshKnob.setRange (-48.0f, 12.0f, 1.0f);
    threshKnob.setSliderStyle (Slider::Rotary);
    threshKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    threshKnob.setTextValueSuffix(" dB");
    threshKnob.addListener (this);
    threshKnob.setBounds (40, 400, 100, 100);

    addAndMakeVisible(threshLabel);
    threshLabel.setText("Threshold", dontSendNotification);
    threshLabel.attachToComponent(&threshKnob, false);
    threshLabel.setBounds(55, 360, 100, 50);

    addAndMakeVisible (ratioKnob);
    ratioKnob.setRange (0.0f, 10.0f, 0.1f);
    ratioKnob.setValue(3.0f);
    ratioKnob.setSliderStyle (Slider::Rotary);
    ratioKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    ratioKnob.setTextValueSuffix(":1");
    ratioKnob.addListener (this);
    ratioKnob.setBounds (168, 400, 100, 100);
    
    addAndMakeVisible(ratioLabel);
    ratioLabel.setText("Ratio", dontSendNotification);
    ratioLabel.attachToComponent(&ratioKnob, false);
    ratioLabel.setBounds(195, 360, 100, 50);

    addAndMakeVisible (attackKnob);
    attackKnob.setRange (0.10f, 1.0f, 0.01f);
    attackKnob.setSliderStyle (Slider::Rotary);
    attackKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    attackKnob.setTextValueSuffix(" s");
    attackKnob.addListener (this);
    attackKnob.setBounds (296, 400, 100, 100);
    
    addAndMakeVisible(attackLabel);
    attackLabel.setText("Attack", dontSendNotification);
    attackLabel.attachToComponent(&attackKnob, false);
    attackLabel.setBounds(320, 360, 100, 50);

    addAndMakeVisible (releaseKnob);
    releaseKnob.setRange (0.1f, 10.0f, 0.01f);
    releaseKnob.setSliderStyle (Slider::Rotary);
    releaseKnob.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    releaseKnob.setTextValueSuffix(" s");
    releaseKnob.addListener (this);
    releaseKnob.setBounds (424, 400, 100, 100);
    
    addAndMakeVisible(releaseLabel);
    releaseLabel.setText("Release", dontSendNotification);
    releaseLabel.attachToComponent(&releaseKnob, false);
    releaseLabel.setBounds(445, 360, 100, 50);

    addAndMakeVisible (gainReduction);
    gainReduction.setRange (-96.0f, 12.0f, 5.0f);
    gainReduction.setSliderStyle (Slider::LinearVertical);
    gainReduction.setTextBoxStyle (Slider::TextBoxBelow, false, 80, 20);
    gainReduction.setTextValueSuffix("dB");
    gainReduction.addListener (this);
    gainReduction.setBounds (16, 64, 50, 300);

    addAndMakeVisible (label);
    label.setFont (Font (45.00f, Font::plain).withTypefaceStyle ("Regular"));
    label.setJustificationType (Justification::centred);
    label.setEditable (false, false, false);
    label.setColour (Label::textColourId, Colour (0xffdee5ee));
    label.setColour (TextEditor::textColourId, Colours::black);
    label.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label.setBounds (178, 12, 225, 63);
    
    
    setSize (600, 600);
    
    
    
}

Gray_compressorAudioProcessorEditor::~Gray_compressorAudioProcessorEditor()
{
}

//==============================================================================
void Gray_compressorAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);
}

void Gray_compressorAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
}
void Gray_compressorAudioProcessorEditor::sliderValueChanged (Slider* sliderThatWasMoved)
{
    
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]
    
    if (sliderThatWasMoved == &threshKnob)
    {
        *processor.threshold = pow( 10.0f, threshKnob.getValue()/20.0f);
    }
    else if (sliderThatWasMoved == &ratioKnob)
    {
        *processor.ratio = sliderThatWasMoved -> getValue();
    }
    else if (sliderThatWasMoved == &attackKnob)
    {
        *processor.attack = sliderThatWasMoved -> getValue();
    }
    else if (sliderThatWasMoved == &releaseKnob)
    {
        *processor.release = sliderThatWasMoved -> getValue();
    }
    
    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]

}
