# Copyright (C) 2023 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

cmake_minimum_required(VERSION 3.15)

set(PROJECT_NAME juce-qt-template)
project(${PROJECT_NAME} VERSION 0.0.1)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(libs/juce)

find_package(Qt6
    REQUIRED COMPONENTS Core Gui
    OPTIONAL_COMPONENTS Quick
)

qt_standard_project_setup()

juce_add_plugin(${PROJECT_NAME}
    PLUGIN_MANUFACTURER_CODE TQtC
    COMPANY_NAME "Miller Labs DSP"
    PRODUCT_NAME "juce-qt-template"
    PLUGIN_CODE MLDSP
    BUNDLE_ID "io.qt.juce-qt-template"
    FORMATS AU VST3 Standalone
    COPY_PLUGIN_AFTER_BUILD TRUE
)

target_sources(${PROJECT_NAME}
    PRIVATE
        PluginProcessor.cpp
        PluginEditor.cpp
        QtComponent.cpp
)

target_compile_definitions(${PROJECT_NAME}
    PUBLIC
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0
)

target_link_libraries(${PROJECT_NAME}
    PRIVATE
        juce::juce_audio_utils
        Qt6::Core
        Qt6::Gui
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags
)

# Ease up on juce_recommended_warning_flags a bit
target_compile_options(juce_recommended_warning_flags INTERFACE
    -Wno-gnu-zero-variadic-macro-arguments
    -Wno-switch-enum
    -Wno-missing-prototypes
)

if(TARGET Qt6::Quick)
    qt_add_resources(${PROJECT_NAME} "qml" FILES main.qml)
    qt_import_qml_plugins(${PROJECT_NAME})
    target_link_libraries(${PROJECT_NAME} PRIVATE Qt6::Quick)
endif()