#pragma once
#include<iostream>
#include<string.h>
#pragma warning(disable:4996)
using namespace std;
//编码字符类,用来存储要编码的字符和对应的哈弗曼编码
class chara {
public:
    char c;
    char* code;
    chara() {
        c = '#';
        code = NULL;
    }
    friend ostream& operator<<(ostream& out, chara& c) {
        out << c.c << ":" << c.code << endl;
        return out;
    }
    /*friend istream& operator>>(istream& in, chara& c) {
        cin >> c.c >> c.weight;
        return in;
    }*/
};
//错误提醒
void error(string s) {
    cout << s << endl;
}
//哈夫曼树结点
class HTNode {
public:
    char c;
    int weight;
    int parent,  lchild,  rchild;
    HTNode(int w = 0) {
        c = '#';
        weight = w; 
        parent = lchild = rchild = -1;
    }
};
typedef HTNode* HuffmanTree;
//从数组里选出两个权最小的
void SeclectMin(HuffmanTree p, int n, int *s1,int *s2) {
    int k = 0;
    while (p[k].parent != -1)k++;//找到数组中第一个没被构造过的结点
    for (int i = 0; i < n; i++) {
        if (p[i].weight < p[k].weight && p[i].parent == -1)
            k = i;
    }
    *s1 = k;
    k = 0;
    while (p[k].parent != -1 || k == *s1)k++;
    for (int i = 0; i < n; i++) {
        if (p[i].weight < p[k].weight && p[i].parent == -1&&i!=*s1)
            k = i;
    }
    *s2 = k;
}
//初始化结点数组
int InitNodeArray(HuffmanTree& p) {
    return 0;
}
//构造哈夫曼树
void CreateHuffmanTree(HuffmanTree& p, int n) {
    if (n < 1)error("参数错误!");
    else {
        int m = 2 * n - 1;
        p = new HTNode[m];
        for (int i = 0; i < n; i++) {
            cout << "请输入字符和权重:\n";
            cin >> p[i].c >> p[i].weight;
        }
        int s1, s2;
        for (int i = n; i < m; i++) {
            SeclectMin(p, i, &s1, &s2);
            p[s1].parent = p[s2].parent = i;
            p[i].lchild = s1; p[i].rchild = s2;//最小的放左边，最大的放右边
            p[i].weight = p[s1].weight + p[s2].weight;
            p[i].c = '#';
        }
    }
}
//打印哈夫曼树
void PrintTree(const HuffmanTree p,int n) {
    for (int i = 0; i < 2 * n - 1; i++) {
        cout <<i <<": char: " << p[i].c << " weight: " << p[i].weight << endl;
        cout << "parent: "<<p[i].parent << ',' <<"left: " << p[i].lchild << ',' <<"right: " << p[i].rchild << endl;
    }
}
void Code(const HuffmanTree p,int num,chara *s) {
        char *cd = new char[num];//临时储存编码
    for (int i = 0; i < num; i++) {
        int start = num - 1;
        cd[start] = '\0';
        s[i].c = p[i].c;
        int j = i;
        while (p[j].parent != -1) {
            int temp = p[j].parent;
            cd[--start] = (p[temp].lchild == j) ? '0' : '1';
            j = temp;
        }
        s[i].code = new char[num - start];
        strcpy(s[i].code, cd+start);
    }
    delete[] cd;
}
void Decode(const HuffmanTree p,int n,const char*c) {
        int m=n = 2 * n - 2;
    for (int i = 0; c[i] != '\0'; i++) {
        if (c[i] != '0' && c[i] != '1') {
            error("请输入正确的哈夫曼编码！");
            return;
        }
         m = (c[i] == '0') ? p[m].lchild : p[m].rchild;
        if (p[m].lchild == -1)
        {
            cout << p[m].c;
            m = n;
        }
    }
        if(m!=n)
            error("请输入正确的哈夫曼编码！");
   // cout << "TEST" << endl;
}
