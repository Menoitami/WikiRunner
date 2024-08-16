cmake_minimum_required(VERSION 3.5)

project(CreateRoomWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCES
    createroomwindow.cpp
)

set(HEADERS
    createroomwindow.h
)

add_library(CreateRoomWindow STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(CreateRoomWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(CreateRoomWindow PRIVATE PersonClass)
target_include_directories(CreateRoomWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

