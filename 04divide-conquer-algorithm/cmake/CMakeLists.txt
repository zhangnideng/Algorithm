cmake_minimum_required(VERSION 2.8)

project(find_maximum_subarray)

message(STATUS "This is project binary dir " ${PROJECT_BINARY_DIR})
message(STATUS "This is project source dir " ${PROJECT_SOURCE_DIR})

get_filename_component(ROOT ${PROJECT_SOURCE_DIR}/.. REALPATH)

include_directories(${ROOT}/code/max_subarray)

aux_source_directory(${ROOT}/code DIR)
aux_source_directory(${ROOT}/code/max_subarray DIR)

#add_subdirectory(${ROOT}/code/insertion)

add_executable(test ${DIR})
