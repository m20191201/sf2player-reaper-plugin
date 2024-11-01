#include "PluginProcessor.h"
#include "PluginEditor.h"

class Sf2PlayerAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    Sf2PlayerAudioProcessorEditor(Sf2PlayerAudioProcessor& p)
        : AudioProcessorEditor(&p), processor(p)
    {
        openFileButton.setButtonText("Open SF2 File");
        openFileButton.onClick = [this]() { openFile(); };
        addAndMakeVisible(openFileButton);
        setSize(400, 200);
    }

    void openFile()
    {
        juce::FileChooser chooser("Select a SoundFont file...", juce::File(), "*.sf2");
        if (chooser.browseForFileToOpen())
        {
            juce::File sf2File = chooser.getResult();
            processor.loadSoundFont(sf2File);
        }
    }

    void resized() override
    {
        openFileButton.setBounds(10, 10, getWidth() - 20, 30);
    }

private:
    Sf2PlayerAudioProcessor& processor;
    juce::TextButton openFileButton;
};
