# Create a config file
configure_file (
        "config/YggdrasilConfig.h.in"
        "config/YggdrasilConfig.h"
)
add_subdirectory(LPC)
add_subdirectory(derived)

add_executable(yggdrasil main)
target_link_libraries(yggdrasil input lexer ${LINKER_FLAGS})

