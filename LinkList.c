#define _CRT_SECURE_NO_WARNINGS -1

#include "LinkList.h"


typedef struct Node    //��������
{
	DataType data;
	struct Node *next;
}Node,*pHead;//*pHead �ǽṹ��ָ�� ��������  Node�ǽṹ�������������ô*pHead�ǽṹ��ָ���������  ����struct Node *  p <==> pHead p


pHead Init()//��ʼ��ͷ���ָ��
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

void BuyNode(Node **pnode,DataType x)//�������
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

void PushBack(pHead phead, DataType x)//β��
{
	Node *pnode = NULL;
	Node *pret = phead;

	while (pret->next)//Ѱ��β���
	{
		pret = pret->next;
	}

	BuyNode(&pnode, x);
	pret->next = pnode;
}

void PushFront(pHead phead, DataType x)//ͷ��
{
	assert(phead);
	Node *pnode = NULL;

	BuyNode(&pnode, x);
	pnode->next = phead->next;
	phead->next = pnode;
}

Node* Find(pHead phead, DataType x)//����ָ��Ԫ�ص�λ��
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

void Insest(pHead phead, Node* pos, DataType x)//����ָ��λ��ǰ��
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

void PopBack(pHead phead)//βɾ
{
	assert(phead);
	Node *ret = NULL;
	Node *tmp = NULL;
	//�������Ϊ��
	if ((phead)->next == NULL)
	{
		return;
	}

	ret = phead;
	while (ret->next->next)//��β
	{
		ret = ret->next;
	}
	tmp = ret->next;
	free(tmp);
	tmp = NULL;
	ret->next = NULL;
}
void PopFront(pHead phead)//ͷɾ
{
	assert(phead);
	Node *ret = NULL;
	Node *tmp = NULL;
	//�������Ϊ��
	if ((phead)->next == NULL)
	{
		return;
	}
	//���ֻ��һ�����
	if (phead->next->next == NULL)
	{
		tmp = phead->next;
		free(tmp);
		tmp = NULL;
		phead->next = NULL;
		return;
	}
	else//����ж�����
	{
		tmp = phead->next;
		ret = phead->next->next;
		phead->next = ret;
		free(tmp);
		tmp = NULL;
	}
}

void Erase(pHead phead, Node* pos)//ָ��λ��ɾ��
{
	assert(phead);
	assert(pos);
	Node *ret = phead;
	Node *tmp;

	//�������Ϊ��
	if ((phead)->next == NULL)
	{
		return;
	}
	//�������Ϊ��
	while(ret->next->data != pos->data)
	{
		ret = ret->next;
	}
	tmp = ret->next;
	ret->next = tmp->next;
	free(tmp);
	tmp = NULL;
}

void At(pHead phead, Node* pos, DataType x)//�滻ָ��λ�õ�����
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

void ShowLinkList(pHead phead)//��ӡ����������
{
	Node *pnode;
	pnode = phead->next;

	printf("����������Ϊ��\n");
	while (NULL != pnode)//�������(NULL != pnode->next)
	{
		printf("%c ",pnode->data);
		pnode=pnode->next;
	}
	printf("\n");
}