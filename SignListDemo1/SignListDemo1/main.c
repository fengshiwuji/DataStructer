#include <stdio.h>
#include "signlist.h"

//单链表测试函数
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

//单链表测试函数
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

//单链表测试函数
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
		printf("找到了：%p\r\n", pos);
		printf("pos->data：%d\r\n", pos->data);
	}
	else
	{
		printf("未找到：%d\r\n", 300);
	}
}

//单链表测试函数
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
		printf("找到了：%p\r\n", pos);
		printf("pos->data：%d\r\n", pos->data);
	}
	else
	{
		printf("未找到：%d\r\n", 300);
	}

	SListInsert(&plist,pos,1000);
	SListInsert(&plist, pos, 1000);
	SListInsert(&plist, pos, 1000);
	SListInsert(&plist, pos, 1000);

	SListErase(&plist, pos);

	SListPrint(plist);
	SListDestory(&plist);
}

//主函数
int main(void)
{
	SListTest1();
	//SListTest2();
	//SListTest3();
	//SListTest4();

	return 0;
}

