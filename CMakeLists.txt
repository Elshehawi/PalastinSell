cmake_minimum_required(VERSION 4.0)
project(PalastinShell C)

set(CMAKE_C_STANDARD 17)

add_executable(PalastinShell main.c
        input_paraser.c
        helpers.c
        builtins.c)
