/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class CircularBufferAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    CircularBufferAudioProcessorEditor (CircularBufferAudioProcessor&);
    ~CircularBufferAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    CircularBufferAudioProcessor& audioProcessor;
    juce::Slider delaySlider;
    juce::Slider feedbackSlider;
    
    juce::Label delayLabel;
    juce::Label feedbackLabel;
    
public:
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> delaySliderValue;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> feedbackSliderValue;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CircularBufferAudioProcessorEditor)
};
