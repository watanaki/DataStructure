
#include <iostream>
#include "HaffmanTree.h"
using namespace std;

int main()
{
	HuffmanTree A;
	cout << "请输入要编码字符的个数：";
	int num;cin >> num;
	CreateHuffmanTree(A, num);
	PrintTree(A, num);
	chara *b=new chara[num];
	Code(A,num,b);
	for (int i = 0; i < num; i++)
		cout << b[i] ;
	Decode(A,num,"101100101010");
	
	/*char a[4] = "123";
	a[3] = '\0';
	char b[3];
	strcpy(b, a + 2);
	cout << b;*/
	/*int a, b;
	SeclectMin(A, 4, &a, &b);
	cout << a << ' ' << b;
	A[0].weight = 99; A[1].weight = 88;
	A[3].weight = 17;
	SeclectMin(A, 4, &a, &b);
	cout << a << ' ' << b;*/
}

