cmake_minimum_required(VERSION 3.1)
project(derivejson)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(CATCH_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/catch/single_include)
set(CATCH_INCLUDE_DIR ${CATCH_INCLUDE_DIR} PARENT_SCOPE)
set(JSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/json/src)
set(JSON_INCLUDE_DIR ${JSON_INCLUDE_DIR} PARENT_SCOPE)
set(PREPROCESSOR_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/preprocessor/include)
set(PREPROCESSOR_INCLUDE_DIR ${PREPROCESSOR_INCLUDE_DIR} PARENT_SCOPE)
set(DERIVEJSON_INCLUDE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(DERIVEJSON_INCLUDE_DIR ${DERIVEJSON_INCLUDE_DIR} PARENT_SCOPE)

macro(toggle_option OPTION_NAME OPTION_TEXT OPTION_DEFAULT)
    option(${OPTION_NAME} ${OPTION_TEXT} ${OPTION_DEFAULT})
    if(DEFINED ENV{${OPTION_NAME}})
        # Allow setting the option through an environment variable
        set(${OPTION_NAME} $ENV{${OPTION_NAME}})
    endif()
    if(${OPTION_NAME})
        add_definitions(-D${OPTION_NAME})
    endif()
    message(STATUS "  ${OPTION_NAME}: ${${OPTION_NAME}}")
endmacro()

include_directories(
  ${CATCH_INCLUDE_DIR}
  ${JSON_INCLUDE_DIR}
  ${PREPROCESSOR_INCLUDE_DIR}
  ${DERIVEJSON_INCLUDE_DIR}
  )

toggle_option(BUILD_DERIVEJSON_TESTS "Set to ON to build derivejson tests." ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++14")

if(BUILD_DERIVEJSON_TESTS)
  add_executable(derivejson_tests test/tests.cc)
  enable_testing()
  add_test(NAME Tests COMMAND derivejson_tests)
endif()
