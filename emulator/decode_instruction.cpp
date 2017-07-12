#include "decode_instruction.h"
InstructionDecoder::InstructionDecoder(int depth): depth_(depth){

}
InstructionDecoder::~InstructionDecoder(){
  for (int i=0; i<depth_; i++) {
    fifo.pop();
  }
}
bool         InstructionDecoder::DecodePush(MipsInstruction& inst){
  if (fifo.size() < depth_)
    fifo.push(inst);
  else 
    return false;

  return true;
}

DecodeCluster InstructionDecoder::DecodeRun(bool& pass){
  DecodeCluster ret;
  if (fifo.size() > 0) {
    MipsInstruction next_inst = fifo.front();
    fifo.pop();
    switch (next_inst.GetType()) {

      case I_type : {
                      I_type_instruction_field32 i_inst = next_inst.inst_.i_type;
                      if (i_inst.opcode == RV32I_ADDI) {
                          switch (i_inst.funct3) {
                            case FUNCT3_ADDI : { //ADDI
                                         ret.op  = INT_ADDI  ; 
                                         ret.rd  = i_inst.rd ;
                                         ret.rs1 = i_inst.rs1;
                                         ret.imm = i_inst.imm;
                                         break;
                                       }
                          }
                      }
                      break;
                    }
      case R_type : { 
                       R_type_instruction_field32 r_inst = next_inst.inst_.r_type;
                       if (r_inst.opcode == RV32I_ADD ) {
                           switch (r_inst.funct3) {
                             case 0x0 : { //ADD or SUB
                                          ret.op = r_inst.funct7 ==0 ? INT_ADD  :INT_SUB ;
                                          ret.rd  = r_inst.rd ;
                                          ret.rs1 = r_inst.rs1;
                                          ret.rs2 = r_inst.rs2;
                                          break;
                                        }

                           }  
                       }
                       break;
                    }

    }
    pass = true;
  } else {
    pass = false;
  }
  
  return ret;
}
