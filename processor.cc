#include "processor.h"
#include "register.h"
#include "instruction.h"

#include <cstdint>
#include <iostream>

namespace Jittery_boy {
  
void Processor::execute(Instruct inst) {
  switch (inst.instruct) {
  case (Instruct_tag::add):
    inst_add(inst.target);
    break;
  case (Instruct_tag::adc):
    inst_adc(inst.target);
    break;
  default:
    std::cerr<<"Bad instructure!\n";
    break;
  }

  return;
}

void Processor::inst_add(Reg_tag target) {
  switch (target) {
  case (Reg_tag::a):
    add(file.a, false);
    break;
  case (Reg_tag::b):
    add(file.b, false);
    break;
  case (Reg_tag::c):
    add(file.c, false);
    break;
  case (Reg_tag::d):
    add(file.d, false);
    break;
  case (Reg_tag::e):
    add(file.e, false);
    break;
  case (Reg_tag::h):
    add(file.h, false);
    break;
  case (Reg_tag::l):
    add(file.l, false);
    break;
  default:
    std::cerr<<"Bad target!\n";
    break;
  }

  return;
}

void Processor::inst_adc(Reg_tag target) {
  switch (target) {
  case (Reg_tag::a):
    add(file.a, flags.get_carry());
    break;
  case (Reg_tag::b):
    add(file.b, flags.get_carry());
    break;
  case (Reg_tag::c):
    add(file.c, flags.get_carry());
    break;
  case (Reg_tag::d):
    add(file.d, flags.get_carry());
    break;
  case (Reg_tag::e):
    add(file.e, flags.get_carry());
    break;
  case (Reg_tag::h):
    add(file.h, flags.get_carry());
    break;
  case (Reg_tag::l):
    add(file.l, flags.get_carry());
    break;
  default:
    std::cerr<<"Bad target!\n";
    break;
  }

  return;
}
  
void Processor::add(uint8_t value, bool carry) {
  uint16_t result = uint16_t{file.a} + uint16_t{value} + (carry ? 1 : 0);

  file.a = uint8_t(result);
  
  flags.set_carry(result > 0x00FF);
  flags.set_half_carry((file.a & 0x0F) + (value & 0x0F) + (carry ? 1 : 0) > 0x0F);
  flags.set_subtract(false);
  flags.set_zero(file.a == 0);

  return;
}

// void Processor::sub(uint8_t value, bool carry) {
//   uint16_t result = uint16_t{file.a} - uint16_t{value} - (carry ? 1 : 0);

//   file.a = uint8_t(result);
  
  
//   return;
// }
  
}
