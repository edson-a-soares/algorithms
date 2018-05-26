SET(TEST_UNIT "InsertionSortTests")
SET(TEST_ALGORITHM_DIRECTORY "InsertionSort")

enable_testing()

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

if(NOT GTEST_FOUND)
    message(WARNING "Failed to find the GTest libraries.")
endif()

file(GLOB_RECURSE TEST_SOURCE_FILES
    ${CMAKE_HOME_DIRECTORY}/${ALGORITHM_DIRECTORY}/tests/${TEST_ALGORITHM_DIRECTORY}/*.cpp)

add_executable(${TEST_UNIT} ${TEST_SOURCE_FILES})
target_link_libraries(${TEST_UNIT} gtest gtest_main pthread ${ALGORITHM_NAME})

add_test(NAME ${TEST_UNIT} COMMAND ${TEST_UNIT})
