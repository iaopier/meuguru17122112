cmake_minimum_required(VERSION 3.21)
project(atividade1)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(atividade1
        celular.cpp
        celular.hpp
        main.cpp
        util.cpp
        util.hpp
        venda.cpp
        venda.hpp)
