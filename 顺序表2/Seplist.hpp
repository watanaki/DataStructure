#pragma once
#include<iostream>
#include<string>
using namespace std;
const int MAX = 30;
template<class T>
class Seplist {
private:
	int length; //˳�����Ч����
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
/*������ʾ*/
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
		error("��Χ����!");
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
	 cout << "���ʼ��˳����ֵ,��������ִ���¼�����(����������������һ������Ctrl+Z�����������!):"<<endl;
	 T a;
	 while (cin >> a)
	 {
		 data[count++] = a;
	 }
	 return count;
}

/*����˳���*/
template<class T>
int Seplist<T>::LocateList(T x)
{
	if (IsArrayVoid())
		return -1;
	for (int i = 0; i < length; i++)
		if (data[i] == x)
		{
			cout << "�������ҵ�����"<<" "<<x<<" " << "�ڱ��е�" << i + 1 << "λ" << endl;
			return i + 1;
		}
	error("�����޴�����!");
	return -1;
}

/*��˳����в�����x,i����鵽�ڼ���λ��,��1��ʼ*/
template<class T>
void Seplist<T>::InsertList(int i,T x )
{
	if (length == MAX)
	{
		error("˳�������,���ɲ���!");
		return;
	}
	if (i<1 || i>length+1) {
		error("����λ��Խ��!");
		return;
	}
	for (int j = length - 1; j >= i - 1; j--)
		data[j + 1] = data[j];
	data[i - 1] = x;
	this->length++;
	cout << "��ӳɹ�!" << endl;
	PrintList();
}

/*��˳�����ɾ����i�����*/
template<class T>
void Seplist<T>::DeleteList(int n) {
	if (IsArrayVoid())
		return;
	if (n<1 || n>length) {
		error("Ŀ��λ��Խ��!");
		return;
	}
	for (int i = n; i <= length - 1; i++)
		data[i - 1] = data[i];
	length--;
	cout << "ɾ���ɹ�!" << endl;
	PrintList();
}

/*��ӡ˳�����ǰn�����*/
template <class T>
void Seplist<T>::PrintList(int n) {
	printData(1, n);
}

/*��ӡ˳���*/
template <class T>
void Seplist<T>::PrintList() {
	printData(1, length);
}

/*�жϵ�ǰ�����Ƿ�Ϊ��*/
template<class T>
inline bool Seplist<T>::IsArrayVoid()
{
	if (length == 0) {
		error("��ǰ˳���Ϊ��!");
		return true;
	}
	return false;
}
