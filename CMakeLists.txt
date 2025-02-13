cmake_minimum_required(VERSION 3.10)
# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# used internally by CMake to identify your project
project(MovieRating)
# Include the directory headers are located
include_directories(${CMAKE_SOURCE_DIR}/include)
# Add the main executable
add_executable(MovieRating src/main.cpp src/movie.cpp src/movie_factory.cpp)
add_executable(test test/test.cpp src/movie.cpp src/movie_factory.cpp)