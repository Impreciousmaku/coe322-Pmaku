cmake_minimum_required
project(Impreciousmaku)

set(CMAKE_CXX_STANDARD 11)

# Add the path to cxxopts.hpp header file
include_directories(path/to/cxxopts)

add_executable(Impreciousmaku main.cpp)

# Link the cxxopts library
# target_link_libraries(Impreciousmaku <library_name>)
