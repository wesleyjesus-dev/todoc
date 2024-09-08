cmake_minimum_required(VERSION 3.10)

# Nome do projeto
project(TodoCApp)

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK REQUIRED gtk4)

include_directories(${GTK_INCLUDE_DIRS})
link_directories(${GTK_LIBRARY_DIRS})

add_executable(todoc_app main.c)
target_link_libraries(todoc_app ${GTK_LIBRARIES})

# Nome do projeto
# project(TodoCApp)
