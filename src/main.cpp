#include <cstddef>
#include <cstring>

//#include "config/YggdrasilConfig.h"
#include "LPC/Grammar/lexer.h"

void header();

int main() {
  const char* data = "5 + 6 * (13 - 4) - 4 / 2";
  std::size_t sz = strlen(data);
  
  header();

  std::cout << "Feeding \"" << data << "\" to the lexer." << std::endl;
  LPC::Grammar::Lexer lex(data, sz);
  lex.Execute(); // really need this??
  lex.DumpTokens();
}

void header() {
//  std::cout << "Yggdrasil " << Yggdrasil_VERSION_MAJOR 
//	<< "." << Yggdrasil_VERSION_MINOR;
}

