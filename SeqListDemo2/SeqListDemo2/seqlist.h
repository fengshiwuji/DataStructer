#pragma once

#include <stdio.h>

#define N	100

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType arr[N];	//定义存放有效数据的数组
	size_t size;		//有效数据的个数
}SeqList;

void SeqListInit(SeqList* psl);
void SeqListPrint(SeqList* psl);
void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
int SeqListFind(SeqList* psl, SLDataType x);
void SeqListInsert(SeqList* psl,size_t pos,SLDataType x);
void SeqListErase(SeqList* psl,size_t pos);