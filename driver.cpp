/*Joseph Klimko
 * Driver
 */

#include "stack.h"
#include "ItemType.h"
using namespace std;

int main(){
	string a;
	ItemType item;
	StackOnArray s1, s2, tmpS;

	cout << "Please enter some string\n";

	getline(cin, a);

	string pali;
	for (int i = 0; i < a.length(); i++){
		if((a.at(i) >= 'A' && a.at(i) <= 'Z')|| (a.at(i) >= 'a' && a.at(i) <= 'z')){
			pali = pali + a.at(i);
		}
	}

	for (int i=0; i< pali.length(); i++){
		item.Initialize(pali.at(i));
		s1.Push(item);
	}

	tmpS = s1;

	for (int i=0; i<= s1.GetTop(); i){
		s2.Push(s1.Top());
		s1.Pop();
	}
	
	for (int i=0; i<= tmpS.GetTop(); i){
		if (tmpS.Top().ComparedTo (s2.Top()) != EQUAL){
			cout << "This string is not a palindrome\n";
			return (1);
		}
	else{
		tmpS.Pop();
		s2.Pop();

		if (tmpS.IsEmpty()){
			cout << "Yup, thats a palindrome\n";
			break;
		}
	}
}


return (0);	

}
