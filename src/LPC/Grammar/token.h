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
  Token(TokenType type, std::string data);
  Token(TokenType type, std::string data, unsigned short line, unsigned short column);
  Token(const Token& src);
  ~Token();
  friend std::ostream& operator<<(std::ostream&, const Token&);
private:
  TokenType type;
  std::string data; 
  std::pair<unsigned short, unsigned short> loc;
};


} /* namespace Grammar */
} /* namespace LPC */
#endif
