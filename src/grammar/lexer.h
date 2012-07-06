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
  ~Lexer();
  void DumpTokens();
  void Execute();
  const char* p;
  const char* pe;
  const char* eof;
private:
  std::vector<std::unique_ptr<Token>> tokens;
  int cs;
  int act;
  const char* ts;
  const char* te;
    
  static const int lexer_start = 1;
    
  //void* lparser;   
    
  void addToken(TokenType token_type, std::string token_data);
};

} /* namespace Grammar */
} /* namespace LPC */

#endif
