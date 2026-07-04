cmake_minimum_required(VERSION 3.21)

project(BlockTorch
    VERSION 0.0.6
    DESCRIPTION "Visual block-based AI/ML/DL desktop application"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

add_subdirectory(src)
add_subdirectory(tests/cpp)
