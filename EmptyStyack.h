#ifndef EMPTYSTACK_H
#define EMPTYSTACK_H


#include <stdexcept>
using std::runtime_error;

class EmptyStack : public runtime_error
{
  public: 

     EmptyStack()
        : runtime_error("The stack is empty"){}
         
};

#endif
