cmake_minimum_required(VERSION 2.8.12)
project(CompiledModule)

add_subdirectory(pybind11)
pybind11_add_module(CompiledModule src/main.cpp)