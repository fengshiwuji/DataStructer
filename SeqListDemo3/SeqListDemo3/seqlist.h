#pragma once

#include <stdio.h>
#include <malloc.h>

typedef  int SLDataType;

typedef struct SeqList
{
	SLDataType* Data;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList* psl);
void SeqListDestory(SeqList* psl);
void SeqListPrint(SeqList* psl);

void SeqListPushBack(SeqList* psl, SLDataType x);
void SeqListPopBack(SeqList* psl);
void SeqListPushFront(SeqList* psl, SLDataType x);
void SeqListPopFront(SeqList* psl);
void SeqListInsert(SeqList* psl,size_t pos,SLDataType x);
void SeqListErase(SeqList* psl,size_t pos);