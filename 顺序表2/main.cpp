#include"Seplist.hpp"
#include <iostream>
using namespace std;
int main()
{
	/*while (1) {
		system("cls");
		cout << "1->创建顺序表" << endl;
		cout << "2->创建空顺序表" << endl;
		cout << "3->插入数据" << endl;
		cout << "4->删除数据" << endl;
		cout << "5->查找" << endl;
		cout << "6->打印数据" << endl;
		cout << "7->打印前n个数据" << endl;
		cout << "请选择要进行的操作:" << endl;
		int o;
		cin >> o;
		switch (o) {
		case 1:
			Seplist<T>
		}
	}*/
	Seplist <int>a;
	a.PrintList();
	a.InsertList(1,2);
	a.InsertList(1, 4);
	a.InsertList(3, 7);
	a.InsertList(2, 5);


	a.PrintList();
	a.LocateList(4);
	a.LocateList(7);
	a.LocateList(5);
	a.LocateList(2);
	a.LocateList(8);


	a.PrintList();
	a.DeleteList(1);
	a.DeleteList(1);
	a.DeleteList(10);
	a.DeleteList(1);
	a.DeleteList(1);
	a.PrintList();
}

