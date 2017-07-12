#include "mips_instruction.h"
MipsInstruction::MipsInstruction(MIPS_RV32I_type type_) :inst_type_(type_) {

}
MipsInstruction::~MipsInstruction() {

}
MipsInstruction& MipsInstruction::operator = (const MipsInstruction& rhs) {
  if (this != &rhs) {
    this->inst_type_ = rhs.inst_type_;
    this->inst_      = rhs.inst_;
  }
  return *this;
}

void MipsInstruction::CreateMipsInstI(MIPS_RV32I_Opcode opcode, int rd    , int funct3, int rs1, int imm) {
  inst_.i_type.opcode   = opcode;
  inst_.i_type.rd       = rd    ;
  inst_.i_type.funct3   = funct3;
  inst_.i_type.rs1      = rs1   ;
  inst_.i_type.imm      = imm   ;
}
MIPS_RV32I_type& MipsInstruction::GetType() {
  return inst_type_;
}
