#include <iostream>
using namespace std;
#include "mips_instruction.h"
#include "instruction_memory.h"

int main() {
  InstructionMemory *inst_mem;
  inst_mem = new InstructionMemory;
  inst_mem->LoadMipsInstruction("add_asm.mips");
  
  


  return 0;
}
