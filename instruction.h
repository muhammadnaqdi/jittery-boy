#include "register.h"

#ifndef JITTERY_BOY_INSTRUCTION_H
#define JITTERY_BOY_INSTRUCTION_H

namespace Jittery_boy {

  enum class Instruct_tag { add, adc, sub };

  struct Instruct {
    Instruct_tag instruct;
    Reg_tag target;
  };
  
}

#endif
