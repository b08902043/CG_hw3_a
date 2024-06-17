cmake_minimum_required ( VERSION 3.1.0...3.27.0 )

project ( hw3_a  LANGUAGES CXX )

# Set to C++11
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

#Executables
add_executable(main ./main.cpp)
