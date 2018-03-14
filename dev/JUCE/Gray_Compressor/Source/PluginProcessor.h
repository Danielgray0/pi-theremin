/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
*/
class Gray_compressorAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    Gray_compressorAudioProcessor();
    ~Gray_compressorAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;

   #ifndef JucePlugin_PreferredChannelConfigurations
    bool isBusesLayoutSupported (const BusesLayout& layouts) const override;
   #endif

    void processBlock (AudioBuffer<float>&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool isMidiEffect() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;
    
    
    AudioParameterFloat* threshold;
    AudioParameterFloat* alpha;
    AudioParameterFloat* attack;
    AudioParameterFloat* release;
    AudioParameterFloat* ratio;
    
    float Fs;
    float linOut;
    float output;

private:
    //==============================================================================
    
    int sampleCountDown;
    float AlphaA;
    float AlphaR;
    float gainSmoothPrev;
    float gain;
    float gainChange;
    float gainSmooth;
    float drySample;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (Gray_compressorAudioProcessor)
};
