
#line 1 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
#include <iostream>
#include <cstring>
#include <memory>
#include <iomanip>
#include "lexer.h"
#include "token.h"

namespace LPC {
namespace Grammar {

/*
char *getTokenData(const char* start, const char* end) {
  char *data = new char[end - start + 1];
  strncpy(data, start, end - start);
  *(data + (end - start)) = '\0';
  return data;

}
*/

std::string getTokenData(const char* start, const char* end) {
  return std::string(start).substr(0, end - start);
}


#line 88 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"


// had ragel command 'write data' here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header   
    


Lexer::~Lexer() {
  std::cout << "Lexer destroyed." << std::endl;
  //ParseFree(lparser, free);
}

Lexer::Lexer(const char* data, std::size_t len): p(data), pe(data+len), eof(pe) {

  //lparser = ParserAlloc(malloc);
  
  
#line 49 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 107 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"

}

void Lexer::Execute() { 
  
#line 63 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 62 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  //++line_col;
}}
	goto st1;
tr2:
#line 49 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::OpenP, getTokenData(ts, te));
}}
	goto st1;
tr3:
#line 53 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::CloseP, getTokenData(ts, te));
}}
	goto st1;
tr4:
#line 41 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
    addToken(TokenType::Times, getTokenData(ts, te));
}}
	goto st1;
tr5:
#line 33 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Plus, getTokenData(ts, te));
}}
	goto st1;
tr6:
#line 37 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Minus, getTokenData(ts, te));
}}
	goto st1;
tr7:
#line 45 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Divide, getTokenData(ts, te));
}}
	goto st1;
tr9:
#line 29 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Semi, getTokenData(ts, te));
}}
	goto st1;
tr10:
#line 57 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
	{te = p;p--;{
  addToken(TokenType::Number, getTokenData(ts, te));
  
}}
	goto st1;
st1:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof1;
case 1:
#line 1 "NONE"
	{ts = p;}
#line 132 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
	switch( (*p) ) {
		case 32: goto tr0;
		case 40: goto tr2;
		case 41: goto tr3;
		case 42: goto tr4;
		case 43: goto tr5;
		case 45: goto tr6;
		case 47: goto tr7;
		case 59: goto tr9;
	}
	if ( (*p) > 13 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st2;
	} else if ( (*p) >= 9 )
		goto tr0;
	goto st0;
st0:
cs = 0;
	goto _out;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st2;
	goto tr10;
	}
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 2: goto tr10;
	}
	}

	_out: {}
	}

#line 112 "/Users/NFA/development/yggdrasil/src/grammar/lexer.rl"
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


void Lexer::addToken(TokenType token_type, std::string token_data) {
  tokens.push_back(std::unique_ptr<Token>(new Token(token_type, token_data)));
}

} /* namespace Grammar */
} /* namespace LPC */
