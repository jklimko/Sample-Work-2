#ifndef FULLSTACK_H
#define FULLSTACK_H


#include <stdexcept>
using std::runtime_error;

class FullStack : public runtime_error
{
  public: 

     FullStack()
        : runtime_error("The stack is full"){}
         
};

#endif

