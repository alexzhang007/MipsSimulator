#include "instruction_memory.h"
#include "mips_instruction.h"
//Initialize the Instruction memory size to 1K
InstructionMemory::InstructionMemory(): PC(0), MAX_SIZE(1024){
  data = NULL;
  data = new MipsInstruction[MAX_SIZE];
}

InstructionMemory::~InstructionMemory() {
  delete[] data;
  MAX_SIZE = 0;
}
void InstructionMemory::LoadMipsInstruction(const char* binary_file){
  ifstream in_file(binary_file);
  int index;
  char buffer[256];
  //char* stop_str;
  int reg_dest, reg_src1, reg_src2, reg_src3;
  int funct3, funct7;
  int op_code_v ;
  if (!in_file.is_open()) {
    cout<<"Error opening file:" <<binary_file<<endl;
    exit(1);
  }

  index =0;
  while (!in_file.eof()) {
    in_file.getline(buffer, 256);
    string str(buffer); 
    if (buffer[0]==0) {
       break;
    }
    cout<<"Instruction ==== "<<index <<"==="<<endl;
    cout<<"Buffer is "<<buffer<<endl;  
    string code (str.begin(), str.end());
    cout<<"code is "<<code<<endl;
    string op_code_s = code.substr(25, 7); 
    //int op_code_v = strtol(op_code_s.c_str(), &stop_str, 2);
    op_code_v = binary_string_to_int(op_code_s);
    cout<<"Opcode_v "<<op_code_v<<endl;
    MIPS_RV32I_Opcode op_code = MIPS_RV32I_Opcode(op_code_v);
    cout<<"op_code is "<<op_code<<endl;

    string rd_str, funct3_str, rs1_str, imm_str;
    int    rd_int, funct3_int, rs1_int, imm_int;
    switch(op_code) {
      case RV32I_ADDI : {
                          cout <<"An ADDI instruction."<<endl;
                          rd_str    = code.substr(20, 5);
                          funct3_str= code.substr(17, 3);
                          rs1_str   = code.substr(12, 5 );
                          imm_str   = code.substr(0 , 12);
                      
                          rd_int    = binary_string_to_int(rd_str); 
                          funct3_int= binary_string_to_int(funct3_str); 
                          rs1_int   = binary_string_to_int(rs1_str); 
                          imm_int   = binary_string_to_int(imm_str);
                          data[index]   = MipsInstruction(I_type); 
                          data[index].CreateMipsInstI(RV32I_ADDI, rd_int, funct3_int, rs1_int, imm_int);
                          break;
                        }
      default         : {
                          cout <<"Unknown instructions."<<endl;
                        }
        
    }
   
    memset(buffer,0, sizeof(buffer));
    index ++;
   
  }
  in_file.close();
}
//The system will contain the brach/Jump instruction
void    InstructionMemory:: UpdatePC() {

  PC ++;

}

MipsInstruction& InstructionMemory::FetchNextInstruction(){
  return data[PC];
}


int InstructionMemory::binary_string_to_int(string& bin_str) {
  char* stop_str;
  int ret_val = strtol(bin_str.c_str(), &stop_str, 2);
  return ret_val;
}
