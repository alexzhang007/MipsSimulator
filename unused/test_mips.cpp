#include "mips_instruction.h"
#include <iostream>
using namespace std;

int main (){

  MipsInstruction inst = MipsInstruction(R_type);
  inst.CreateMipsInstI(RV32I_ADDI, 0,  0, 1, 123);
  I_type_instruction_field32 ii= inst.inst_.i_type;
  cout<<"Immeidate="<<ii.imm<<endl;
  return 0;
}
