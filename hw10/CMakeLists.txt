cmake_minimum_required(VERSION 3.10)
project(Hw10_Coe322)
set(CMAKE_CXX_STANDARD 11)

# Locate and include Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add your source files
set(SOURCES
    f.cpp  # Replace with the actual file names you have
    polynomial.cpp
    main.cpp  # Add your main file if you have one
)

# Add the executable for your main program (if applicable)
# add_executable(YourExecutable ${SOURCES})

# Add the executable for the unit tests
add_executable(UnitTests
    unit_test_f.cpp
    unit_test_polynomial.cpp
    unit_test_bounds.cpp
    unit_test_zero.cpp
    ${SOURCES}  # Include your source files in the test executable
)

# Link the executable with Google Test and other necessary libraries
target_link_libraries(UnitTests ${GTEST_LIBRARIES} pthread)

# Optionally, you can enable testing with 'make test'
enable_testing()
add_test(NAME UnitTests COMMAND UnitTests)
