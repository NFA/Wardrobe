#include <iostream>
#include "parser.h"

#include <sstream>

void *ParseAlloc(void *(*mallocProc)(size_t));
void Parse(void *yyp, int yymajor, LPC::Grammar::Token* yyminor);
void ParseFree(void *p, void (*freeProc)(void*));

namespace LPC {
namespace Grammar {

void Parser::parse() {
  void *pParser = ParseAlloc(malloc);
  Token* token;
  
  for (bool eof = false; !eof;) {
    try {
      token = lexer.LexToken();
      Parse(pParser, token->token(), token);
    } 
    catch (const Tokenizer::eof&) {
      eof = true;
    } 
    catch (const Tokenizer::unknown& e) {
      ParseFree(pParser, free);
      throw SyntaxError(e.what());
    } 
    catch (const Parser::ParsingInterrupted&) {
      std::stringstream fmt;
      fmt << "syntax error at the position " << tokenizer_.col() 
          << " line " << tokenizer_.lineno() 
          << " (offset " << tokenizer_.offset() << ")";
      ParseFree(pParser, free);
      throw SyntaxError(fmt.str());
    }
  }
  Parse(pParser, 0, token);
  ParseFree(pParser, free);
}

} /* namespace Grammar */
} /* namespace LPC */
