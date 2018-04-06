SET(ALGORITHM_NAME "karatsuba")
SET(ALGORITHM_DIRECTORY "Karatsuba")

set(CMAKE_C_COMPILER /usr/bin/gcc)
set(CMAKE_CXX_COMPILER /usr/bin/g++)

SET(CMAKE_SHARED_LIBRARY_PREFIX "")

# It sets default to Release build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Release")
endif()

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wextra -Wall -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} \
        -O0 -g -rdynamic -Wshadow -Wunused-parameter -Wunused-variable -Wdelete-non-virtual-dtor -Wfatal-errors \
        -Woverloaded-virtual -Wunreachable-code -Wno-unused -Wundef -Wl,--no-undefined -Wl,--no-allow-shlib-undefined")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -w -Wl,--discard-all")

# It defines the custom directory structure.
set(PROJECT_SOURCE_DIR ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/src)
set(PROJECT_INCLUDE_DIR ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/include)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/build)

file(GLOB_RECURSE ALGORITHM_SOURCE_FILES ${PROJECT_SOURCE_DIR}/${ALGORITHM_DIRECTORY}/*.cpp)

include_directories("${PROJECT_INCLUDE_DIR}")
include_directories("${PROJECT_SOURCE_DIR}")

add_library(${ALGORITHM_NAME} SHARED ${ALGORITHM_SOURCE_FILES})
target_include_directories(${ALGORITHM_NAME} PUBLIC ${PROJECT_INCLUDE_DIR})

# It handles the tests
add_subdirectory(test)
