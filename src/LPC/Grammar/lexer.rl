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
  identifier  => { addToken(TokenType::Identifier,  ts, te); };
  integer     => { addToken(TokenType::Integer,     ts, te); };
  float       => { addToken(TokenType::Float,       ts, te); };
  # inc dec assig ..
  '='         => { addToken(TokenType::Assign,      ts, te); };
  # Control
  'return'    => { addToken(TokenType::Return,      ts, te); };
  # Structure
  '('         => { addToken(TokenType::OpenParen,   ts, te); };
  ')'         => { addToken(TokenType::CloseParen,  ts, te); };
  '{'         => { addToken(TokenType::OpenBrace,   ts, te); };
  '}'         => { addToken(TokenType::CloseBrace,  ts, te); };
  ';'         => { addToken(TokenType::Semi,        ts, te); };
  ','         => { addToken(TokenType::Comma,       ts, te); };
  # Logic
  
  # Arithmetic 
  '+'         => { addToken(TokenType::Add,         ts, te); };
  '-'         => { addToken(TokenType::Sub,         ts, te); };
  '*'         => { addToken(TokenType::Mult,        ts, te); };
  '/'         => { addToken(TokenType::Div,         ts, te); };
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


void Lexer::Lex() { 
  %% write exec;
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


void Lexer::addToken(TokenType token_type, const char* ts, const char* te) {
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
