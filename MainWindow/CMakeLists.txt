cmake_minimum_required(VERSION 3.5)

project(MainWindow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(SOURCES
    mainwindow.cpp
)

set(HEADERS
    mainwindow.h
)


add_library(MainWindow STATIC
    ${SOURCES}
    ${HEADERS}
)

target_link_libraries(MainWindow PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_link_libraries(MainWindow PRIVATE RegWindow MenuWindow)
target_include_directories(MainWindow PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

