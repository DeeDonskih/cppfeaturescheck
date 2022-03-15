cmake_minimum_required(VERSION 3.18)

project(cppfeaturecheck VERSION 0.1 LANGUAGES C CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

# ==========================================================================
# Project options

if(MACOS)
    option(MAKE_OSX_BUNDLE "Make macos bundle" OFF)
endif()

# ==========================================================================
# Set folders aliases (temporary)

# ==========================================================================
# Define resources

# Find sources in project directories recursive with wildcards 

# ==========================================================================
# Main sources
if(MAKE_OSX_BUNDLE)
    add_executable(
                    cppfeaturecheck
                    ${MACOSX_BUNDLE}
                    featurescheck.cpp
                    cppfeatures.hpp
                   )
else()
    add_executable(
                    cppfeaturecheck
                    featurescheck.cpp
                    cppfeatures.hpp
                   )
endif()

# Main include directories


# ==========================================================================
# Add compile feature set
target_compile_features(cppfeaturecheck PUBLIC cxx_std_20)


# Main compiler options
#target_compile_options(cppfeaturecheck PRIVATE -fno-rtti)

# Main linker options (creates compile symbols map for analysis)
if(CLANG)
    target_link_options(cppfeaturecheck PRIVATE -Wl,-map,output.map)
elseif(GNU)
    target_link_options(cppfeaturecheck PRIVATE -Wl,-Map,output.map)
endif()

# OSX shit
if(XTZ_MAKE_OSX_BUNDLE)
set_target_properties(
    cppfeaturecheck PROPERTIES
    MACOSX_BUNDLE   true
    MACOSX_BUNDLE_GUI_IDENTIFIER my.cxxcheck.com
    XCODE_ATTRIBUTE_MACOSX_DEPLOYMENT_TARGET 10.12
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
)
endif()
