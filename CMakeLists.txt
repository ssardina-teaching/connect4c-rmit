cmake_minimum_required(VERSION 3.5)
project(connect4-rmit)


set(C_STANDARD 98)


set(SOURCE_FILES
        game.c
        c4.c
        c4_functions.c
        get_agents.c)


add_executable(connect4 ${SOURCE_FILES})