#include "processor.h"

#include <iostream>

using namespace Jittery_boy;
using namespace std;

int main() {
  Instruct i{Instruct_tag::add, Reg_tag::a};

  Processor cpu;

  cpu.execute(i);
  cpu.execute(i);
  cpu.execute(i);
  cpu.execute(i);
   
  return 0;
}
