cmake_minimum_required(VERSION 3.5)

project(WikiRunner VERSION 0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets )
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets Network)

set(PROJECT_SOURCES
    main.cpp
)

add_subdirectory(RegWindow)  # Добавляем директориb
add_subdirectory(GameWindow)
add_subdirectory(MainWindow)
add_subdirectory(MenuWindow)
add_subdirectory(PersonClass)


if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(WikiRunner
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
        Pictures.qrc


    )
else()
    if(ANDROID)
        add_library(WikiRunner SHARED
            ${PROJECT_SOURCES}
        )
    else()
        add_executable(WikiRunner
            ${PROJECT_SOURCES}
        )
    endif()
endif()

# Линкуем библиотеку RegWindow с основным проектом
target_link_libraries(WikiRunner PRIVATE Qt${QT_VERSION_MAJOR}::Widgets RegWindow GameWindow MainWindow MenuWindow PersonClass)
target_link_libraries(WikiRunner PRIVATE Qt6::Network)




if(${QT_VERSION} VERSION_LESS 6.1.0)
    set(BUNDLE_ID_OPTION MACOSX_BUNDLE_GUI_IDENTIFIER com.example.RegWindow)
endif()

set_target_properties(WikiRunner PROPERTIES
    ${BUNDLE_ID_OPTION}
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

include(GNUInstallDirs)
install(TARGETS WikiRunner
    BUNDLE DESTINATION .
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(WikiRunner)
endif()
