# CMakeLists.txt

cmake_minimum_required(VERSION 3.12)
project(Impreciousmaku)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Add the fmtlib library
find_package(fmt REQUIRED)

# Include directories for fmtlib
include_directories(${fmt_INCLUDE_DIRS})

# Create the executable
add_executable(Impreciousmaku main.cpp)

# Link fmtlib to the executable
target_link_libraries(Impreciousmaku PRIVATE fmt::fmt)
