cmake_minimum_required(VERSION 3.5)

project(PersonClass LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Найти пакет Qt
find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Core)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Core)

set(SOURCES
    personclass.cpp
)

set(HEADERS
    personclass.h
)

add_library(PersonClass STATIC
    ${SOURCES}
    ${HEADERS}
)

# Указать директории для include
target_include_directories(PersonClass PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Подключить необходимые модули Qt к вашей библиотеке
target_link_libraries(PersonClass PUBLIC Qt${QT_VERSION_MAJOR}::Core)

