#pragma once
#include<iostream>
#include<string>
using namespace std;
const int MAX = 30;
template<class T>
class Seplist {
private:
	int length; //顺序表有效长度
	T data[MAX];
	inline bool IsArrayVoid();
	inline void error(string s);
	void printData(int a, int b);
	int initializeData();
public:

	Seplist(int a) { this->length = initializeData(); }
	Seplist() { this->length = 0; }
	~Seplist() {  };
	int LocateList(T x);
	void InsertList( int i,T x);
	void DeleteList(int i);
	void PrintList(int n);
	void PrintList();
	int getlength() { return this->length; }

};
/*错误提示*/
template<typename T>
inline void Seplist<T>::error(string s) {
	cout << s << endl;
}

template<class T>
void Seplist<T>::printData(int a, int b)
{
	if (IsArrayVoid())
		return;
	if (b < 1 || b<a || b>length)
	{
		error("范围错误!");
		return;
	}
	cout << "[";
	for (int i = a - 1; i < b; i++)
	{
		cout << this->data[i];
		if (i != b - 1)
			cout << ",";
	}
	cout << "]" << endl;;
}

template<class T>
 int Seplist<T>::initializeData()
{
	 int count = 0;
	 cout << "请初始化顺序表的值,输入非数字代表录入结束(其它数据类型另起一行输入Ctrl+Z代表输入结束!):"<<endl;
	 T a;
	 while (cin >> a)
	 {
		 data[count++] = a;
	 }
	 return count;
}

/*查找顺序表*/
template<class T>
int Seplist<T>::LocateList(T x)
{
	if (IsArrayVoid())
		return -1;
	for (int i = 0; i < length; i++)
		if (data[i] == x)
		{
			cout << "你所查找的数据"<<" "<<x<<" " << "在表中第" << i + 1 << "位" << endl;
			return i + 1;
		}
	error("表中无此数据!");
	return -1;
}

/*在顺序表中插入结点x,i代表查到第几个位置,从1开始*/
template<class T>
void Seplist<T>::InsertList(int i,T x )
{
	if (length == MAX)
	{
		error("顺序表已满,不可插入!");
		return;
	}
	if (i<1 || i>length+1) {
		error("插入位置越界!");
		return;
	}
	for (int j = length - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = x;
	this->length++;
	cout << "添加成功!" << endl;
	PrintList();
}

/*在顺序表中删除第i个结点*/
template<class T>
void Seplist<T>::DeleteList(int n) {
	if (IsArrayVoid())
		return;
	if (n<1 || n>length) {
		error("目标位置越界!");
		return;
	}
	for (int i = n; i <= length - 1; i++)
		data[i - 1] = data[i];
	length--;
	cout << "删除成功!" << endl;
	PrintList();
}

/*打印顺序表中前n个结点*/
template <class T>
void Seplist<T>::PrintList(int n) {
	printData(1, n);
}

/*打印顺序表*/
template <class T>
void Seplist<T>::PrintList() {
	printData(1, length);
}

/*判断当前表内是否为空*/
template<class T>
inline bool Seplist<T>::IsArrayVoid()
{
	if (length == 0) {
		error("当前顺序表为空!");
		return true;
	}
	return false;
}
