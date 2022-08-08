cmake_minimum_required(VERSION 3.21)
project(mackenzie_pa2)

set(CMAKE_CXX_STANDARD 20)

add_executable(mackenzie_pa2 main.cpp sample_tests.cpp catch_setup.h catch_setup.cpp DSVector.h wordPage.cpp wordPage.h DSString.cpp DSString.h rwFile.cpp rwFile.h)