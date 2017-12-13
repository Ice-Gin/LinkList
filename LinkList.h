#ifndef __LINKLIST_H__

#define __LINKLIST_H__

#include <stdio.h>
#include <windows.h>
#include <assert.h>

#define M 10

typedef char DataType;//��������������
typedef struct Node Node, *pHead;

pHead Init();//��ʼ��ͷ���ָ��
void ShowLinkList(pHead phead);//��ӡ����������
void BuyNode(Node **pnode, DataType x);//�������

void PushFront(pHead phead, DataType x);//ͷ��
void PushBack(pHead phead, DataType x);//β��
void PopBack(pHead phead);//βɾ
void PopFront(pHead phead);//ͷɾ

Node* Find(pHead phead, DataType x);//����ָ��Ԫ�ص�λ��
void Insest(pHead phead, Node* pos, DataType x);//ָ��λ�ò���
void Erase(pHead phead, Node* pos);//ָ��λ��ɾ��

void At(pHead phead,Node* pos,DataType x);//�滻ָ��λ�õ�����
#endif //__LINKLIST_H__