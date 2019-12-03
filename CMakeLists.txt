cmake_minimum_required(VERSION 3.14)

project(seqlist C)
project(linklist C)
project(dlinklist C)
project(sortlinklist C)

set(CMAKE_C_STANDARD 11)

add_executable(seqlist seqlist/main seqlist/seqlist)
add_executable(linklist linklist/main linklist/linklist)
add_executable(sortlinklist sortlinklist/main sortlinklist/sortlinklist)
add_executable(dlinksortlist dlinklist/main dlinklist/dlinklist)