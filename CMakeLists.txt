cmake_minimum_required ( VERSION 3.1.0...3.27.0 )

project ( hw3_a  LANGUAGES CXX )

# Set to C++11
set ( CMAKE_CXX_STANDARD          11 )
set ( CMAKE_CXX_STANDARD_REQUIRED ON )
set ( CMAKE_CXX_EXTENSIONS        OFF )

# Source

set ( SOURCE
	./src/vec3.h
	./src/ray.h
	./src/sphere.h
	./src/main.cpp
)

#Executables
add_executable(main ${SOURCE})
