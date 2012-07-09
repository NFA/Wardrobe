#include <iostream>
#include <sstream>
#include <iomanip>
#include "token.h"

namespace LPC {
namespace Grammar {


std::string printTokenType(const TokenType &tok) {
  std::string ret;
  switch (tok) {
    case TokenType::Semi:
      ret = "semi";
      break;
    case TokenType::Plus:
      ret = "plus";
      break;
    case TokenType::Minus:
      ret = "minus";
      break;
    case TokenType::Times:
      ret = "times";
      break;
    case TokenType::Divide:
      ret = "divide";
      break;
    case TokenType::OpenP:
      ret = "openP";
      break;
    case TokenType::CloseP:
      ret = "closeP";
      break;
    case TokenType::Number:
      ret = "number";
      break;
  }
  return ret;
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
  bool ret = (this->type == rhs.type) && (std::strcmp(this->data, rhs.data) == 0);
  std::cout << rhs.data << " == " << this->data << " : " << std::boolalpha << ret << std::endl;
  return ret;
}

Token::~Token() {
//  std::cout << "Destroying token " << data << "." << std::endl;
  delete[] data;
}

std::ostream& operator<<(std::ostream& os, const Token& tok) {
  std::string tt;
  std::stringstream data;
  std::stringstream loc;
  tt = printTokenType(tok.type);
  data << "'" << tok.data << "'";
  loc << "Loc<" << tok.loc.first << ":" << tok.loc.second << ">" ;
  os << std::setw(12) << tt;
  os << std::setw(12) << data.str();
  os << std::setw(12) << loc.str();
  return os;
}


} /* namespace Grammar */
} /* namespace LPC */