/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class Gray_compressorAudioProcessorEditor  : public AudioProcessorEditor,
                                             public Slider::Listener
{
public:
    Gray_compressorAudioProcessorEditor (Gray_compressorAudioProcessor&);
    ~Gray_compressorAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    Gray_compressorAudioProcessor& processor;
    
   Slider threshKnob;
   Slider ratioKnob;
   Slider attackKnob;
   Slider releaseKnob;
   Slider gainReduction;
   Label label;
   Label threshLabel;
   Label ratioLabel;
   Label attackLabel;
   Label releaseLabel;
   Label gainReductionLabel;
    
    
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gray_compressorAudioProcessorEditor)
};
