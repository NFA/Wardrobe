#ifndef ragel_test_lexer_h
#define ragel_test_lexer_h

#include <iostream>
#include <vector>
#include <memory>
#include "token.h"

namespace LPC {
namespace Grammar {

class Lexer {
public:
  Lexer(const char* data, std::size_t len);
  Lexer(const char* data, const char* data_end);
  ~Lexer();
  void DumpTokens();
  void Lex();
private:
  std::vector<std::unique_ptr<Token>> tokens;
  unsigned short current_line;
  unsigned short current_column;
  // Required variables by Ragel
  
  // current state
  int cs;
  // data pointer
  const char* p;
  // data end pointer
  const char* pe;
  // eof pointer
  const char* eof;
  // scanner bookkeeping variable
  int act;
  // pointer to token start
  const char* ts;
  // pointer to token end
  const char* te;
       
//  void addToken(TokenType token_type, std::string token_data);
  void addToken(TokenType token_type, const char* ts, const char* te);
  void advanceLocation(const char *ts, const char *te);
};

} /* namespace Grammar */
} /* namespace LPC */

#endif
