#ifndef DECODE_INSTRUCTION_H
#define DECODE_INSTRUCTION_H

#include "mips_instruction.h"
#include "integer_pipeline.h"
#include <queue>
typedef struct DecodeCluster {
  ArithOp op    ;
  int     rs1   ;
  int     rs2   ;
  int     imm   ; 
  int     funct7;
  int     funct3;
  int     rd    ;
  int     shamt ;
}DecodeCluster;
class InstructionDecoder{
public:
  InstructionDecoder(int depth);
  ~InstructionDecoder();
  bool         DecodePush(MipsInstruction& inst);
  DecodeCluster DecodeRun(bool& pass);

private:
  int depth_;
  queue<MipsInstruction> fifo; 

};


#endif
