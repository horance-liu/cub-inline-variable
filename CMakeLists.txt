cmake_minimum_required(VERSION 3.14)

project(cub_inline_variable
  VERSION 1.0 
  LANGUAGES CXX
)

option(CUB_RUN_TESTS "If ON, test cases for cub-inline-variable will be run." OFF)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")

# enable test runtime
if(${CUB_RUN_TESTS})
  include(CTest)
  include(cctest)
  enable_testing()
endif()

# target: cub
add_library(cub_inline_variable INTERFACE)

target_include_directories(cub_inline_variable
  INTERFACE include
)

target_compile_features(cub_inline_variable
  INTERFACE cxx_std_11
)

add_library(cub::inline_variable ALIAS cub_inline_variable)

if(BUILD_TESTING)
  add_subdirectory(test)
endif()
