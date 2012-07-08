
cmake_minimum_required (VERSION 2.6)
project (Yggdrasil)

# Versioning
set (Yggdrasil_VERSION_MAJOR 0)
set (Yggdrasil_VERSION_MINOR 1)

# We're making heavy use of C++11 features
add_definitions(-std=c++11)

find_program(RAGEL ragel)

if(NOT RAGEL)
	message(FATAL_ERROR "Ragel not found, aborting.")
endif(NOT RAGEL)


# Entry point
add_subdirectory(src)



