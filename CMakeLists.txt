cmake_minimum_required(VERSION 3.10)

project(RealtyCode)

set(CMAKE_CXX_STANDARD 17)

add_executable(program
    src/Main.cpp
    src/Apartment.cpp
    src/House.cpp
    src/Menu.cpp
    src/RealEstateManager.cpp
    src/OBJECTS_LIST.cpp
    src/utils.cpp
)