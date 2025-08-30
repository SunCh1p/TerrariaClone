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

# Find Catch2
find_package(Catch2 3 REQUIRED)

# Collect all source files
file(GLOB_RECURSE SOURCES "${PROJECT_SOURCE_DIR}/src/*.cc")

# Add executable
add_executable(TerrariaClone ${SOURCES})

# Link SDL3 libraries
target_link_libraries(TerrariaClone PUBLIC SDL3::SDL3 SDL3_ttf::SDL3_ttf )

# file(GLOB_RECURSE TESTSOURCES "${PROJECT_SOURCE_DIR}/test/*.cc")

# # Test executable
# add_executable(TerrariaCloneTests ${TESTSOURCES})

# # Link Catch2 and project code
# target_link_libraries(TerrariaCloneTests PRIVATE Catch2::Catch2WithMain TerrariaClone)

