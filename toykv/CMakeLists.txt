cmake_minimum_required(VERSION 3.9)
project(toydb VERSION 0.1.0)

# C standard can be overridden when this is used as a sub-project.
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 17)
  set(CMAKE_C_STANDARD_REQUIRED OFF)
  set(CMAKE_C_EXTENSIONS OFF)
endif(NOT CMAKE_C_STANDARD)

# C++ standard can be overridden when this is used as a sub-project.
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 17)
  set(CMAKE_CXX_STANDARD_REQUIRED ON)
  set(CMAKE_CXX_EXTENSIONS OFF)
endif(NOT CMAKE_CXX_STANDARD)

set (CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}")
set(BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}")

include_directories(
    "${BASE_DIR}/"
)

add_subdirectory("${BASE_DIR}/storage")
add_subdirectory("${BASE_DIR}/rpc/gensrc")
add_subdirectory("${BASE_DIR}/service")

add_executable(toykv
  "toykv.cc"
)

target_link_libraries(toykv
  Storage
  libfmt.a
)