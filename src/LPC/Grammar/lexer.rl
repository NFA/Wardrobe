#include <iostream>
#include <cstring>
#include <memory>
#include <iomanip>
#include "lexer.h"
#include "token.h"
#include "../LPC/input.h"

namespace LPC {
namespace Grammar {


char *getTokenData(const char* start, const char* end) {
  char *data = new char[end - start + 1];
  strncpy(data, start, end - start);
  *(data + (end - start)) = '\0';
  return data;

}

%%{

machine lexer;

action space_tok {
  switch (*ts) {
    case ' ':
      ++offset;
      break;
    case '\t':
      ++line_nr;
      break;
    case '\n':
      ++line_nr;
      offset = 0;
      break;
    case '\r':
      // nop, only handle CRLF and LF newlines
      break;
  }
}

identifier  = [a-zA-Z_][a-zA-Z_0-9]*;
integer     = digit+;
float       = /digit+.\.digit+/;

main := |*
  #
  #
  identifier  => { 
    ret = TokenType::Identifier;
    addToken(ret);
    fbreak;
  };
  integer     => { 
    ret = TokenType::Integer;
    addToken(ret);
    fbreak;
  };
  float       => { 
    ret = TokenType::Float;
    addToken(ret);
    fbreak;
  };
  # inc dec assig ..
  #
  '='         => { 
    ret = TokenType::Assign;
    addToken(ret);
    fbreak;
  };
  # Control
  #
  'return'    => { 
    ret = TokenType::Return;
    addToken(ret);
    fbreak;
  };
  # Structure
  '('         => { 
    ret = TokenType::OpenParen;
    addToken(ret);
    fbreak;
  };
  ')'         => { 
    ret = TokenType::CloseParen;
    addToken(ret);
    fbreak;
  };
  '{'         => { 
    ret = TokenType::OpenBrace;
    addToken(ret);
    fbreak;
  };
  '}'         => { 
    ret = TokenType::CloseBrace;
    addToken(ret);
    fbreak;
  };
  ';'         => { 
    ret = TokenType::Semi;
    addToken(ret);
    fbreak;
  };
  ','         => { 
    ret = TokenType::Comma;
    addToken(ret);
    fbreak;
  };
  # Logic
  
  # Arithmetic 
  '+'         => { 
    ret = TokenType::Add;
    addToken(ret);
    fbreak;
  };
  '-'         => { 
    ret = TokenType::Sub;
    addToken(ret);
    fbreak;
  };
  '*'         => { 
    ret = TokenType::Mult;
    addToken(ret);
    fbreak;
  };
  '/'         => { 
    ret = TokenType::Div;
    addToken(ret);
    fbreak;
  };
  # Misc
  space       => space_tok;
  *|;
    
        
}%%

// had ragel command %%write data here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header    
%% write data;

Lexer::Lexer(Input& input) : p(input.GetBuffer()), pe(input.GetBufferEnd()), eof(pe) {
  line_nr = 0;
  offset = 0;
  %% write init;
}

void Lexer::LexAllTokens() {
  TokenType stop;
  do {
    stop = LexToken();
  } while (p != pe);
}


TokenType Lexer::LexToken() { 
  TokenType ret = TokenType::END;
  %% write exec;
  return ret;
}

Token& Lexer::LexToken() {
  LexToken();
  return tokens.back();

}

void Lexer::DumpTokens() {
  std::cout << std::setw(12) << std::left << "Token";
  std::cout << std::setw(12) << std::left << "Data";
  std::cout << std::setw(12) << std::left << "Location";
  std::cout << std::endl;
  for (const auto& tok: tokens) {
    std::cout << *tok << std::endl;
  }
}

int Lexer::CountTokens() const {
  return tokens.size();
}


void Lexer::addToken(TokenType token_type) {
  tokens.push_back(std::unique_ptr<Token>(
    new Token(token_type, getTokenData(ts, te), line_nr, offset)
  ));
  advanceLocation(ts, te);
}

void Lexer::advanceLocation(const char *ts, const char *te) {
  offset += (unsigned short)(te - ts);
}


} /* namespace Grammar */
} /* namespace LPC */
