cmake_minimum_required(VERSION 3.9)
project(AUD_4 C)

set(CMAKE_C_STANDARD 11)

set(CMAKE_C_FLAGS "-fsanitize=address -fsanitize-address-use-after-scope -O1 -fno-omit-frame-pointer")

add_executable(AUD_4 main.c aud-4.c object.c)