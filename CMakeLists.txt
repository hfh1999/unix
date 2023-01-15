cmake_minimum_required(VERSION 3.0.0)
project(unix_p C)

#set(CMAKE_C_STANDARD )
#set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CFLAG
        -g
        #-O2
        # -DVALGRIND
        # -DMUDUO_STD_STRING
        #-Wall
        #-Wextra
        # -m32
        #-Werror
        #-Wconversion
        #-Wno-unused-parameter
        #-Wold-style-cast
        #-Woverloaded-virtual
        #-Wpointer-arith
        #-Wshadow
        #-Wwrite-strings
        #-march=native
        # -MMD
        # -std=c++0x
        #-rdynamic
        #-pthread
        )
# find_package(Boost REQUIRED)
#string(REPLACE ";" " " CMAKE_CXX_FLAGS "${CXX_FLAGS}")
#set(FEIPU_BASE_INCLUDE ${PROJECT_SOURCE_DIR}/base/include)
#set(FEIPU_HTTP_INCLUDE ${PROJECT_SOURCE_DIR}/http)
#set(TEST_DIR ${PROJECT_SOURCE_DIR}/test)
#set(SNIPPET_DIR ${PROJECT_SOURCE_DIR}/snippet)
#set(HTTP_DIR ${PROJECT_SOURCE_DIR}/http)
#set(BASE_DIR ${PROJECT_SOURCE_DIR}/base)
#include_directories(${FEIPU_BASE_INCLUDE})
#include_directories(${FEIPU_HTTP_INCLUDE})
#include_directories(${Boost_INCLUDE_DIRS})
#add_subdirectory(${TEST_DIR})
#add_subdirectory(${SNIPPET_DIR})
#add_subdirectory(${HTTP_DIR})
#add_subdirectory(${BASE_DIR})
add_executable(test_select test_select.c)
add_executable(test_shell_pipe test_shell_pipe.c)

add_subdirectory(chapter2)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter6)
add_subdirectory(chapter7)
add_subdirectory(chapter11)
add_subdirectory(nargs)
