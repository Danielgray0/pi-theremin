/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"
#include <math.h>


//==============================================================================
Gray_compressorAudioProcessor::Gray_compressorAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
    addParameter(threshold = new AudioParameterFloat ("threshold", "Threshold", 0.0f, 1.0f,0.5f));
    addParameter(alpha = new AudioParameterFloat ("alpha", "Alpha", 0.0f, 1.0f, 0.8f));
    addParameter(attack = new AudioParameterFloat ("attack", "Attack", 0.0f, 1.0f, 0.0f));
    addParameter(release = new AudioParameterFloat ("release", "Release", 0.0f, 1.0f, 0.5f));
    addParameter(ratio = new AudioParameterFloat ("ratio", "Ratio", 1.0f, 100.0f, 1.0f));
}

Gray_compressorAudioProcessor::~Gray_compressorAudioProcessor()
{
}

//==============================================================================
const String Gray_compressorAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool Gray_compressorAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Gray_compressorAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool Gray_compressorAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double Gray_compressorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int Gray_compressorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Gray_compressorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void Gray_compressorAudioProcessor::setCurrentProgram (int index)
{
}

const String Gray_compressorAudioProcessor::getProgramName (int index)
{
    return {};
}

void Gray_compressorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Gray_compressorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    if (Fs != sampleRate) {
        Fs = sampleRate;
    }
    
}

void Gray_compressorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool Gray_compressorAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void Gray_compressorAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    float AlphaA = exp(-log(9)/(Fs * *attack));
    float AlphaR = exp(-log(-9)/(Fs * *release));

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        for (int n = 0; n < buffer.getNumSamples(); ++n) {
            
            drySample = buffer.getReadPointer(channel)[n];
            
            float xLog = fabs(drySample);
            float x_dB = 20*log10(xLog/1);
            
            if (x_dB < -96) {
                x_dB = -96;
            }
            
            if (x_dB > *threshold) {
                gain = *threshold + (x_dB - *threshold) / *ratio;
            }
            else {
                gain = x_dB;
            }
            
            gainChange = gain - x_dB;
            
            if (gainChange < gainSmoothPrev) {
                gainSmooth = ((1 - AlphaA) * gainChange) + (AlphaA * gainSmoothPrev);
            }
            else {
                gainSmooth = ((1 - AlphaR) * gainChange) + (AlphaR * gainSmoothPrev);
            }
            
            linOut = pow(10,(gainSmooth/20));
            
            output = linOut * drySample;
            
            buffer.getWritePointer(channel)[n] = output;
            
            
        }
        // ..do something to the data...
       
    }
}

//==============================================================================
bool Gray_compressorAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* Gray_compressorAudioProcessor::createEditor()
{
    return new Gray_compressorAudioProcessorEditor (*this);
}

//==============================================================================
void Gray_compressorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void Gray_compressorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Gray_compressorAudioProcessor();
}
