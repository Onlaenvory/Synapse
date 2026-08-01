cmake_minimum_required(VERSION 3.25)

project(Yoshimura LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
  # Sorce files
  src/features/notification/notifier.cpp
  src/features/authenticate/auth.cpp
  src/client/client.cpp
  src/main.cpp

  # Header files
  src/features/notification/notifier.hpp
  src/features/authenticate/auth.hpp
  src/client/client.hpp

  # Settings
  src/settings/setting.hpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
  src
)
