cmake_minimum_required(VERSION 3.16)
project(TerrariaClone)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

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
enable_testing()
include(CTest)
file(GLOB_RECURSE TESTSOURCES "${PROJECT_SOURCE_DIR}/tests/*.cc")
add_executable(tests ${TESTSOURCES})
target_link_libraries(tests PRIVATE TerrariaCore Catch2::Catch2WithMain)

add_test(TerrariaCloneTests tests)

