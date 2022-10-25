
#include <iostream>
using namespace std;
class LinkNode {
public:
	char a;
	LinkNode* next;
	LinkNode() {};
	LinkNode(char a) { this->a = a; next= NULL; };
};
//LinkNode* initList(LinkNode* p) { return new LinkNode(); }
void insertList(LinkNode* p,char a);//尾插法
void insertList(LinkNode* p,int n,char a);//定点插入
void deleElem(LinkNode* p,char a);//按值删除
void deleElem(LinkNode* p,int n);//按序号删除（从1开始）
bool ListEmpty(LinkNode* p);//判断链表是否为空
int getLength(LinkNode* p);//返回链表长度
void showList(LinkNode* p);//输出全表
void showList(LinkNode* p,int n);//输出第n个元素
int findElem(LinkNode* p, char a);//按值查找
void error(const char* a) { cout << a << endl; }//错误提醒
void deleList(LinkNode *&p);//释放链表

int main()
{
	LinkNode* head = new LinkNode();
	insertList(head, 'h');
	insertList(head, 'e');
	insertList(head, 'l');
	insertList(head, 'l');
	insertList(head, 'o');
	showList(head);
	deleList(head);
	showList(head);
	
}

void insertList(LinkNode* p,char a)
{
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = new LinkNode(a);
	cout << "插入成功！" << endl;
	
}

void insertList(LinkNode* p, int n, char a)
{
	if (n < 1) { error("范围错误!"); return; }
	int i = getLength(p) + 1;
	if (n>i)//n不允许大于表长+1
	{
		printf("表内现在还没有%d个元素!\n", n);
		return;
	}
	if (n == i) {//n=表长+1，直接尾插
		insertList(p,a);
		return;
	}
	int count = 0;
	while (p->next != NULL) {
		count++;
		if (count == n)
			break;
		p = p->next;
		
	}
	LinkNode *temp =new LinkNode(a);
	temp->next = p->next;
	p->next = temp;
	cout << "插入成功！" << endl;
}

void deleElem(LinkNode* p, char a)
{
	if (ListEmpty(p))
		return;
	LinkNode* q = p;
	p = p->next;
	while (p->next != NULL&&p->a!=a)
	{
		q = p;
		p = p->next;
	}
	if (p->a == a)
	{
		q->next = p->next;
		delete p;
		cout << "删除成功！" << endl;
		return;
	}
	error("表内无此元素！");
}

void deleElem(LinkNode* p, int n)
{
	if(n<1||n>getLength(p))
	{
		error("范围越界！");
		return;
	}
	int count = 0;
	while (p->next != NULL)
	{
		count++;
		if (count == n)
			break;
		p = p->next;
	}
	p->next = p->next->next;
	cout << "删除成功！" << endl;
	return;
}

bool ListEmpty(LinkNode* p)
{
	if(p==NULL)
	{
		error("链表不存在！");
		return true;
	}
	if (p->next == NULL)
	{
		error("链表为空！");
		return true;
	}
	return false;
	}

int getLength(LinkNode* p)
{
	int count = 0;
	while (p->next != NULL)
	{
		count++;
		p = p->next;
	}
	return count;
}

void showList(LinkNode* p)
{
	if (ListEmpty(p))
		return;
	while (1)
	{
			p = p->next;
			cout << p->a << "->";
			if (p->next == NULL)
				break;
	}
	cout << "NULL" << endl;
}

void showList(LinkNode* p, int n)
{
	if (n < 1) { error("范围错误！"); return; }
	if (ListEmpty(p))
		return;
if(getLength(p)<n)
{
	printf("表内现在还没有%d个元素!\n", n);
	return;
}
int count = 0;
while (p->next != NULL) {
	p = p->next;
	count++;
	if (count == n)
		break;
}
printf("第%d个元素为：%c\n", n,p->a);
}

int findElem(LinkNode* p, char a)
{
	if (ListEmpty(p))
		return -1;
	int count = 0,n=0;
	while (p->next!=NULL) {
		count++;
		p = p->next;
		if (p->a == a)
		{
			n++;
			break;
		}
	}
	if (n)
	{
		printf("你所查找的元素%c在表中第%d位", a, count);
		return count;
	}
		error("表中没有从此元素！");
	return -1;
}

void deleList(LinkNode* &p)
{
	LinkNode* q;
	while (p->next != NULL) {
		 q = p;
		p = p->next;
		delete q;
	}
	q = p;
	p = NULL;
	delete q;
}
