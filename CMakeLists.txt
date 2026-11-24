
cmake_minimum_required(VERSION 3.22)
project(IsoCam LANGUAGES CXX)

include(FetchContent)

FetchContent_Declare(
    preloader_android
    GIT_REPOSITORY https://github.com/LiteLDev/preloader-android.git
    GIT_TAG main
)

FetchContent_MakeAvailable(preloader_android)

add_library(IsoCam SHARED
    src/main.cpp
)

target_include_directories(IsoCam PRIVATE include)

target_compile_features(IsoCam PRIVATE cxx_std_20)

target_compile_options(IsoCam PRIVATE
    -Wall
    -Wextra
)

find_library(ANDROID_LOG_LIB log REQUIRED)

target_link_libraries(IsoCam PRIVATE
    preloader
    ${ANDROID_LOG_LIB}
)
