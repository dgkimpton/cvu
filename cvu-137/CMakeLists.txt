# CMakeLists.txt
cmake_minimum_required(VERSION 3.22)
project(playing_cards)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
add_compile_options(
        -Wall
        -Werror
        -Wpedantic
        -Wextra
)
add_executable(cvu137
        tests.cpp
        test_card.cpp
        card.cpp
        test_card_helpers.cpp
        card_helpers.cpp
)