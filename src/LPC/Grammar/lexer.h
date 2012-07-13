#ifndef ragel_test_lexer_h
#define ragel_test_lexer_h

#include <iostream>
#include <vector>
#include <memory>
#include "token.h"

namespace LPC {

class Input;

namespace Grammar {

// Forward declarations
enum class TokenType: unsigned char;

class Lexer {
public:
  Lexer(Input&);
  ~Lexer() = default;
  void DumpTokens();
  void Lex();
  void LexAllTokens();
  TokenType LexToken();
  int CountTokens() const;
private:
  std::vector<std::unique_ptr<Token>> tokens;
  unsigned short line_nr;
  unsigned short offset;
  
  // Required variables by Ragel
  //
  // cs     current state
  // p      pointer to data
  // pe     pointer to data end
  // eof    pointer to eof
  // act    scanner bookkeeping variable
  // ts     pointer to token start
  // te     pointer to token end
  
  int cs;
  const char* p;
  const char* pe;
  const char* eof;
  int act;
  const char* ts;
  const char* te;
  
  // end Ragel variables
       
  void addToken(TokenType);
  void advanceLocation(const char*, const char*);
};

} /* namespace Grammar */
} /* namespace LPC */

#endif
