#include <iostream>
//#include "config/YggdrasilConfig.h"
#include "LPC/input.h"
#include "LPC/Grammar/lexer.h"

void header();

int main() {
// Lexing ~12Mb text file took ~5.8 seconds
// it contained >7M tokens
// ~2.05 Mb/sec
// 1.2M tokens/sec

  
  const char* data1 =
    "int x;                 \n"
    "int y = 5;             \n"
    "x = 3;                 \n"
    "int calc(int value) {  \n"
    "    return value*x*y;  \n"
    "}                      \n"
    "";
//  std::ifstream data2("tokens.txt");
//  std::ifstream data3("tokens2.txt");
  
  LPC::Input input1(data1);
//  LPC::Input input2(data2);
//  LPC::Input input3(data3);
   
  header();

  LPC::Grammar::Lexer lex1(input1);
//  LPC::Grammar::Lexer lex2(input2);
//  LPC::Grammar::Lexer lex3(input3);
  
  lex1.Lex();
//  lex2.Lex();
//  lex3.Lex();
 
  std::cout << " lex1 size = " << lex1.CountTokens() << std::endl;
//  std::cout << " lex2 size = " << lex2.CountTokens() << std::endl;
//  std::cout << " lex3 size = " << lex3.CountTokens() << std::endl;
  std::cout << std::endl;

  std::cout << std::endl;
//  lex1.DumpTokens();
  lex1.DumpTokens();

}

void header() {
//  std::cout << "Yggdrasil " << Yggdrasil_VERSION_MAJOR 
//	<< "." << Yggdrasil_VERSION_MINOR;
}


