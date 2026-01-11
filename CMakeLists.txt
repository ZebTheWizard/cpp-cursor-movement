cmake_minimum_required(VERSION 4.2)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
project(CursorMovement)

find_package(Curses REQUIRED)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

aux_source_directory(src SOURCES)

add_executable(main ${SOURCES})
target_include_directories(main PRIVATE src)

target_link_libraries(main ${CURSES_LIBRARIES})
