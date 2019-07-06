cmake_minimum_required(VERSION 3.14)
project(rwfile C)

set(CMAKE_C_STANDARD 99)

include_directories(includes)

set(HEADER rwfile.h)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -Ofast")

add_library(rwfile
        read_file/read_all_file.c   read_file/read_many_files.c read_file/read_line.c
        list/list_create.c          list/list_add_end.c         read_file/line_lst_work.c)