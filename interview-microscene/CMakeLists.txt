cmake_minimum_required (VERSION 3.5)

project (interview)

aux_source_directory(. DIR_SRCS)

add_executable(interview ${DIR_SRCS})
