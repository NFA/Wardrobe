#include <iostream>
#include <cstring>
#include <memory>
#include <iomanip>
#include "lexer.h"
#include "token.h"

namespace LPC {
namespace Grammar {


char *getTokenData(const char* start, const char* end) {
  char *data = new char[end - start + 1];
  strncpy(data, start, end - start);
  *(data + (end - start)) = '\0';
  return data;

}

//std::string getTokenData(const char* start, const char* end) {
//  return std::string(start).substr(0, end - start);
//}

%%{

machine lexer;

action semi_tok {
  addToken(TokenType::Semi, ts, te);
}
    
action plus_tok {
  addToken(TokenType::Plus, ts, te);
}

action minus_tok {
  addToken(TokenType::Minus, ts, te);
}

action times_tok {
  addToken(TokenType::Times, ts, te);
}

action divide_tok {
  addToken(TokenType::Divide, ts, te);
}

action openp_tok {
  addToken(TokenType::OpenP, ts, te);
}

action closep_tok {
  addToken(TokenType::CloseP, ts, te);
}

action number_tok {
  addToken(TokenType::Number, ts, te);
  
}

action space_tok {
  switch (*ts) {
    case ' ':
//      std::cout << "whitespace";
      ++current_column;
      break;
    case '\t':
//      std::cout << "tab";
      break;
    case '\n':
//      std::cout << "newline";
      ++current_line;
      current_column = 0;
      break;
    case '\r':
//      std::cout << "carriage return";
      break;
  }
//  std::cout << "identifier(\"";
//  std::cout.write(ts, te - ts);
//  std::cout << "\")\n";
}

number  = [0-9]+([0-9]+)?;
plus    = '+';
minus   = '-';
openp   = '(';
closep  = ')';
times   = '*';
divide  = '/';
semi    = ';';

main := |*
  number  => number_tok;
  plus    => plus_tok;
  minus   => minus_tok;
  openp   => openp_tok;
  closep  => closep_tok;
  times   => times_tok;
  divide  => divide_tok;
  semi    => semi_tok;
  space   => space_tok;
  *|;
    
        
}%%

// had ragel command %%write data here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header    
%% write data;


Lexer::~Lexer() {
  std::cout << "Lexer destroyed." << std::endl;
}

Lexer::Lexer(const char* data, std::size_t len): p(data), pe(data+len), eof(pe) {
  current_line = 0;
  current_column = 0;

  %% write init;

}

Lexer::Lexer(const char* data, const char* data_end): p(data), pe(data_end), eof(pe) {
  current_line = 0;
  current_column = 0;
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


//void Lexer::addToken(TokenType token_type, std::string token_data) {
//  tokens.push_back(std::unique_ptr<Token>(new Token(token_type, token_data)));
//}

void Lexer::addToken(TokenType token_type, const char* ts, const char* te) {
  tokens.push_back(std::unique_ptr<Token>(
    new Token(token_type, getTokenData(ts, te), current_line, current_column)
  ));
  advanceLocation(ts, te);
}

void Lexer::advanceLocation(const char *ts, const char *te) {
  current_column += (unsigned short)(te - ts);
}

} /* namespace Grammar */
} /* namespace LPC */
