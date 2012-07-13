#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "token.h"

namespace LPC {
namespace Grammar {

// Clunky!!
const char* getTokenStr(const TokenType &tok) { 
  switch(tok) {
  case TokenType::END:        return "END";         break;
  case TokenType::Identifier: return "identifier";  break;
  case TokenType::Integer:    return "integer";     break;
  case TokenType::Float:      return "float";       break;
  case TokenType::Assign:     return "assign";      break;
  case TokenType::Return:     return "return";      break;
  case TokenType::OpenParen:  return "open_p";      break;
  case TokenType::CloseParen: return "close_p";     break;
  case TokenType::OpenBrace:  return "open_brace";  break;
  case TokenType::CloseBrace: return "close_brace"; break;
  case TokenType::Semi:       return "semi";        break;
  case TokenType::Comma:      return "comma";       break;
  case TokenType::Add:        return "add";         break;
  case TokenType::Sub:        return "sub";         break;
  case TokenType::Mult:       return "mult";        break;
  case TokenType::Div:        return "div";         break;
  default: return "unknown"; break;
  }
}


Token::Token(TokenType type, const char* data, unsigned short line, unsigned short col) : 
  type(type), data(data), loc(line, col) {
  //std::cout << "Constructing a token." << std::endl;
}

Token::Token(TokenType type, const char* data) :
  type(type), data(data) {
  //std::cout << "Constructing a token " << data << "." << std::endl;
  loc.first = -1;
  loc.second = -1;
}

bool Token::operator==(const Token& rhs) const {
  bool ret = (this->type == rhs.type) && (strcmp(this->data, rhs.data) == 0);
  std::cout << rhs.data << " == " << this->data << " : " << std::boolalpha << ret << std::endl;
  return ret;
}

Token::~Token() {
//  std::cout << "Destroying token " << data << "." << std::endl;
  delete[] data;
}

std::ostream& operator<<(std::ostream& os, const Token& tok) {
  const char* tt = getTokenStr(tok.type);
  std::stringstream data;
  std::stringstream loc;
  data << "'" << tok.data << "'";
  loc << "Loc<" << tok.loc.first << ":" << tok.loc.second << ">" ;
  os << std::setw(12) << tt;
  os << std::setw(12) << data.str();
  os << std::setw(12) << loc.str();
  return os;
}


} /* namespace Grammar */
} /* namespace LPC */