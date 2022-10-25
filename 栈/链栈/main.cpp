#include "LinkedStack.h"
#include <fstream>
#include <cassert>
using namespace std;
LinkedStack<int>& decTObin(LinkedStack<int>& sta);
long binTOstr(LinkedStack<int>& a);
int main(){
	LinkedStack<int> sta;
	cout << "转换后的二进制为:" << binTOstr(decTObin(sta));
	return 0;
	/*ifstream fin("data.txt");
	assert(fin);
	int data;
	while (!fin.eof()){
		assert(fin >> data);
		sta.Push(data);		
	}
	cout << "The initial Stack in the file is:\n" << sta;
	cout << "The current size of the Stack is: " << sta.getSize() << endl;
	sta.getTop(data);
	cout << "The current Top of the Stack is : " << data << endl;
	sta.Pop(data);
	cout << "\nDo a Pop operation, then the stack is:\n" << sta << endl;
	cout << "The data popped is: " << data << endl;
	sta.getTop(data);
	cout << "The current Top of the Stack is : " << data << endl;
	cout << "\nTest the state of the stack:\n";
	if (sta.IsEmpty())	cout << "The stack is empty now!\n";
	else if (sta.IsFull())	cout << "The stack is full now!\n";
		else	cout << "The stack is not empty and not full now!\n";
	sta.makeEmpty();
	cout << "Now make the stack empty, then the state of the stack is:\n";
	if (sta.IsEmpty())	cout << "The stack is empty now!\n";
	else if (sta.IsFull())	cout << "The stack is full now!\n";
		else	cout << "The stack is not empty and not full now!\n";*/
}
LinkedStack<int>& decTObin(LinkedStack<int>& sta) {
	int dec;
	cout << "请输入一个十进制整数:" << endl;
	cin >> dec;
	int i;// i为入栈的余数
	while (dec != 0) {
		i = dec % 2;
		sta.Push(i);
		dec /= 2;
	}
	return sta;
}
long binTOstr(LinkedStack<int>& a) {
	int n = 0;
	long bin = 0;
	while (!a.IsEmpty())
	{
		bin *= 10;
		a.Pop(n);
		bin += n;
	}
	return bin;
}
