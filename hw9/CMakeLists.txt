CMakeLists.txt

cmake_minimum_required(VERSION 3.10)

project(Hw9_Coe322)

# Add executable
add_executable(main main.cpp filename.cpp)

# Include header files directory
target_include_directories(main PRIVATE ${ CMAKE_CURRENT_SOURCE_DIR })

# Set C++ standard
set_target_properties(main PROPERTIES CXX_STANDARD 11)

