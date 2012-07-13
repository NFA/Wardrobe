#ifndef ragel_test_token_h
#define ragel_test_token_h
#include <unordered_map>
#include <string>

namespace LPC {
namespace Grammar {

enum class TokenType: unsigned char {
  END = 0,
  //
  Identifier,
  //
  Integer,
  Float,
  //
  Assign,
  // Control
  Return,
  // Structure
  OpenParen,
  CloseParen,
  OpenBrace,
  CloseBrace,
  Semi,
  Comma,
  // Logic
  // Arithmetic
  Add,
  Sub,
  Mult,
  Div,
  //
};
 

const char* getTokenStr(const TokenType &tok); 

class Token {
public:
  Token(TokenType, const char*);
  Token(TokenType, const char*, unsigned short, unsigned short);
  Token(const Token&) = delete;
  ~Token();
  bool operator==(const Token&) const;
  friend std::ostream& operator<<(std::ostream&, const Token&);
private:
  TokenType type;
  const char* data; 
  std::pair<unsigned short, unsigned short> loc;
};


} /* namespace Grammar */
} /* namespace LPC */
#endif
