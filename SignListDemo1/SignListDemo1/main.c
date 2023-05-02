#include <stdio.h>
#include "signlist.h"

//��������Ժ���
void SListTest1(void)
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 100);
	SListPushBack(&plist, 200);
	SListPushBack(&plist, 300);
	SListPushBack(&plist, 400);
	SListPushBack(&plist, 500);
	SListPrint(plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

//��������Ժ���
void SListTest2(void)
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 100);
	SListPushFront(&plist, 200);
	SListPushFront(&plist, 300);
	SListPushFront(&plist, 400);
	SListPushFront(&plist, 500);
	SListPrint(plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPopFront(&plist);
	SListPrint(plist);
}

//��������Ժ���
void SListTest3(void)
{
	SListNode* plist = NULL;
	SListPushFront(&plist, 100);
	SListPushFront(&plist, 200);
	SListPushFront(&plist, 300);
	SListPushFront(&plist, 400);
	SListPushFront(&plist, 500);
	SListPrint(plist);
		
	SListNode* pos = SListFind(plist,300);
	if (pos)
	{
		printf("�ҵ��ˣ�%p\r\n", pos);
		printf("pos->data��%d\r\n", pos->data);
	}
	else
	{
		printf("δ�ҵ���%d\r\n", 300);
	}
}

//��������Ժ���
void SListTest4(void)
{
	SListNode* plist = NULL;
	SListPushBack(&plist, 100);
	SListPushBack(&plist, 200);
	SListPushBack(&plist, 300);
	SListPushBack(&plist, 400);
	SListPushBack(&plist, 500);
	SListPrint(plist);

	SListNode* pos = SListFind(plist, 300);
	if (pos)
	{
		printf("�ҵ��ˣ�%p\r\n", pos);
		printf("pos->data��%d\r\n", pos->data);
	}
	else
	{
		printf("δ�ҵ���%d\r\n", 300);
	}

	SListInsert(&plist,pos,1000);
	SListInsert(&plist, pos, 1000);
	SListInsert(&plist, pos, 1000);
	SListInsert(&plist, pos, 1000);

	SListErase(&plist, pos);

	SListPrint(plist);
	SListDestory(&plist);
}

//������
int main(void)
{
	SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();

	return 0;
}

