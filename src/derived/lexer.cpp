
#line 1 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
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


#line 88 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"


// had ragel command %%write data here previously but I want the data members to 
// part of the Lexer class definiation, so i declared
// static const int lexer_start = 1
// it the lexer header   

#line 37 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
static const char _lexer_actions[] = {
	0, 1, 0, 1, 1, 1, 2, 1, 
	3, 1, 4, 1, 5, 1, 6, 1, 
	7, 1, 8, 1, 9, 1, 10
};

static const char _lexer_key_offsets[] = {
	0, 0, 12
};

static const char _lexer_trans_keys[] = {
	32, 40, 41, 42, 43, 45, 47, 59, 
	9, 13, 48, 57, 48, 57, 0
};

static const char _lexer_single_lengths[] = {
	0, 8, 0
};

static const char _lexer_range_lengths[] = {
	0, 2, 1
};

static const char _lexer_index_offsets[] = {
	0, 0, 11
};

static const char _lexer_trans_targs[] = {
	1, 1, 1, 1, 1, 1, 1, 1, 
	1, 2, 0, 2, 1, 1, 0
};

static const char _lexer_trans_actions[] = {
	19, 9, 11, 13, 5, 7, 15, 17, 
	19, 0, 0, 0, 21, 21, 0
};

static const char _lexer_to_state_actions[] = {
	0, 1, 0
};

static const char _lexer_from_state_actions[] = {
	0, 3, 0
};

static const char _lexer_eof_trans[] = {
	0, 0, 14
};

static const int lexer_start = 1;
static const int lexer_first_final = 1;
static const int lexer_error = 0;

static const int lexer_en_main = 1;


#line 95 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"


Lexer::~Lexer() {
  std::cout << "Lexer destroyed." << std::endl;
  //ParseFree(lparser, free);
}

Lexer::Lexer(const char* data, std::size_t len): p(data), pe(data+len), eof(pe) {

  //lparser = ParserAlloc(malloc);
  
  
#line 107 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
	{
	cs = lexer_start;
	ts = 0;
	te = 0;
	act = 0;
	}

#line 107 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"

}

void Lexer::Execute() { 
  
#line 121 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
	{
	int _klen;
	unsigned int _trans;
	const char *_acts;
	unsigned int _nacts;
	const char *_keys;

	if ( p == pe )
		goto _test_eof;
	if ( cs == 0 )
		goto _out;
_resume:
	_acts = _lexer_actions + _lexer_from_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 1:
#line 1 "NONE"
	{ts = p;}
	break;
#line 142 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
		}
	}

	_keys = _lexer_trans_keys + _lexer_key_offsets[cs];
	_trans = _lexer_index_offsets[cs];

	_klen = _lexer_single_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + _klen - 1;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + ((_upper-_lower) >> 1);
			if ( (*p) < *_mid )
				_upper = _mid - 1;
			else if ( (*p) > *_mid )
				_lower = _mid + 1;
			else {
				_trans += (unsigned int)(_mid - _keys);
				goto _match;
			}
		}
		_keys += _klen;
		_trans += _klen;
	}

	_klen = _lexer_range_lengths[cs];
	if ( _klen > 0 ) {
		const char *_lower = _keys;
		const char *_mid;
		const char *_upper = _keys + (_klen<<1) - 2;
		while (1) {
			if ( _upper < _lower )
				break;

			_mid = _lower + (((_upper-_lower) >> 1) & ~1);
			if ( (*p) < _mid[0] )
				_upper = _mid - 2;
			else if ( (*p) > _mid[1] )
				_lower = _mid + 2;
			else {
				_trans += (unsigned int)((_mid - _keys)>>1);
				goto _match;
			}
		}
		_trans += _klen;
	}

_match:
_eof_trans:
	cs = _lexer_trans_targs[_trans];

	if ( _lexer_trans_actions[_trans] == 0 )
		goto _again;

	_acts = _lexer_actions + _lexer_trans_actions[_trans];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 )
	{
		switch ( *_acts++ )
		{
	case 2:
#line 33 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Plus, getTokenData(ts, te));
}}
	break;
	case 3:
#line 37 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Minus, getTokenData(ts, te));
}}
	break;
	case 4:
#line 49 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::OpenP, getTokenData(ts, te));
}}
	break;
	case 5:
#line 53 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::CloseP, getTokenData(ts, te));
}}
	break;
	case 6:
#line 41 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
    addToken(TokenType::Times, getTokenData(ts, te));
}}
	break;
	case 7:
#line 45 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Divide, getTokenData(ts, te));
}}
	break;
	case 8:
#line 29 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  addToken(TokenType::Semi, getTokenData(ts, te));
}}
	break;
	case 9:
#line 62 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p+1;{
  //++line_col;
}}
	break;
	case 10:
#line 57 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
	{te = p;p--;{
  addToken(TokenType::Number, getTokenData(ts, te));
  
}}
	break;
#line 262 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
		}
	}

_again:
	_acts = _lexer_actions + _lexer_to_state_actions[cs];
	_nacts = (unsigned int) *_acts++;
	while ( _nacts-- > 0 ) {
		switch ( *_acts++ ) {
	case 0:
#line 1 "NONE"
	{ts = 0;}
	break;
#line 275 "/home/nfa/development/Yggdrasil/src/derived/lexer.cpp"
		}
	}

	if ( cs == 0 )
		goto _out;
	if ( ++p != pe )
		goto _resume;
	_test_eof: {}
	if ( p == eof )
	{
	if ( _lexer_eof_trans[cs] > 0 ) {
		_trans = _lexer_eof_trans[cs] - 1;
		goto _eof_trans;
	}
	}

	_out: {}
	}

#line 112 "/home/nfa/development/Yggdrasil/src/derived/../LPC/Grammar/lexer.rl"
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
