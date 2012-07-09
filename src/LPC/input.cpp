#include <fstream>
#include <string>
#include <cstring>
#include "input.h"


namespace LPC {

Input::Input(std::string str) {
  sz = str.size();
  buffer = new char[sz + 1];
  std::strncpy(buffer, str.c_str(), sz);
}

Input::Input(std::ifstream& file) {
  // The lexer deals with ws characters
  file.unsetf(std::ios_base::skipws);
  file.seekg(0, std::ios_base::end);
  sz = file.tellg();
  file.seekg(0, std::ios_base::beg);
  
  buffer = new char[sz +1];
  file.read((char*) &buffer[0], sz);
}

Input::~Input() {
  delete[] buffer;
}

char* Input::GetBuffer() const {
  return buffer;
}
char* Input::GetBufferEnd() const {
  return buffer + sz;
}

size_t Input::GetBufferSize() const {
  return sz;
}

} /* namespace LPC */