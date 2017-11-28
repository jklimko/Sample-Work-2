#include "stack.h"
#include "FullStack.h"
#include "EmptyStack.h"

StackOnArray::StackOnArray()
{ 
  top = -1; 
}

StackOnArray::~StackOnArray()
{
 
}


//pre: Stack has been initialized.
//post: function value = (stack is empty)
bool StackOnArray::IsEmpty() const
{ 
   return ( top == -1); 
}

//pre: stack has been initialized.
//post: function value = (stack is full)
bool StackOnArray:: IsFull() const
{ 
    return ( top == MAX_ITEM-1); 
}
/*

//pre: stack has been initialized and is not full
//post: newItem is at the top of the stack.
void StackOnArray::Push(ItemType newItem)
{
  top++;
  items[top] = newItem;
}

*/

//pre: stack has been initialized.
//post: if stack is full, throw an exception;  
//Else newItem is at the top of the stack.
void StackOnArray::Push(ItemType newItem) //throw (FullStack)
{
  if (IsFull())
	cout << "ERROR, FULL\n";
  top++;
  items[top] = newItem;
 
}

/*

//pre: stack has been initialized and is not empty.
//post: top element has been removed from stack. 
void StackOnArray::Pop()
{   
    top--; 
}


//pre: stack has been initialized and is not empty.
//post: A copy of the top element is returned.
ItemType StackOnArray:: Top() const
{
  return (items[top]);
}

*/


//pre: stack has been initialized.
//post: if stack is empty, throw an exception; else top element 
//has been removed from stack. 
void StackOnArray::Pop() //throw (EmptyStack)
{
  if (IsEmpty())  
	cout << "EMPTY\n";
  top--;
}


//pre: stack has been initialized.
//post: if stack is empty, throw an exception; else a copy of the 
//top element is returned.
ItemType StackOnArray::Top() const //throw (EmptyStack)
{
  if (IsEmpty()) 
	cout << "EMPTY\n";
  return (items[top]);
}
	
int StackOnArray::GetTop() const{
	return top;
}


