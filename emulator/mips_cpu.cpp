#include "mips_cpu.h"

MipsCpu::MipsCpu(){
 
  inst_memory = new InstructionMemory  ();
  inst_dec    = new InstructionDecoder (128);
  inst_exe    = new IntegerPipeline    (32);

}

void MipsCpu::SetNewInstMemory(InstructionMemory* newInstMem){
  inst_memory = newInstMem;
}

MipsCpu::~MipsCpu(){

  delete inst_memory ;
  delete inst_dec    ;
  delete inst_exe    ;

}
void MipsCpu::CpuRun () {
  MipsInstruction inst;
  bool dec_pass;
  DecodeCluster    inst_decoded;
  ArithCluster     inst_pre_exe;
  WriteRegCluster  inst_wb;

  inst = MipsInstruction();

//IF
//One Thread fetch instruction from inst_memory
  inst = inst_memory->FetchNextInstruction();
  inst_dec->DecodePush(inst);

//ID
//the other thread decode the instruction
  inst_decoded = inst_dec->DecodeRun(dec_pass);

//RF 
  int src1;
  RegisterFile::GetInstance()->ReadRegister(inst_decoded.rs1, &src1);
  inst_pre_exe.op  = inst_decoded.op;
  inst_pre_exe.src1= src1;
  inst_pre_exe.src2= inst_decoded.imm;
  inst_pre_exe.rd  = inst_decoded.rd ;
  
//EXE
  inst_exe->PushPipeline(inst_pre_exe);
  inst_wb = inst_exe->Execute();

//WB
  if (inst_wb.vld)
    RegisterFile::GetInstance()->WriteRegister(inst_wb.rd, inst_wb.val);
  
}
