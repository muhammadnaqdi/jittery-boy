#include "register.h"

#include <cstdint>

namespace Jittery_boy {

uint16_t get_af(Reg_file file) {
  return (uint16_t{file.a} << 8) | uint16_t{file.f};
}

uint16_t get_bc(Reg_file file) {
  return (uint16_t{file.b} << 8) | uint16_t{file.c};
}

uint16_t get_de(Reg_file file) {
  return (uint16_t{file.d} << 8) | uint16_t{file.e};
}

uint16_t get_hl(Reg_file file) {
  return (uint16_t{file.h} << 8) | uint16_t{file.l};
}


void set_af(Reg_file file, uint16_t value) {
  file.a = value >> 8;
  file.f = value;

  return;
}

void set_bc(Reg_file file, uint16_t value) {
  file.b = value >> 8;
  file.c = value;

  return;
}

void set_de(Reg_file file, uint16_t value) {
  file.d = value >> 8;
  file.e = value;

  return;
}

void set_hl(Reg_file file, uint16_t value) {
  file.h = value >> 8;
  file.l = value;

  return;
}

uint8_t Flags_reg::to_byte() {
  uint8_t result = 0;

  for (uint8_t i = carry_position; i <= zero_position; ++i) {
    result |= (flags[i] ? 1 : 0) << i;
  }
  
  return result;
}

void Flags_reg::from_byte(uint8_t byte) {
  for (uint8_t i = carry_position; i <= zero_position; ++i) {
    flags[i] = ((byte >> i) & 1) == 1;
  }
  
  return;
}

bool Flags_reg::get_carry() { return flags[carry_position]; }

bool Flags_reg::get_half_carry() { return flags[half_carry_position]; }

bool Flags_reg::get_subtract() { return flags[subtract_position]; }

bool Flags_reg::get_zero() { return flags[zero_position]; }

void Flags_reg::set_carry(bool flag) {
  flags[carry_position] = flag;

  return;
}

void Flags_reg::set_half_carry(bool flag) {
  flags[half_carry_position] = flag;

  return;
  }

void Flags_reg::set_subtract(bool flag) {
  flags[subtract_position] = flag;

  return;
  }

void Flags_reg::set_zero(bool flag) {
  flags[zero_position] = flag;

  return;
}

}
