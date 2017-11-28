#include "SortedList.h"

SortedListByArray::SortedListByArray()
{
  length = 0;
}


bool SortedListByArray::IsFull() const
{
  return (length == MAX_ITEM);
}

int SortedListByArray::GetLength( ) const
{
  return length;
}


bool SortedListByArray::IsEmpty() const
{
  return (length == 0);
}

void SortedListByArray::InsertItem(ItemType item) 
{
   bool moreToSearch; 
   int location = 0;
   moreToSearch = (location < length);
   while (moreToSearch)
   {
      switch(item.ComparedTo(info[location]))
      {
         case LESS : moreToSearch = false; break;
         case GREATER : location++;
                        moreToSearch = (location < length);
                        break;
      }
   }

   for ( int index = length; index > location; index--)
        info[index] = info[index-1];

   info[location] = item;
   length++;
}


void SortedListByArray::RetrieveItem(ItemType& item, bool& found) 
// Pre:  Key member(s) of item is initialized. 
// Post: If found, item's key matches an element's key in the 
//       list and a copy of that element has been stored in item; 
//       otherwise, item is unchanged. 
{
  int midPoint;
  int first =0;
  int last = length -1;
  
  bool moreToSearch = (first <= last);
  found = false;
  while (moreToSearch && !found) 
  {
    midPoint = (first+last)/2;
    switch (item.ComparedTo(info[midPoint]))
    { 
      case LESS    : last = midPoint -1;
                     moreToSearch = (first <= last);
                     break;
      case GREATER : first = midPoint +1;
                     moreToSearch = (first <= last);
                     break;
      case EQUAL   : found = true;
                     item = info[midPoint];
                     break;
    }
  }
}


void SortedListByArray::DeleteItem(ItemType item) 
// Pre: item�s key has been inititalized.
//	One and only one element in the list has a key that matches item�s.
// Post: No element in the list has a key that matches item�s.
{
   int location = 0;
   while(item.ComparedTo(info[location])!= EQUAL)
       location++;

   for ( int index = location +1; index < length; index++)
        info[index-1] = info[index];
   info[location] = item;
   length--;
}


void SortedListByArray::MakeEmpty()
// Pre:  N/A   
// Post: the list is empty
{
   length = 0;
}



void SortedListByArray::ResetList ( )  
// Pre:  List has been inititalized.
// Post: Current position is prior to first element.
{    
  currentPos  =  -1 ;
}


void SortedListByArray::GetNextItem ( ItemType&  item )  
// Pre:  List has been initialized. Current position is 
//       defined. 
//       Element at current position is not last in list.
// Post: Current position is updated to next position.
// 	  item is a copy of element at current position.
{
  currentPos++  ;
  item = info [currentPos] ;
}

void SortedListByArray::Split(SortedListByArray& listOne, SortedListByArray& listTwo, ItemType item){

	currentPos = -1;
	ItemType thisOne;//making generic data type
	for(int i=0; i<GetLength(); i++){	//iterates through all parts of array
	       	GetNextItem(thisOne);
		if(thisOne.ComparedTo(item)==(GREATER))
			listTwo.InsertItem(thisOne);
		else
			listOne.InsertItem(thisOne);
	}
}
void SortedListByArray::Merge( SortedListByArray& listOne, SortedListByArray& listTwo ){
	//function to merge the lsits without using insertitem, doesnt seem to work as intended. ouptuts are not sorted when they are put into the array. 

	currentPos = -1;
	int i, j = 0;

	listOne.ResetList();
	listTwo.ResetList();

	while (i < listOne.GetLength() && j < listTwo.GetLength()){
		ItemType thisOne = listOne.info[i];
		ItemType thisTwo = listTwo.info[j];

		switch (thisOne.ComparedTo(thisTwo)){	
			case GREATER:
				info[currentPos] = thisTwo;
				j++;
				break;
			case LESS:
				info[currentPos] = thisOne;
				i++;
				break;
			case EQUAL:
				info[currentPos] = thisOne;
				info[currentPos++] = thisTwo;
				i++;
				j++;
				currentPos++;
				break;
		}
		currentPos++;
		length++;
	}

	if (i < listOne.GetLength()){
		for (int k=i; k <= listOne.GetLength(); k++){
			info[currentPos] = listOne.info[k];
			currentPos++;
			length++;
		}
	}
	
	if (j < listTwo.GetLength()){
		for (int k = j; k <= listTwo.GetLength(); k++){
			info[currentPos] = listTwo.info[k];
			currentPos++;
			length++;
		}
	}
	
}
