# CMakeLists.txt

cmake_minimum_required
project(Impreciousmaku)

# Set the C++ standard to 14
set(CMAKE_CXX_STANDARD 14)

# Add the source file to the project
add_executable(${PROJECT_NAME} pointer_dynrectangle.cpp)
