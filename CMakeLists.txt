cmake_minimum_required(VERSION 3.16)
project(TerrariaClone LANGUAGES CXX)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
# set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD "a9e1cf81-9932-4810-974b-6eccaf14e457")
# set(CMAKE_CXX_MODULE_STD 1)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)
include_directories(${PROJECT_SOURCE_DIR}/include/designpatterns)

# Find SDL3 installed system-wide
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_ttf REQUIRED)
#find_package(SDL3_image REQUIRED)
find_package(Catch2 3 REQUIRED)

# Collect all source files
file(GLOB_RECURSE GAME_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cc")
list(FILTER GAME_SOURCES EXCLUDE REGEX ".*/main\\.cc$")

add_library(TerrariaCore ${GAME_SOURCES})
target_link_libraries(TerrariaCore PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)

# Main executable
add_executable(TerrariaClone src/main.cc)
target_link_libraries(TerrariaClone PRIVATE TerrariaCore)

# Tests
include(CTest)
include(Catch)
# catch_discover_tests(tests)
enable_testing()
add_subdirectory(tests)
