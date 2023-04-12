cmake_minimum_required(VERSION 3.24)
project(test_1)

set(CMAKE_CXX_STANDARD 23)

add_executable(test_1 main.cpp Phrase.cpp Phrase.h)
