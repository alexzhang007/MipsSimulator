#include "integer_pipeline.h"
IntegerPipeline::IntegerPipeline(int depth): depth_(depth){

}
IntegerPipeline::~IntegerPipeline(){
  for (int i=0; i<depth_; i++) {
    data_.pop();
  }
}
bool IntegerPipeline::PushPipeline(ArithCluster&  data_pack){
  if (data_.size() < depth_) {
    data_.push(data_pack);
  } else {
    return false; //The data cannot be insterted after the pipeline
  }
  return true;
}
WriteRegCluster IntegerPipeline::Execute(){
  WriteRegCluster ret;
  if (data_.size()> 0 ) {
    ArithCluster fifo_data= data_.front();
    data_.pop();
    switch(fifo_data.op) {
      case INT_ADD : {
                       ret.val = fifo_data.src1 + fifo_data.src2;
                       ret.rd  = fifo_data.rd ; 
                       ret.vld = true;
                     }

    }
  } else {
    ret.vld = false;
  }
  
  return ret;

}

