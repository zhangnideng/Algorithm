cmake_minimum_required(VERSION 2.8)

project(find_maximum_subarray)

message(STATUS "This is project binary dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is project source dir " ${PROJECT_SOURCE_DIR})

get_filename_component(ROOT ${PROJECT_SOURCE_DIR}/.. REALPATH)

aux_source_directory(${ROOT}/code DIR)

add_executable(test ${DIR})
