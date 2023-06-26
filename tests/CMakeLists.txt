cmake_minimum_required(VERSION 3.24.2)

project(Kamagotchi_tests)

add_executable(${PROJECT_NAME} test_main.cpp)

add_subdirectory(../src [binary_dir][EXCLUDE_FROM_ALL])

target_include_directories(${PROJECT_NAME} PUBLIC includes/ ../includes [binary_dir][EXCLUDE_FROM_ALL])

target_link_libraries(${PROJECT_NAME} PUBLIC pet utils)
