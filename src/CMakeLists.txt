add_subdirectory(config)
add_subdirectory(LPC)
add_subdirectory(derived)

add_executable(wardrobe main)
target_link_libraries(wardrobe input lexer ${LINKER_FLAGS})

