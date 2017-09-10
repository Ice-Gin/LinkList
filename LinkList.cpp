#include "iostream"
using namespace std;
typedef struct Node//结点类型定义
{
	char data;
	struct Node * next;
}Node,*LinkList;//*LinkList用来定义单链表的头结点,Node用来定义单链表中的结点（头结点不属于单链表的内容）

LinkList Init_List()//初始化单链表
{
	
	Node *L;
	L = (LinkList)malloc(sizeof(Node));//强制类型转换，不懂，待问
	if (L == NULL)
	{
		printf("初始化失败!\n");
		exit(-1);
	}
	L->next = NULL;
	return L;
}
void CreatFromHead_LinkList(LinkList L)//头插法建表（逆序）
{
	Node *s;
	char c;
	int flag = 1;
	while (flag)
	{
		cin >> c;
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}
void CreatFromTail_LinkList(LinkList L)//尾插法建表
{
	Node *r, *s;//r的作用是以一个独立的结点来等价新节点，以此来持续链接新的结点，简单来说，r始终用来等于链表中的最后一个结点，再从它后面加新结点
	char c;
	int flag = 1;
	r = L;
	while (flag)
	{
		cin >> c;
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			r->next = s;
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;
		}
	}
}
void Length_LinkList(LinkList L)//求单链表长度
{
	Node *p;
	p = L->next;
	int Length = 0;
	while (p!=NULL)
	{
		p = p->next;
		Length++;
	}
	cout << "单链表的长度为："<<Length<<endl;
}
void Dispaly_LinkList(LinkList L)//输出单链表内容
{
	cout << "单链表的内容是："<<endl;
	Node *p;
	p = L->next;
	while (p != NULL)
	{
		cout << p->data<<" ";
		p = p->next;
	}
	cout << endl;
}
int main()
{
	LinkList  L;
	L=Init_List();
	flag://flag1
	cout << "*------------------------------------------------------*" << endl;//从这开始选择功能
	cout << "请选择功能："
		<< endl << "1.正序建表"
		<< endl << "2.逆序建表"
		<< endl << "3.输出单链表的长度"
		<< endl << "4.输出单链表的内容"
		<< endl << "5.查找指定序号的元素"
		<< endl << "6.在指定位置插入元素"
		<< endl << "0.退出程序" << endl;
	int n;
	cin >> n;
	switch (n)
	{
	case 1:CreatFromTail_LinkList(L); break;
	case 2:CreatFromHead_LinkList(L); break;
	case 3:Length_LinkList(L); break;
	case 4:Dispaly_LinkList(L); break;
	default:cout << "谢谢使用！";
		break;
	}
	cout << "是否继续使用顺序表其他功能？1 for 是；2 for 否" << endl;
	int ss;
	cin >> ss;
	if (ss == 1)
	{
		goto flag;//flag1
	}
	system("pause");
	return 0;
}
