#ifndef Yggdrasil_input_h
#define Yggdrasil_input_h
#include <string>
#include <fstream>

namespace LPC {

class Input {
public:
  Input(std::string);
  Input(std::ifstream&);
  ~Input();
  char* GetBuffer() const;
  char* GetBufferEnd() const;
  size_t GetBufferSize() const;
private:
  char* buffer;
  size_t sz;
};

} /* namespace LPC */


#endif
