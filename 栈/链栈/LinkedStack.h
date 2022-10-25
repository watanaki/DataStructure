#ifndef LINKEDSTACK_H
#define LINKEDSTACK_H
#include <iostream>
#include <cassert>
using namespace std;
template <typename T>struct StackNode{
	T data;
	StackNode<T> *link;
	StackNode(T d = 0, StackNode<T> *next = NULL):link(next),data(d){}
	//StackNode() { data = 0; link = NULL; }
};

template <typename T>class LinkedStack{
private:
	StackNode<T> *top;
public:
	LinkedStack():top(NULL){}//无头结点
	~LinkedStack(){
		makeEmpty();
	}
	void Push(const T &x);
	bool Pop(T &x);
	bool getTop(T &x)const;	
	int getSize()const;
	bool IsEmpty()const{
		return top == NULL;
	}
	bool IsFull()const{
		return false;
	}
	void makeEmpty();
	friend ostream& operator << (ostream &os, LinkedStack<T> &s)	{
		//为下面的代码添加注释
		os << "Stack Size: " << s.getSize() << endl;//输出链栈节点数量
		StackNode<T> *p = s.top;//p节点指向栈顶元素
		int i = 0;//序号
		while (p){
			os << ++i << ": " << p->data << endl;//输出栈顶元素
			p = p->link;//每次循环p指向栈顶的下一个节点
		}
		return os;
	}
};

template <typename T>void LinkedStack<T>::makeEmpty(){
	StackNode<T> *p;
	while (top){//最后top为NULL
		p = top;
		top = top->link;
		delete p;
	}
}

template <typename T>void LinkedStack<T>::Push(const T &x){
	//补全代码
	StackNode<T>* p=new StackNode<T>(x,top);
	top = p;
	assert(top);
}

template <typename T>bool LinkedStack<T>::Pop(T &x){
	if (IsEmpty()){
		return false;
	}
	StackNode<T> *p = top;
	//补全代码
	top = top->link;
	x = p->data;
	p->link = NULL;
	return true;	
}

template <typename T>bool LinkedStack<T>::getTop(T &x)const{	
	if (IsEmpty())	return false;
	x = top->data; 
	return true;
}

template <typename T>int LinkedStack<T>::getSize()const{
	StackNode<T> *p = top;
	int k = 0;
	while (p){
		p = p->link;
		k++;
	}
	return k;
}
#endif
