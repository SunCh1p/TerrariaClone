cmake_minimum_required(VERSION 3.16)
project(HelloSDL3)

# Set C++ Standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find SDL3 installed system-wide
find_package(SDL3 CONFIG REQUIRED)
find_package(SDL3_ttf REQUIRED)

# Add executable
add_executable(hello hello.cc)

# Link SDL3
target_link_libraries(hello PRIVATE SDL3::SDL3 SDL3_ttf::SDL3_ttf)
