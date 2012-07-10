#ifndef ragel_test_lexer_h
#define ragel_test_lexer_h

#include <iostream>
#include <vector>
#include <memory>
#include "token.h"
#include "../input.h"

namespace LPC {
namespace Grammar {

class Lexer {
public:
  Lexer(Input&);
  ~Lexer() = default;
  void DumpTokens();
  void Lex();
  int CountTokens() const;
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
       
  void addToken(TokenType, const char*, const char*);
  void advanceLocation(const char*, const char*);
};

} /* namespace Grammar */
} /* namespace LPC */

#endif
