#ifndef DIGITAL_COMPONENT_H
#define DIGITAL_COMPONENT_H
//Author  : Alex Zhang (cgalexzhang@sina.com)
//Date    : 03-07-2017
//Comment : Each digital component has the timing sequence, derived from this class

class DigitalComponent{
public:
           DigitalComponent();
  virtual void  run_clock() =0;
  virtual ~DigitalComponent();


private:


}; 


#endif
