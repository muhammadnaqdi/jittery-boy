#include "register.h"
#include "instruction.h"

#ifndef JITTERY_BOY_PROCESSOR_H
#define JITTERY_BOY_PROCESSOR_H

namespace Jittery_boy {

class Processor {
public:
  class Invalid {};
  
  Processor() {}
  void execute(Instruct inst);
  
private:
  Reg_file file;
  Flags_reg flags;
  void inst_add(Reg_tag target);
  void add(uint8_t value) {
  uint16_t result = uint16_t{file.a} + value; 
  file.a = uint8_t(result);
  //TODO: handle flags
  }
};
  
}

#endif
