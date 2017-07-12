#ifndef REGISTER_FILE_H
#define REGISTER_FILE_H
class RegisterFile {
  public    :
    static RegisterFile* GetInstance();

    void   ReadRegister(int rs1, int* rs1_val); 
    void   ReadRegister(int rs1, int* rs1_val, int rs2, int* rs2_val);
    void   WriteRegister(int rd, int wr_val); 
    
  protected :
    RegisterFile();
    ~RegisterFile();

  private :
    static RegisterFile *instance_;
    //Totoal 32 registers.
    int  reg[32];
};

#endif
