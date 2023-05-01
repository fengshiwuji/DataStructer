#include "seqlist.h"

/**************************************************************
函数功能：初始化顺序表
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
返回值：None.
*************************************************************/
void SeqListInit(SeqList* psl)
{
	psl->size = 0;
}

/**************************************************************
函数功能：顺序表的打印
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
返回值：None.
*************************************************************/
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
		printf("%d\t", psl->arr[i]);
	printf("\r\n");
}

/**************************************************************
函数功能：顺序表的尾插
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
		  x: 数据
返回值：None.
*************************************************************/
void SeqListPushBack(SeqList* psl, SLDataType x)
{
	if (psl->size < N)
	{
		psl->arr[psl->size] = x;
		psl->size++;
	}
	else
	{
		printf("容量不足，插入失败\r\n");
	}
}

/**************************************************************
函数功能：顺序表的尾删
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
返回值：None.
*************************************************************/
void SeqListPopBack(SeqList* psl)
{
	if (psl->size>0)
	{
		psl->size--;
	}
	else
	{
		printf("没有数据可以删除！\r\n");
	}
}

/************************************************
函数功能：实现内存拷贝（单位：字节）
函数参数：dest:目的地址。
		  src :原地址。
		  count:拷贝count字节。
返回值：原目的地址：dest。
注意：该函数与memcpy有所区别，memcpy某种情况下不
能自拷，而memmove可以实现。
************************************************/
static void* my_memmove(void* dest, const void* src, size_t count)
{
	char* pch1 = (char*)dest;
	char* pch2 = (char*)src;
	if ((pch1 > pch2) && (pch1 < (pch2 + count)))
	{
		pch1 = pch1 + count - 1;
		pch2 = pch2 + count - 1;
		while (count--)
		{
			*pch1-- = *pch2--;
		}
	}
	else
	{
		while (count--)
		{
			*pch1++ = *pch2++;
		}
	}
	return dest;
}


/**************************************************************
函数功能：顺序表的头插
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
		  x: 数据
返回值：None.
*************************************************************/
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	my_memmove(psl->arr+1, psl->arr, (psl->size)*sizeof(SLDataType));
	psl->arr[0] = x;
	psl->size++;
}

/**************************************************************
函数功能：顺序表的头删
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
返回值：None.
*************************************************************/
void SeqListPopFront(SeqList* psl)
{
	my_memmove(psl->arr, psl->arr+1, (psl->size-1)*sizeof(SLDataType));
	psl->size--;
}

/**************************************************************
函数功能：查找顺序表中的x
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
		  x:要找的数据
返回值：x数据的下标. -1表示未找到x
*************************************************************/
int SeqListFind(SeqList* psl, SLDataType x)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
	{
		if (psl->arr[i] == x)
			return i;
	}
	return -1;
}

/**************************************************************
函数功能：顺序表中间插入
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
		  pos:要插入的位置
		  x:要插入的数据
返回值：x数据的下标. -1表示未找到x
*************************************************************/
void SeqListInsert(SeqList* psl, size_t pos, SLDataType x)
{
	my_memmove(psl->arr+pos+1, psl->arr + pos, (psl->size-pos)*sizeof(SLDataType));
	psl->arr[pos] = x;
	psl->size++;
}

/**************************************************************
函数功能：顺序表中间删除
函数参数：psl：顺序表结构体变量的地址，即该顺序表的首地址
		  pos:要删除的位置
返回值：x数据的下标. -1表示未找到x
*************************************************************/
void SeqListErase(SeqList* psl, size_t pos)
{
	my_memmove(psl->arr + pos, psl->arr + pos+1, (psl->size-pos-1)*sizeof(SLDataType));
	psl->size--;
}
