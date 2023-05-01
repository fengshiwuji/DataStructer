#include "seqlist.h"


/**************************************************************
  * @brief 内存拷贝函数
  * @param dest:目的地址
  * @param src:源地址
  * @param count:拷贝字节数
  * @return 目的地址.
  *************************************************************/
void* my_memmove(void* dest, const void* src, size_t count)
{
	void* temp = dest;
	/*若目的地址比源地址小则从前往后拷贝，否则反之*/
	if (dest < src)
	{
		while (count--)
		{
			*((char*)dest) = *((char*)src);
			++(char*)dest;
			++(char*)src;
		}
	}
	else
	{
		dest = (char*)dest + count - 1;
		src = (char*)src + count - 1;
		while (count--)
		{
			*(char*)dest = *(char*)src;
			--(char*)dest;
			--(char*)src;
		}
	}
	return temp;
}

/*******************************************
函数功能：初始化顺序表
函数参数：psl：顺序表结构体变量的地址
********************************************/
void SeqListInit(SeqList* psl)
{
	psl->Data = NULL;
	psl->size = 0;
	psl->capacity = 0;
}

/*******************************************
函数功能：顺序表打印
函数参数：psl：顺序表结构体变量的地址
********************************************/
void SeqListPrint(SeqList* psl)
{
	int i = 0;
	for (i = 0; i < psl->size; i++)
		printf("%d\t",psl->Data[i]);
	printf("\r\n");
}

/*******************************************
函数功能：顺序表测容
函数参数：psl：顺序表结构体变量的地址
********************************************/
static void SeqListCheckCapacity(SeqList* psl)
{
	if (psl->size == psl->capacity)
	{
		size_t NewCapacity = (psl->capacity == 0) ? 4 : psl->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(psl->Data, NewCapacity*sizeof(SLDataType));
		if (temp != NULL)
		{
			psl->Data = temp;
			psl->capacity = NewCapacity;
		}
	}
}

/*******************************************
函数功能：顺序表尾插
函数参数：psl：顺序表结构体变量的地址
		  x: 数据
********************************************/
void SeqListPushBack(SeqList* psl,SLDataType x)
{
	SeqListCheckCapacity(psl);
	psl->Data[psl->size] = x;
	psl->size++;
}

/*******************************************
函数功能：顺序表尾删
函数参数：psl：顺序表结构体变量的地址
********************************************/
void SeqListPopBack(SeqList* psl)
{
	if (psl->size)
		psl->size--;
}

/*******************************************
函数功能：顺序表头插
函数参数：psl：顺序表结构体变量的地址
		  x: 数据
********************************************/
void SeqListPushFront(SeqList* psl, SLDataType x)
{
	SeqListCheckCapacity(psl);
	my_memmove(psl->Data + 1, psl->Data, psl->size * sizeof(SLDataType));
	psl->Data[0] = x;
	psl->size++;
}

/*******************************************
函数功能：顺序表头删
函数参数：psl：顺序表结构体变量的地址
********************************************/
void SeqListPopFront(SeqList* psl)
{
	if (psl->size)
	{
		my_memmove(psl->Data, psl->Data+1, (psl->size-1) * sizeof(SLDataType));
		psl->size--;
	}	
}

/*******************************************
函数功能：顺序表中间插入
函数参数：psl：顺序表结构体变量的地址
          pos:要插入的位置
		  x: 数据
********************************************/
void SeqListInsert(SeqList* psl, size_t pos,SLDataType x)
{
	SeqListCheckCapacity(psl);
	my_memmove(psl->Data + pos+1, psl->Data+pos, (psl->size-pos) * sizeof(SLDataType));
	psl->Data[pos] = x;
	psl->size++;
}

/*******************************************
函数功能：顺序表中间删除
函数参数：psl：顺序表结构体变量的地址
          pos:要删除的位置
********************************************/
void SeqListErase(SeqList* psl,size_t pos)
{
	my_memmove(psl->Data + pos, psl->Data + pos+1, (psl->size - pos-1) * sizeof(SLDataType));
	psl->size--;
}

/*******************************************
函数功能：顺序表销毁
函数参数：psl：顺序表结构体变量的地址
********************************************/
void SeqListDestory(SeqList* psl)
{
	free(psl->Data);
	psl->Data = NULL;
	psl->size = psl->capacity = NULL;
}

