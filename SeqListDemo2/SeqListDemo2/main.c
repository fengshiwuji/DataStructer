/***********************************************************************
使用定长数组实现顺序表

日期：2023-05-01
************************************************************************/

#include <stdio.h>
#include "seqlist.h"

//顺序表测试函数
void SeqListTest1(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 8);
	SeqListPrint(&sl);
	SeqListPopBack(&sl);
	SeqListPrint(&sl);
}

//顺序表测试函数
void SeqListTest2(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPopFront(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 8);

	if (pos != -1)
		printf("找到了，下标: %d\r\n", pos);
	else
		printf("该顺序表中未找到 %d \r\n",8);
}

//顺序表测试函数
void SeqListTest3(void)
{
	SeqList sl;
	SeqListInit(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPopFront(&sl);
	SeqListPushFront(&sl, 8);
	SeqListPrint(&sl);
	int pos = SeqListFind(&sl, 8);

	if (pos != -1)
		printf("找到了，下标: %d\r\n", pos);
	else
		printf("该顺序表中未找到 %d \r\n", 8);

	SeqListInsert(&sl,pos,100);
	SeqListInsert(&sl, pos, 200);
	SeqListInsert(&sl, pos, 300);
	SeqListInsert(&sl, pos, 400);
	SeqListInsert(&sl, pos, 500);
	SeqListPrint(&sl);
	SeqListErase(&sl, pos);
	SeqListErase(&sl, pos);
	SeqListPrint(&sl);
}

//主函数
int main(void)
{
	//SeqListTest1();
	//SeqListTest2();
	SeqListTest3();

	return 0;
}
