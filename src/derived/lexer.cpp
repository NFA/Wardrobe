
#line 1 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
#include <iostream>
#include <cstring>
#include <memory>
#include <iomanip>
#include "lexer.h"
#include "token.h"
#include "../LPC/input.h"

namespace LPC {
namespace Grammar {


char *getTokenData(const char* start, const char* end) {
  char *data = new char[end - start + 1];
  strncpy(data, start, end - start);
  *(data + (end - start)) = '\0';
  return data;

}


#line 138 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"


// had ragel command %%write data here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header    

#line 33 "/Users/NFA/development/yggdrasil/src/derived/lexer.cpp"
static const int lexer_start = 9;
static const int lexer_first_final = 9;
static const int lexer_error = 0;

static const int lexer_en_main = 9;


#line 145 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"

Lexer::Lexer(Input& input) : p(input.GetBuffer()), pe(input.GetBufferEnd()), eof(pe) {
  line_nr = 0;
  offset = 0;
  
#line 47 "/Users/NFA/development/yggdrasil/src/derived/lexer.cpp"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 150 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
}

void Lexer::LexAllTokens() {
  TokenType stop;
  do {
    stop = LexToken();
  } while (p != pe);
}


TokenType Lexer::LexToken() { 
  TokenType ret = TokenType::END;
  
#line 69 "/Users/NFA/development/yggdrasil/src/derived/lexer.cpp"
	{
	if ( p == pe )
		goto _test_eof;
	switch ( cs )
	{
tr0:
#line 50 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{{p = ((te))-1;}{ 
    ret = TokenType::Identifier;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr8:
#line 60 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Float;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr9:
#line 25 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{
  switch (*ts) {
    case ' ':
      ++offset;
      break;
    case '\t':
      ++line_nr;
      break;
    case '\n':
      ++line_nr;
      offset = 0;
      break;
    case '\r':
      // nop, only handle CRLF and LF newlines
      break;
  }
}}
	goto st9;
tr11:
#line 80 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::OpenParen;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr12:
#line 85 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::CloseParen;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr13:
#line 123 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Mult;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr14:
#line 113 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Add;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr15:
#line 105 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Comma;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr16:
#line 118 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Sub;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr17:
#line 128 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Div;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr19:
#line 100 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Semi;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr20:
#line 67 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::Assign;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr24:
#line 90 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::OpenBrace;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr25:
#line 95 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p+1;{ 
    ret = TokenType::CloseBrace;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr26:
#line 55 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p;p--;{ 
    ret = TokenType::Integer;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
tr27:
#line 50 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
	{te = p;p--;{ 
    ret = TokenType::Identifier;
    addToken(ret);
    {p++; cs = 9; goto _out;}
  }}
	goto st9;
st9:
#line 1 "NONE"
	{ts = 0;}
	if ( ++p == pe )
		goto _test_eof9;
case 9:
#line 1 "NONE"
	{ts = p;}
#line 223 "/Users/NFA/development/yggdrasil/src/derived/lexer.cpp"
	switch( (*p) ) {
		case 32: goto tr9;
		case 40: goto tr11;
		case 41: goto tr12;
		case 42: goto tr13;
		case 43: goto tr14;
		case 44: goto tr15;
		case 45: goto tr16;
		case 47: goto tr17;
		case 59: goto tr19;
		case 61: goto tr20;
		case 95: goto st11;
		case 100: goto st12;
		case 114: goto st17;
		case 123: goto tr24;
		case 125: goto tr25;
	}
	if ( (*p) < 48 ) {
		if ( 9 <= (*p) && (*p) <= 13 )
			goto tr9;
	} else if ( (*p) > 57 ) {
		if ( (*p) > 90 ) {
			if ( 97 <= (*p) && (*p) <= 122 )
				goto st11;
		} else if ( (*p) >= 65 )
			goto st11;
	} else
		goto st10;
	goto st0;
st0:
cs = 0;
	goto _out;
st10:
	if ( ++p == pe )
		goto _test_eof10;
case 10:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st10;
	goto tr26;
st11:
	if ( ++p == pe )
		goto _test_eof11;
case 11:
	if ( (*p) == 95 )
		goto st11;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st12:
	if ( ++p == pe )
		goto _test_eof12;
case 12:
	switch( (*p) ) {
		case 95: goto st11;
		case 105: goto st13;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st13:
	if ( ++p == pe )
		goto _test_eof13;
case 13:
	switch( (*p) ) {
		case 95: goto st11;
		case 103: goto st14;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st14:
	if ( ++p == pe )
		goto _test_eof14;
case 14:
	switch( (*p) ) {
		case 95: goto st11;
		case 105: goto st15;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st15:
	if ( ++p == pe )
		goto _test_eof15;
case 15:
	switch( (*p) ) {
		case 95: goto st11;
		case 116: goto tr31;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
tr31:
#line 1 "NONE"
	{te = p+1;}
	goto st16;
st16:
	if ( ++p == pe )
		goto _test_eof16;
case 16:
#line 354 "/Users/NFA/development/yggdrasil/src/derived/lexer.cpp"
	switch( (*p) ) {
		case 43: goto st1;
		case 95: goto st11;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st1:
	if ( ++p == pe )
		goto _test_eof1;
case 1:
	goto st2;
st2:
	if ( ++p == pe )
		goto _test_eof2;
case 2:
	if ( (*p) == 46 )
		goto st3;
	goto tr0;
st3:
	if ( ++p == pe )
		goto _test_eof3;
case 3:
	if ( (*p) == 100 )
		goto st4;
	goto tr0;
st4:
	if ( ++p == pe )
		goto _test_eof4;
case 4:
	if ( (*p) == 105 )
		goto st5;
	goto tr0;
st5:
	if ( ++p == pe )
		goto _test_eof5;
case 5:
	if ( (*p) == 103 )
		goto st6;
	goto tr0;
st6:
	if ( ++p == pe )
		goto _test_eof6;
case 6:
	if ( (*p) == 105 )
		goto st7;
	goto tr0;
st7:
	if ( ++p == pe )
		goto _test_eof7;
case 7:
	if ( (*p) == 116 )
		goto st8;
	goto tr0;
st8:
	if ( ++p == pe )
		goto _test_eof8;
case 8:
	if ( (*p) == 43 )
		goto tr8;
	goto tr0;
st17:
	if ( ++p == pe )
		goto _test_eof17;
case 17:
	switch( (*p) ) {
		case 95: goto st11;
		case 101: goto st18;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st18:
	if ( ++p == pe )
		goto _test_eof18;
case 18:
	switch( (*p) ) {
		case 95: goto st11;
		case 116: goto st19;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st19:
	if ( ++p == pe )
		goto _test_eof19;
case 19:
	switch( (*p) ) {
		case 95: goto st11;
		case 117: goto st20;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st20:
	if ( ++p == pe )
		goto _test_eof20;
case 20:
	switch( (*p) ) {
		case 95: goto st11;
		case 114: goto st21;
	}
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
st21:
	if ( ++p == pe )
		goto _test_eof21;
case 21:
	if ( (*p) == 95 )
		goto st11;
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st11;
	} else if ( (*p) > 90 ) {
		if ( 97 <= (*p) && (*p) <= 122 )
			goto st11;
	} else
		goto st11;
	goto tr27;
	}
	_test_eof9: cs = 9; goto _test_eof; 
	_test_eof10: cs = 10; goto _test_eof; 
	_test_eof11: cs = 11; goto _test_eof; 
	_test_eof12: cs = 12; goto _test_eof; 
	_test_eof13: cs = 13; goto _test_eof; 
	_test_eof14: cs = 14; goto _test_eof; 
	_test_eof15: cs = 15; goto _test_eof; 
	_test_eof16: cs = 16; goto _test_eof; 
	_test_eof1: cs = 1; goto _test_eof; 
	_test_eof2: cs = 2; goto _test_eof; 
	_test_eof3: cs = 3; goto _test_eof; 
	_test_eof4: cs = 4; goto _test_eof; 
	_test_eof5: cs = 5; goto _test_eof; 
	_test_eof6: cs = 6; goto _test_eof; 
	_test_eof7: cs = 7; goto _test_eof; 
	_test_eof8: cs = 8; goto _test_eof; 
	_test_eof17: cs = 17; goto _test_eof; 
	_test_eof18: cs = 18; goto _test_eof; 
	_test_eof19: cs = 19; goto _test_eof; 
	_test_eof20: cs = 20; goto _test_eof; 
	_test_eof21: cs = 21; goto _test_eof; 

	_test_eof: {}
	if ( p == eof )
	{
	switch ( cs ) {
	case 10: goto tr26;
	case 11: goto tr27;
	case 12: goto tr27;
	case 13: goto tr27;
	case 14: goto tr27;
	case 15: goto tr27;
	case 16: goto tr27;
	case 1: goto tr0;
	case 2: goto tr0;
	case 3: goto tr0;
	case 4: goto tr0;
	case 5: goto tr0;
	case 6: goto tr0;
	case 7: goto tr0;
	case 8: goto tr0;
	case 17: goto tr27;
	case 18: goto tr27;
	case 19: goto tr27;
	case 20: goto tr27;
	case 21: goto tr27;
	}
	}

	_out: {}
	}

#line 163 "/Users/NFA/development/yggdrasil/src/LPC/Grammar/lexer.rl"
  return ret;
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


void Lexer::addToken(TokenType token_type) {
  tokens.push_back(std::unique_ptr<Token>(
    new Token(token_type, getTokenData(ts, te), line_nr, offset)
  ));
  advanceLocation(ts, te);
}

void Lexer::advanceLocation(const char *ts, const char *te) {
  offset += (unsigned short)(te - ts);
}


} /* namespace Grammar */
} /* namespace LPC */
