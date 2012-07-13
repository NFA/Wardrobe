#include <iostream>
#include <chrono>
//#include "config/wardrobe.h"
#include "LPC/input.h"
#include "LPC/Grammar/lexer.h"

void header();

int main() {
  header();
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
  std::vector<LPC::Input*> data;
  long long tokens = 0;
  long long iterations = 0;
  int seconds = 10;
  
  std::chrono::steady_clock::time_point tend = std::chrono::steady_clock::now()
                                               + std::chrono::seconds(seconds);
  
  std::cout << "\nStarting lexing (" << seconds << " seconds) ..." << std::endl;
  while (std::chrono::steady_clock::now()  < tend) {
    LPC::Input *input = new LPC::Input(data1);
    LPC::Grammar::Lexer *lexer = new LPC::Grammar::Lexer(*input);
    lexer->LexAllTokens();
    tokens += lexer->CountTokens();
    delete lexer;
    delete input;
    ++iterations;
  }
    
    
//  LPC::Input input1(data1);
//  LPC::Input input2(data2);
//  LPC::Input input3(data3);
   

//  LPC::Grammar::Lexer lex1(input1);
//  LPC::Grammar::Lexer lex2(input2);
//  LPC::Grammar::Lexer lex3(input3);
  
//  lex1.Lex();
//  lex2.Lex();
//  lex3.Lex();
 
//  std::cout << " lex1 size = " << lex1.CountTokens() << std::endl;
//  std::cout << " lex2 size = " << lex2.CountTokens() << std::endl;
//  std::cout << " lex3 size = " << lex3.CountTokens() << std::endl;
  std::cout << std::endl;
  
  long long bytes_per_sec = (strlen(data1)*iterations)/seconds;
  double megabytes_per_sec = ((double)bytes_per_sec)/1024/1024;

  std::cout << "Done." << std::endl;
  std::cout << iterations << " iterations. " << std::endl;
  std::cout << tokens/seconds << " tokens/sec." << std::endl;
  std::cout << megabytes_per_sec << " Mb/sec." << std::endl;
//  lex1.DumpTokens();
//  lex1.DumpTokens();

}

void header() {
  std::cout << "Wardrobe 0.1.0\nCopyright 2012, Fredrik Nyström." << std::endl;
  /*
  std::cout << "Wardrobe " << wardrobe_VERSION_MAJOR 
	    << "."         << wardrobe_VERSION_MINOR
            << "."         << wardrobe_VERSION_PATCH
            << std::endl;
*/
}


