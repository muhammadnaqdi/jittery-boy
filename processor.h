#include "register.h"
#include "instruction.h"

#include <cstdint>

#ifndef JITTERY_BOY_PROCESSOR_H
#define JITTERY_BOY_PROCESSOR_H

namespace Jittery_boy {

class Processor {
public:  
  Processor() {}
  void execute(Instruct inst);
  
private:
  Reg_file file;
  Flags_reg flags;

  void inst_add(Reg_tag target);
  void inst_adc(Reg_tag target);
  // void inst_sub(Reg_tag target);

  void add(uint8_t value, bool carry);
  // void sub(uint8_t value, bool carry);
};
  
}

#endif
