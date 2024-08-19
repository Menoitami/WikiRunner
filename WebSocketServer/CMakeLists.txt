cmake_minimum_required(VERSION 3.5)

project(WebSocketServer VERSION 1.0)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)


cmake_policy(SET CMP0167 NEW)


find_package(Boost 1.85 REQUIRED COMPONENTS system filesystem)

add_library(Server STATIC WebSocketServer/websocketserver.cpp WebSocketServer/websocketserver.h )


if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
    add_executable(WebSocketServer main.cpp)
    target_link_libraries(WebSocketServer PRIVATE
    Server
    ${Boost_LIBRARIES}
    ws2_32

)
else()
    message(FATAL_ERROR "Boost не найден")
endif()
