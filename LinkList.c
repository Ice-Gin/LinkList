#define _CRT_SECURE_NO_WARNINGS -1

#include "LinkList.h"


typedef struct Node    //单链表结点
{
	DataType data;
	struct Node *next;
}Node,*pHead;//*pHead 是结构体指针 重命名的  Node是结构体的重命名，那么*pHead是结构体指针的重命名  所以struct Node *  p <==> pHead p


pHead Init()//初始化头结点指针
{
	Node *phead = (Node *)malloc(sizeof(Node));

	if (NULL == phead)
	{
		perror("malloc");
		exit(-1);
	}

	phead->next = NULL;
	return phead;
}

void Destory(Node * pNode)
{
	free(pNode);
	pNode = NULL;
}

void BuyNode(Node **pnode,DataType x)//创建结点
{
	(*pnode) = (Node *)malloc(sizeof(Node));

	if (NULL == (*pnode))
	{
		perror("malloc");
		return;
	}

	(*pnode)->data = x;
	(*pnode)->next = NULL;
}

void PushBack(pHead phead, DataType x)//尾插
{
	Node *pnode = NULL;
	Node *pret = phead;

	while (pret->next)//寻找尾结点
	{
		pret = pret->next;
	}

	BuyNode(&pnode, x);
	pret->next = pnode;
}

void PushFront(pHead phead, DataType x)//头插
{
	assert(phead);
	Node *pnode = NULL;

	BuyNode(&pnode, x);
	pnode->next = phead->next;
	phead->next = pnode;
}

Node* Find(pHead phead, DataType x)//查找指定元素的位置
{
	assert(phead);
	Node *pnode = phead->next;
	while (pnode)
	{
		if (pnode->data == x)
		{
			return pnode;
		}
		pnode = pnode->next;
	}
	return NULL;
}

void Insest(pHead phead, Node* pos, DataType x)//插入指定位置前面
{
	assert(phead);
	assert(pos);
	Node *pnode = NULL;
	Node *pret = NULL;
	BuyNode(&pnode, x);

	pret = phead;
	while (pret->next != pos)
	{
		pret = pret->next;
	}
	pnode->next = pret->next;
	pret->next = pnode;
}

void PopBack(pHead phead)//尾删
{
	assert(phead);
	Node *ret = NULL;
	Node *tmp = NULL;
	//如果链表为空
	if ((phead)->next == NULL)
	{
		return;
	}

	ret = phead;
	while (ret->next->next)//找尾
	{
		ret = ret->next;
	}
	tmp = ret->next;
	free(tmp);
	tmp = NULL;
	ret->next = NULL;
}
void PopFront(pHead phead)//头删
{
	assert(phead);
	Node *ret = NULL;
	Node *tmp = NULL;
	//如果链表为空
	if ((phead)->next == NULL)
	{
		return;
	}
	//如果只有一个结点
	if (phead->next->next == NULL)
	{
		tmp = phead->next;
		free(tmp);
		tmp = NULL;
		phead->next = NULL;
		return;
	}
	else//如果有多个结点
	{
		tmp = phead->next;
		ret = phead->next->next;
		phead->next = ret;
		free(tmp);
		tmp = NULL;
	}
}

void Erase(pHead phead, Node* pos)//指定位置删除
{
	assert(phead);
	assert(pos);
	Node *ret = phead;
	Node *tmp;

	//如果链表为空
	if ((phead)->next == NULL)
	{
		return;
	}
	//如果链表不为空
	while(ret->next->data != pos->data)
	{
		ret = ret->next;
	}
	tmp = ret->next;
	ret->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

void At(pHead phead, Node* pos, DataType x)//替换指定位置的数据
{
	assert(phead);
	assert(pos);
	Node * ret = phead->next;

	while (ret!= pos)
	{
		ret = ret->next;
	}
	ret->data = x;
}

void ShowLinkList(pHead phead)//打印单链表内容
{
	Node *pnode;
	pnode = phead->next;

	printf("单链表内容为：\n");
	while (NULL != pnode)//错误的是(NULL != pnode->next)
	{
		printf("%c ",pnode->data);
		pnode=pnode->next;
	}
	printf("\n");
}