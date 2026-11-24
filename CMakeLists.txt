cmake_minimum_required(VERSION 3.22)
project(IsoCam LANGUAGES CXX)

# SDK integration intentionally pending.
# Add the official Preloader Android SDK using its documented CMake setup
# only after confirming the exact supported SDK tag/API for this launcher build.

add_library(IsoCam SHARED src/main.cpp)
target_include_directories(IsoCam PRIVATE include)
target_compile_features(IsoCam PRIVATE cxx_std_17)
target_compile_options(IsoCam PRIVATE -Wall -Wextra)
