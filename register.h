#include <cstdint>
#include <vector>

#ifndef JITTERY_BOY_REGISTER_H
#define JITTERY_BOY_REGISTER_H

namespace Jittery_boy {

struct Reg_file {
  uint8_t a;
  uint8_t b;
  uint8_t c;
  uint8_t d;
  uint8_t e;
  uint8_t f;
  uint8_t h;
  uint8_t l;
};

enum class Reg_tag { a, b, c, d, e, f, h, l };

uint16_t get_af(Reg_file file);
uint16_t get_bc(Reg_file file);
uint16_t get_de(Reg_file file);
uint16_t get_hl(Reg_file file);

void set_af(Reg_file file, uint16_t value);
void set_bc(Reg_file file, uint16_t value);
void set_de(Reg_file file, uint16_t value);
void set_hl(Reg_file file, uint16_t value);

class Flags_reg {
  constexpr static uint8_t carry_position{4};
  constexpr static uint8_t half_carry_position{5};
  constexpr static uint8_t subtract_position{6};
  constexpr static uint8_t zero_position{7};

public:
  Flags_reg() :flags(8) {}

  uint8_t to_byte();
  void from_byte(uint8_t byte);
  
  bool get_carry();
  bool get_half_carry();
  bool get_subtract();
  bool get_zero();

  void set_carry(bool flag);
  void set_half_carry(bool flag);
  void set_subtract(bool flag);
  void set_zero(bool flag);
  
private:
  std::vector<bool> flags;
};

}

#endif
