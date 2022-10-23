/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
CircularBufferAudioProcessorEditor::CircularBufferAudioProcessorEditor (CircularBufferAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    delaySliderValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, DELAY_ID, delaySlider);
    feedbackSliderValue = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, FEEDBACK_ID, feedbackSlider);
    
    setSize (400, 400);
    
    addAndMakeVisible(delaySlider);
    delaySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    delaySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    delaySlider.setRange(1, 5000);
    delaySlider.setValue(1000);
    delaySlider.setTextValueSuffix("ms");
    delaySlider.setSkewFactorFromMidPoint(500);
    
    addAndMakeVisible(delayLabel);
    delayLabel.setText(DELAY_NAME, juce::dontSendNotification);
    delayLabel.attachToComponent(&delaySlider, false);
    
    addAndMakeVisible(feedbackSlider);
    feedbackSlider.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    feedbackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, true, 100, 25);
    feedbackSlider.setRange(0.f, 0.99f);
    feedbackSlider.setValue(0.3f);

    addAndMakeVisible(feedbackLabel);
    feedbackLabel.setText(FEEDBACK_NAME, juce::dontSendNotification);
    feedbackLabel.attachToComponent(&feedbackSlider, false);
}

CircularBufferAudioProcessorEditor::~CircularBufferAudioProcessorEditor()
{
}

//==============================================================================
void CircularBufferAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));
}

void CircularBufferAudioProcessorEditor::resized()
{
    auto bounds = getLocalBounds();
    bounds.removeFromTop(25);
    
    auto delayArea = bounds.removeFromLeft(bounds.getWidth() * 0.5);
    //auto feedbackArea = bounds.removeFromRight(bounds.getWidth() * 0.5);
    
    delaySlider.setBounds(delayArea);
    feedbackSlider.setBounds(bounds);
}
