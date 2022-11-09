#include "SeqList.h"


/**
  * @brief 初始化顺序表
  * @param ps:顺序表
  * @return None.
  */
void SeqListInit(SL* ps)
{
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}

/**
  * @brief 顺序表打印输出
  * @param ps:顺序表
  * @return None.
  */
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d\t", ps->data[i]);
	}
	printf("\n");
}

/**
  * @brief 顺序表的测容
  * @param ps:顺序表
  * @return None.
  */
void SeqListCheckCapacity(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newCapacity = (ps->capacity == 0) ? 4 : ps->capacity * 2;
		SLDataType* temp = (SLDataType*)realloc(ps->data, newCapacity * sizeof(SLDataType));
		if (temp != NULL)
		{
			ps->data = temp;
			ps->capacity = newCapacity;
			printf("空间开辟成功，newCapacity:%d\n", newCapacity);
		}
	}
}

/**
  * @brief 顺序表的尾插
  * @param ps:顺序表
  * @param data:要插入的数据
  * @return None.
  */
void SeqListPushBack(SL* ps, SLDataType data)
{
	SeqListCheckCapacity(ps);
	ps->data[ps->size] = data;
	ps->size++;
}

/**
  * @brief 顺序表的尾删
  * @param ps:顺序表
  * @return None.
  */
void SeqListPopBack(SL* ps)
{
	ps->size--;
}


/**
  * @brief 顺序表的头插
  * @param ps:顺序表
  * @param data:要插入的数据
  * @return None.
  */
void SeqListPushFront(SL* ps, SLDataType data)
{
	SeqListCheckCapacity(ps);
	my_memmove(ps->data + 1, ps->data, ps->size*sizeof(SLDataType));
	ps->data[0] = data;
	ps->size++;
}

/**
  * @brief 顺序表的头删
  * @param ps:顺序表
  * @return None.
  */
void SeqListPopFront(SL* ps)
{
	my_memmove(ps->data,ps->data +1, ps->size*sizeof(SLDataType));
	ps->size--;
}

/**
  * @brief 顺序表任意位置插入
  * @param ps:顺序表
  * @param data:插入的数据
  * @return None.
  */
void SeqListPushInsert(SL* ps, int pos, SLDataType data)
{
	assert(pos>=0);
	SeqListCheckCapacity(ps);
	my_memmove(ps->data + 1+pos, ps->data+pos , (ps->size-pos) * sizeof(SLDataType));
	ps->data[pos] = data;
	ps->size++;
}

/**
  * @brief 删除任意位置的元素
  * @param ps:顺序表
  * @return None.
  */
void SeqListErase(SL* ps, int pos)
{
	assert(ps->data && pos >= 0); 
	my_memmove(ps->data + pos, ps->data + pos + 1, (ps->size - pos - 1) * sizeof(SLDataType));
	ps->size--;
}

/**
  * @brief	在顺序表查找数据
  * @param ps:顺序表
  * @param data:要查找的数据
  * @return 找到了返回数据在顺序表的下标，找不到返回-1.
  */
int SeqListFind(SL* ps, SLDataType data)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->data[i] == data)
			return i;
	}
	return -1;
}

/**
  * @brief 销毁动态申请的空间
  * @param ps:顺序表
  * @return None.
  */
void SeqListDestory(SL* ps)
{
	free(ps->data);
	ps->data = NULL;
	ps->size = ps->capacity = 0;
}
