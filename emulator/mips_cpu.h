#ifndef MIPS_CPU_H
#define MIPS_CPU_H

#include "instruction_memory.h"
#include "decode_instruction.h"
#include "integer_pipeline.h"
#include "register_file.h"
class MipsCpu {
  public:
    MipsCpu ();
    ~MipsCpu();
   
    void SetNewInstMemory(InstructionMemory* newInstMem);
    void CpuRun();

  private :
    InstructionMemory*   inst_memory;
    InstructionDecoder*  inst_dec   ;
    IntegerPipeline   *  inst_exe   ;

};

#endif
