#ifndef STACKONARRAY_H
#define STACKONARRAY_H

#include "ItemType.h"
#include "FullStack.h"
#include "EmptyStack.h"

class StackOnArray
{
public:
  StackOnArray();
  ~StackOnArray();
  bool IsEmpty() const;
  bool IsFull() const;
  void Push(ItemType item); //throw (FullStack);
  void Pop( ); //throw (EmptyStack);
  ItemType Top() const; //throw (EmptyStack);
  int GetTop() const;

private:
  int top;
  ItemType items[MAX_ITEM];
};

#endif
