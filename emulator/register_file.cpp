#include "register_file.h"
RegisterFile* RegisterFile::instance_ = 0;
RegisterFile* RegisterFile::GetInstance(){
  if (instance_ == 0)
    instance_ = new RegisterFile();
  return instance_;
}
RegisterFile::RegisterFile(){
  for (int i =0; i< 32; i++) 
    reg[i] = 0;
}
void   RegisterFile::ReadRegister(int rs1, int* rs1_val){
  *rs1_val = reg[rs1];
}
void   RegisterFile::ReadRegister(int rs1, int* rs1_val, int rs2, int* rs2_val){
  *rs1_val = reg[rs1];
  *rs2_val = reg[rs2];
}
void   RegisterFile::WriteRegister(int rd, int wr_val){
  reg[rd] = wr_val;
}
