#define _CRT_SECURE_NO_WARNINGS -1

#include "LinkList.h"

void test1(pHead phead)//��������1��β��
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');

	ShowLinkList(phead);
}

void test2(pHead phead)//��������2��ͷ��
{
	PushFront(phead, '0');
	PushFront(phead, '1');
	PushFront(phead, '2');
	PushFront(phead, '3');

	ShowLinkList(phead);
}

void test3(pHead phead)//��������3��ָ��λ�ò���
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');

	Insest(phead, Find(phead, '0'), 'a');
	Insest(phead, Find(phead, '1'), 'b');
	Insest(phead, Find(phead, '3'), 'c');

	ShowLinkList(phead);
}

void test4(pHead phead)//��������4��βɾ
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');
	ShowLinkList(phead);

	PopBack(phead);
	ShowLinkList(phead);

	PopBack(phead);
	ShowLinkList(phead);

	PopBack(phead);
	ShowLinkList(phead);

	PopBack(phead);
	ShowLinkList(phead);

	PopBack(phead);
	ShowLinkList(phead);
}

void test5(pHead phead)//��������4��ͷɾ
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');
	ShowLinkList(phead);

	PopFront(phead);
	ShowLinkList(phead);

	PopFront(phead);
	ShowLinkList(phead);

	PopFront(phead);
	ShowLinkList(phead);

	PopFront(phead);
	ShowLinkList(phead);

	PopFront(phead);
	ShowLinkList(phead);
}

void test6(pHead phead)//��������6��ָ��λ��ɾ��
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');
	ShowLinkList(phead);

	Erase(phead, Find(phead, '0'));
	ShowLinkList(phead);

	Erase(phead, Find(phead, '1'));
	ShowLinkList(phead);

	Erase(phead, Find(phead, '3'));
	ShowLinkList(phead);

	Erase(phead, Find(phead, '2'));
	ShowLinkList(phead);

	Erase(phead, Find(phead, '3'));
	ShowLinkList(phead);
}

void test7(pHead phead)//��������7���滻ָ��λ������
{
	PushBack(phead, '0');
	PushBack(phead, '1');
	PushBack(phead, '2');
	PushBack(phead, '3');
	ShowLinkList(phead);

	At(phead, Find(phead, '0'), 'a');
	At(phead, Find(phead, '1'), 'b');
	At(phead, Find(phead, '3'), 'c');
	ShowLinkList(phead);

	At(phead, Find(phead, '4'), 'd');
	ShowLinkList(phead);

}

int main()
{
	Node *node = Init();

	//test1(node);
	//test2(node);
	//test3(node);
	//test4(node);
	//test5(node);
	//test6(node);
	test7(node);

	system("pause");
	return 0;
}