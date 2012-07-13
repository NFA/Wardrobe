cmake_minimum_required (VERSION 2.6)
project (Wardrobe)

# Versioning
set (wardrobe_VERSION_MAJOR 0)
set (wardrobe_VERSION_MINOR 1)
set (wardrobe_VERSION_PATCH 0)

# We're making heavy use of C++11 features
add_definitions("-std=c++11 -Wall")

if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
  message(STATUS "Detected Mac OS X")
  message(STATUS "-- Using the libc++ library.")
  set(STDLIB "-stdlib=libc++")
  add_definitions(${STDLIB})
  set(LINKER_FLAGS ${STDLIB})
endif(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")




find_program(RAGEL ragel)

if(NOT RAGEL)
    message(FATAL_ERROR "Ragel not found, aborting.")
endif(NOT RAGEL)

# Some directory structure to help some sources that are being generated
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(DERIVED_DIR ${SRC_DIR}/derived)
set(LPC_DIR ${SRC_DIR}/LPC)
set(GRAMMAR_DIR ${LPC_DIR}/Grammar)


# Entry point
add_subdirectory(${SRC_DIR})

