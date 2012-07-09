
#line 1 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
#include <iostream>
#include <cstring>
#include <memory>
#include <iomanip>
#include "lexer.h"
#include "token.h"

namespace LPC {
namespace Grammar {


char *getTokenData(const char* start, const char* end) {
  char *data = new char[end - start + 1];
  strncpy(data, start, end - start);
  *(data + (end - start)) = '\0';
  return data;

}


#line 97 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"


// had ragel command %%write data here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header    

#line 32 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
static const int lexer_start = 1;
static const int lexer_first_final = 1;
static const int lexer_error = 0;

static const int lexer_en_main = 1;


#line 104 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"

Lexer::Lexer(Input& input) : p(input.GetBuffer()), pe(input.GetBufferEnd()), eof(pe) {
  current_line = 0;
  current_column = 0;
  
#line 46 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 109 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
}


void Lexer::Lex() { 
  
#line 60 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 57 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  switch (*ts) {
    case ' ':
      ++current_column;
      break;
    case '\t':
      ++current_line;
      break;
    case '\n':
      ++current_line;
      current_column = 0;
      break;
    case '\r':
      // nop, only handle CRLF and LF newlines
      break;
  }
}}
	goto st1;
tr2:
#line 44 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::OpenP, ts, te);
}}
	goto st1;
tr3:
#line 48 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::CloseP, ts, te);
}}
	goto st1;
tr4:
#line 36 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Times, ts, te);
}}
	goto st1;
tr5:
#line 28 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Plus, ts, te);
}}
	goto st1;
tr6:
#line 32 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Minus, ts, te);
}}
	goto st1;
tr7:
#line 40 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Divide, ts, te);
}}
	goto st1;
tr9:
#line 24 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Semi, ts, te);
}}
	goto st1;
tr10:
#line 52 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p;p--;{
  addToken(TokenType::Number, ts, te);
  
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
#line 143 "/Users/NFA/development/yggdrasil/derived/lexer.cpp"
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

#line 114 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
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

int Lexer::CountTokens() const {
  return tokens.size();
}


void Lexer::addToken(TokenType token_type, const char* ts, const char* te) {
  tokens.push_back(std::unique_ptr<Token>(
    new Token(token_type, getTokenData(ts, te), current_line, current_column)
  ));
  advanceLocation(ts, te);
}

void Lexer::advanceLocation(const char *ts, const char *te) {
  current_column += (unsigned short)(te - ts);
}


} /* namespace Grammar */
} /* namespace LPC */
