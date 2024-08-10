cmake_minimum_required(VERSION 3.5)

project(RegWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCES
    regwindow.cpp
)

set(HEADERS
    regwindow.h
)

add_library(RegWindow STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(RegWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(RegWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

