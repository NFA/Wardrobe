#ifndef ragel_test_token_h
#define ragel_test_token_h


namespace LPC {
namespace Grammar {

enum class TokenType: unsigned int {
  Semi,
  Plus,
  Minus,
  Times,
  Divide,
  OpenP,
  CloseP,
  Number,
};

std::string printTokenType(TokenType &tok);

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
