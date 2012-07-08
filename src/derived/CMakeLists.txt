set(GRAMMAR_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../LPC/Grammar)

set(LEXER_CPP ${CMAKE_CURRENT_SOURCE_DIR}/lexer.cpp)
set(LEXER_RL ${GRAMMAR_DIR}/lexer.rl)

add_custom_command(
	OUTPUT ${LEXER_CPP}
	COMMAND ${RAGEL} -o ${LEXER_CPP} ${LEXER_RL}
	DEPENDS ${LEXER_RL} # rebuild if lexer.rl is newer
)

include_directories(${GRAMMAR_DIR})

add_library(lexer STATIC ${LEXER_CPP})
target_link_libraries(lexer token)
