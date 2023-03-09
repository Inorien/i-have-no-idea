CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

PROJECT(game
  LANGUAGES C CXX)

add_executable(game
  main.cpp)

target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR})
