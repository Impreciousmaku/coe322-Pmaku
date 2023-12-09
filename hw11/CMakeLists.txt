cmake_minimum_required(VERSION 3.12)
project(Hw11_coe322)

set(CMAKE_CXX_STANDARD 14)

# Add the source files
add_executable(MyExecutable object/container.cpp geo_vector.h)

# Optionally, you can set the output directory
# set_target_properties(MyExecutable PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
