cmake_minimum_required(VERSION 3.15)
project(Breakout)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

add_library(project_options INTERFACE)
target_compile_features(project_options INTERFACE cxx_std_20)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
   message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
   file(DOWNLOAD "https://github.com/conan-io/cmake-conan/raw/v0.15/conan.cmake"
                 "${CMAKE_BINARY_DIR}/conan.cmake"
                 TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(REQUIRES
                fmt/7.0.3
                #glfw/3.3.2
                BASIC_SETUP
                BUILD missing
)

find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

set(CMAKE_BUILD_TYPE Debug)

add_subdirectory(src)

execute_process(COMMAND ${CMAKE_CURRENT_SOURCE_DIR}/copy_cc.sh
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
