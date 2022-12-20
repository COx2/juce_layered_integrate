cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

project(JUCE-LAYERED-INTEGRATE VERSION 0.0.1)

if(MSVC)
    # static linking in Windows
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

# Adds all the module sources so they appear correctly in the IDE
set_property(GLOBAL PROPERTY USE_FOLDERS YES)
option(JUCE_ENABLE_MODULE_SOURCE_GROUPS "Enable Module Source Groups" ON)

# Add JUCE Package
add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/External/JUCE)

# Add static library target
add_library(Core STATIC)

_juce_initialise_target(Core)
_juce_set_output_name(Core $<TARGET_PROPERTY:Core,JUCE_PRODUCT_NAME>)

target_link_libraries(Core
    PUBLIC
        juce::juce_analytics
        juce::juce_audio_basics
        juce::juce_audio_devices
        juce::juce_audio_formats
        juce::juce_audio_plugin_client
        juce::juce_audio_processors
        juce::juce_audio_utils
        juce::juce_box2d
        juce::juce_core
        juce::juce_cryptography
        juce::juce_data_structures
        juce::juce_dsp
        juce::juce_events
        juce::juce_graphics
        juce::juce_gui_basics
        juce::juce_gui_extra
        juce::juce_opengl
        juce::juce_osc
        juce::juce_product_unlocking
        juce::juce_video
)

target_sources(Core
    PRIVATE
        "Core/Source/Core.cpp"
)

# Add application target
add_executable(App)

target_sources(App
    PRIVATE
        "App/Source/Main.cpp"
)

target_include_directories(App
    PRIVATE
        "Core/Source"
)

target_link_libraries(App
    PRIVATE
        Core
)

# Add another application target
add_executable(App2)

target_sources(App2
    PRIVATE
        "App2/Source/Main.cpp"
)

target_include_directories(App2
    PRIVATE
        "Core/Source"
)

target_link_libraries(App2
    PRIVATE
        Core
)