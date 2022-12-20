#include <iostream>
#include <juce_core/juce_core.h>
#include <juce_audio_devices/juce_audio_devices.h>
#include <Core.h>

int main()
{
    std::cout << "This is App2" << std::endl;

    juce::String juce_string("JUCE String");
    std::cout << juce_string.toStdString() << std::endl;

    std::cout << getTextFromCore() << std::endl;

    return 0;
}