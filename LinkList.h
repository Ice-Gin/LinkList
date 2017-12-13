#ifndef __LINKLIST_H__

#define __LINKLIST_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define M 10

typedef char DataType;//数据类型重命名
typedef struct Node Node, *pHead;

pHead Init();//初始化头结点指针
void ShowLinkList(pHead phead);//打印单链表内容
void BuyNode(Node **pnode, DataType x);//创建结点

void PushFront(pHead phead, DataType x);//头插
void PushBack(pHead phead, DataType x);//尾插
void PopBack(pHead phead);//尾删
void PopFront(pHead phead);//头删

Node* Find(pHead phead, DataType x);//查找指定元素的位置
void Insest(pHead phead, Node* pos, DataType x);//指定位置插入
void Erase(pHead phead, Node* pos);//指定位置删除

void At(pHead phead,Node* pos,DataType x);//替换指定位置的数据
#endif //__LINKLIST_H__