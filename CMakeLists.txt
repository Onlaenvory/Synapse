cmake_minimum_required(VERSION 3.25)

project(Synapse LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
  # Source files
  src/core/setting.hpp
  src/core/logger.hpp
  src/core/auth.cpp
  src/main.cpp

  # Data
  data/active_keys.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
  src
)
