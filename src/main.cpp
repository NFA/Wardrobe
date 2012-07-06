#include <cstddef>
#include <cstring>

#include "lexer.h"

int main()
{
  const char* data = "5 + 6 * (13 - 4) - 4 / 2";
  std::size_t sz = strlen(data);
  std::cout << "Feeding \"" << data << "\" to the lexer." << std::endl;
  LPC::Grammar::Lexer lex(data, sz);
  lex.Execute(); // really need this??
  lex.DumpTokens();
}