#pragma once

#include <stdio.h> 
#include <stdlib.h> 
#include "memory.h"

typedef int SLDataType;	

typedef struct SeqList
{
	SLDataType* data;
	int size;		//记录存储了多少个元素
	int capacity;
}SL;

/*-------------------------------顺序表常用接口声明-------------------------------*/

void SeqListInit(SL* ps);
void SeqListPrint(SL* ps);
void SeqListPushBack(SL* ps, SLDataType data);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps, SLDataType data);
void SeqListPopFront(SL* ps);
void SeqListPushInsert(SL* ps, int pos, SLDataType data);
void SeqListErase(SL* ps, int pos);
int SeqListFind(SL* ps, SLDataType data);
void SeqListDestory(SL* ps);

/*--------------------------------------end--------------------------------------*/
