#ifndef INSTRUCTION_MEMORY_H
#define INSTRUCTION_MEMORY_H

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <memory.h>
#include <string>
using namespace std;
class MipsInstruction;

class InstructionMemory{
  public  :
    InstructionMemory();
    ~InstructionMemory();
    void LoadMipsInstruction(const char* binary_file);

    MipsInstruction& FetchNextInstruction();
    void             UpdatePC();
    //brach or jump instruction will call the function to update the PC
    void SetNextPC(bool& is_bj_inst, int PC_new_value);

  private :
    int               PC             ;
    int               MAX_SIZE       ; //Max instruction memory size
    MipsInstruction*  data           ;

    int               binary_string_to_int(string &bin_str);
};


#endif
