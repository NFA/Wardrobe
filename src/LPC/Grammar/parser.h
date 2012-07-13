#ifndef wardrobe_parser_h
#define wardrobe_parser_h
#include <exception>
#include "lexer.h"

namespace LPC {
Namespace Grammar {

class Parser {
public:
  Parser(Lexer& lexer) : lexer(lexer) {}
  void Parse();
  
  class ParsingInterrupted: public std::exception {
  public:
    ParsingInterrupted() {}
  };
  
  class SyntaxError: public std::exception {
  public:
    SyntaxError(const char* str) : std::exception(str)) {}
  };

private:
    Lexer& lexer;

};


} /* namespace Grammar */
} /* namespace LPC */


#endif
