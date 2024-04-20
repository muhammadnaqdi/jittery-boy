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
  }
}

void Processor::inst_add(Reg_tag target) {
  switch (target) {
  case (Reg_tag::a):
    add(file.a);
    break;
  case (Reg_tag::b):
    add(file.b);
    break;
  case (Reg_tag::c):
    add(file.c);
    break;
  case (Reg_tag::d):
    add(file.d);
    break;
  case (Reg_tag::e):
    add(file.e);
    break;
  case (Reg_tag::h):
    add(file.h);
    break;
  case (Reg_tag::l):
    add(file.l);
    break;
  default:
    throw Invalid{};
    break;
  }

  std::cout<<"add: A = "<<int{file.a}<<'\n';
}

}
