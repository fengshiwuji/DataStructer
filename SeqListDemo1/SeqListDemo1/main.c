/******************************************************************************
  *  Instruction: 复习动态顺序表
  *  Time : 2022-11-10
  *****************************************************************************/
#include <stdio.h>
#include <string.h>
#include "SeqList.h"

#pragma warning(disable:4996)
#pragma warning(disable:6031)

/*对尾插、尾删的测试*/
void SeqListTest1(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPrint(&sl);
	printf("插入成功\n");
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
	printf("尾删成功\n");
	SeqListDestory(&sl);	/*销毁空间*/
}

/*对头插、头删的测试*/
void SeqListTest2(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 2);
	SeqListPushFront(&sl, 3);
	SeqListPushFront(&sl, 4);
	SeqListPrint(&sl);
	printf("插入成功\n");
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);
	printf("尾删成功\n");
	SeqListDestory(&sl);	/*销毁空间*/
}

/*对任意位置插入、删除的测试*/
void SeqListTest3(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushInsert(&sl,0,1);
	SeqListPushInsert(&sl,0,2);
	SeqListPushInsert(&sl, 0, 3);
	SeqListPrint(&sl);
	printf("插入成功\n");
	SeqListErase(&sl,0);
	SeqListPrint(&sl);
	printf("删除成功\n");
}

/*对SeqListFind函数的测试*/
void SeqListTest4(void)
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushInsert(&sl, 0, 1);
	SeqListPushInsert(&sl, 0, 2);
	SeqListPushInsert(&sl, 0, 3);
	SeqListPrint(&sl);
	printf("插入成功\n");

	int pos = SeqListFind(&sl,5);
	if (pos != -1)
	{
		printf("找到了！下标为%d\n",pos);
	}
	else
	{
		printf("未找到该数据!\n");
	}

}

/**
  * @brief main函数
  * @param None.
  * @return None.
  */
int main(void)
{
	//SeqListTest1();

	//SeqListTest2();

	//SeqListTest3();

	SeqListTest4();

	return 0;
}