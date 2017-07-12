#ifndef INTEGER_PIPELINE_H
#define INTEGER_PIPELINE_H
//Arithmetic Operation type supported in Integer
#include <iostream>
#include <queue>
using namespace std;
enum ArithOp {
  INT_ADD = 0,
  INT_ADDI,
  INT_SUB ,
  INT_MUL ,
  INT_DIV ,
  INT_SQRT,
  INT_ABS ,
  INT_AND ,
  INT_OR  ,
  INT_XOR 
};
typedef struct  {
  ArithOp op  ;
  int     src1;
  int     src2;
  int     rd  ;
} ArithCluster;
typedef struct {
  int  rd;
  int  val;
  bool vld;
} WriteRegCluster;

class IntegerPipeline {
  public :
    IntegerPipeline (int depth);
    ~IntegerPipeline();
    bool PushPipeline(ArithCluster&  data_pack);
    WriteRegCluster Execute();
  private :
    int depth_;
    queue<ArithCluster> data_;


};



#endif
