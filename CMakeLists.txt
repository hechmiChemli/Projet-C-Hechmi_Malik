cmake_minimum_required(VERSION 3.27)
project(CDATAFRAME)

set(CMAKE_CXX_STANDARD 17)

add_executable(CDATAFRAME
        colonne.h
        cdataframe.h
        cdataframe.c
        main.c)

