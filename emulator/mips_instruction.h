#ifndef MIPS_INSTRUCTION_H_
#define MIPS_INSTRUCTION_H_

//riscv-spec-v2.2.pdf file @page104

enum MIPS_RV32I_Opcode {
  RV32I_LUI   = 0x37,
  RV32I_AUIPC = 0x17,
  RV32I_JAL   = 0x6F,
  RV32I_JALR  = 0x67,
  RV32I_BEQ   = 0x63,
  RV32I_BNE   = 0x63,
  RV32I_BLT   = 0x63,
  RV32I_BGE   = 0x63,
  RV32I_BLTU  = 0x63,
  RV32I_BGEU  = 0x63,
  RV32I_LB    = 0x03,
  RV32I_LH    = 0x03,
  RV32I_LW    = 0x03,
  RV32I_LBU   = 0x03,
  RV32I_LHU   = 0x03,
  RV32I_SB    = 0x23,
  RV32I_SH    = 0x23,
  RV32I_SW    = 0x23,
  RV32I_ADDI  = 0x13,
  RV32I_SLTI  = 0x13,
  RV32I_SLTIU = 0x13,
  RV32I_XORI  = 0x13,
  RV32I_ORI   = 0x13,
  RV32I_ANDI  = 0x13,
  RV32I_SLLI  = 0x13,
  RV32I_SRLI  = 0x13,
  RV32I_SRAI  = 0x13,
  RV32I_ADD   = 0x33,
  RV32I_SUB   = 0x33,
  RV32I_SLL   = 0x33,
  RV32I_SLT   = 0x33,
  RV32I_SLTU  = 0x33,
  RV32I_XOR   = 0x33,
  RV32I_SRL   = 0x33,
  RV32I_SRA   = 0x33,
  RV32I_OR    = 0x33,
  RV32I_AND   = 0x33,
  RV32I_FENCE = 0x0F,
  RV32I_FENCEI= 0x0F,
  RV32I_ECALL = 0x73,
  RV32I_EBREAK= 0x73,
  RV32I_CSRRW = 0x73,
  RV32I_CSRRS = 0x73,
  RV32I_CSRRC = 0x73,
  RV32I_CSRRWI= 0x73,
  RV32I_CSRRSI= 0x73,
  RV32I_CSRRCI= 0x73
};
enum MIPS_RV32I_type {
  R_type = 0,
  I_type = 1,
  S_type = 2,
  B_type = 3,
  U_type = 4,
  J_type = 5
};
enum I_type_funct3{
  FUNCT3_ADDI = 0x0,
  FUNCT3_SLTI = 0x2,
  FUNCT3_SLTIU= 0x3,
  FUNCT3_XORI = 0x4,
  FUNCT3_ORI  = 0x6,
  FUNCT3_ANDI = 0x7
};
enum R_type_funct3 {
  FUNCT3_ADD  = 0x0,
  FUNCT3_SLL  = 0x1,
  FUNCT3_SLT  = 0x2,
  FUNCT3_SLTU = 0x3,
  FUNCT3_XOR  = 0x4,
  FUNCT3_SRL  = 0x5,
  FUNCT3_OR   = 0x6,
  FUNCT3_AND  = 0x7
};

typedef unsigned int u32bit;

typedef struct {
  u32bit      opcode   : 7,  // bit[6 :0 ]  => Instruction Code
              rd       : 5,  // bit[11:7 ]  => Register Destination
              funct3   : 3,  // bit[14:12]  => Function
              rs1      : 5,  // bit[19:15]  => Register Source1
              rs2      : 5,  // bit[24:20]  => Register Source2
              funct7   : 7;  // bit[31:25]  => Function
}R_type_instruction_field32;

typedef struct {
  u32bit      opcode   : 7,  // bit[6 :0 ]  => Instruction Code
              rd       : 5,  // bit[11:7 ]  => Register Destination
              funct3   : 3,  // bit[14:12]  => Function
              rs1      : 5,  // bit[19:15]  => Register Source1
              imm      : 12; // bit[31:20]  => Function
}I_type_instruction_field32;

typedef struct {
  u32bit      opcode   : 7,  // bit[6 :0 ]  => Instruction Code
              imm4_0   : 5,  // bit[11:7 ]  => Register Destination
              funct3   : 3,  // bit[14:12]  => Function
              rs1      : 5,  // bit[19:15]  => Register Source1
              rs2      : 5,  // bit[24:20]  => Register Source2
              imm11_5  : 7;  // bit[31:20]  => Function
}S_type_instruction_field32;

typedef struct {
  u32bit      opcode   : 7,  // bit[6 :0 ]  => Instruction Code
              imm4_1   : 5,  // bit[11:7 ]  => Register Destination
              funct3   : 3,  // bit[14:12]  => Function
              rs1      : 5,  // bit[19:15]  => Register Source1
              rs2      : 5,  // bit[24:20]  => Register Source2
              imm10_5  : 7;  // bit[31:20]  => Function
}B_type_instruction_field32;

typedef struct {
  u32bit      opcode   : 7 ,  // bit[6 :0 ]  => Instruction Code
              rd       : 5 ,  // bit[11:7 ]  => Register Destination
              imm31_12 :20 ;  // bit[31:20]  => Immedidate
}U_type_instruction_field32;

typedef struct {
  u32bit      opcode   : 7 ,  // bit[6 :0 ]  => Instruction Code
              rd       : 5 ,  // bit[11:7 ]  => Register Destination
              imm31_12 :20 ;  // bit[31:20]  => Immedidate
}J_type_instruction_field32;

class MipsInstruction {
public:
  MipsInstruction (MIPS_RV32I_type type_=R_type);
//  MipsInstruction (const MipsInstruction& rhs);
  ~MipsInstruction();
//  virtual void run_instruction() ;
  virtual MIPS_RV32I_type& GetType();
  

  MipsInstruction & operator= (const MipsInstruction& rhs);
  //Overload function to set a MIPS instruction.
  //Change to different name
  void CreateMipsInstR(MIPS_RV32I_Opcode opcode, int rd    , int funct3, int rs1, int rs2, int funct7);//R_type
  void CreateMipsInstI(MIPS_RV32I_Opcode opcode, int rd    , int funct3, int rs1, int imm);//I_type
  void CreateMipsInstS(MIPS_RV32I_Opcode opcode, int imm4_0, int funct3, int rs1, int rs2, int imm11_5);
  void CreateMipsInstB(MIPS_RV32I_Opcode opcode, int imm4_1, int funct3, int rs1, int rs2, int imm11_5);
  void CreateMipsInstU(MIPS_RV32I_Opcode opcode, int rd    , int imm31_12);
  void CreateMipsInstJ(MIPS_RV32I_Opcode opcode, int rd    , int imm20_1 );
  
   

  union {
    R_type_instruction_field32 r_type;
    I_type_instruction_field32 i_type;
    S_type_instruction_field32 s_type;
    B_type_instruction_field32 b_type;
    U_type_instruction_field32 u_type;
    J_type_instruction_field32 j_type;
  } inst_;
private:
  MIPS_RV32I_type inst_type_;

};



#endif
