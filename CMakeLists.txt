cmake_minimum_required(VERSION 3.31)
project(music)

set(CMAKE_CXX_STANDARD 20)

add_executable(music main.cpp
        dice.cpp
        dice.h
        music_theory.cpp
        music_theory.h)
