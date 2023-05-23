#include "sort.h"


/*************************************************
函数功能：交换两个整型变量的值
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void swap(int* pnum1, int* pnum2)
{
    int temp = *pnum1;
    *pnum1 = *pnum2;
    *pnum2 = temp;
}

/*************************************************
函数功能：实现对整型数组的冒泡排序
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void BubbleSort(int* arr, size_t size)
{
	int i = 0; 
	int j = 0;
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

/*************************************************
函数功能：快速排序(hoare版本)
函数参数：arr:存放整型变量的数组元素首地址
		  left:数组的左下标
		  right：数组的右下标
返回值：两个下标遍历数组时相遇的位置.
**************************************************/
int PartSort1(int* arr, int left, int right)
{
	int base = left;

	while (left < right)
	{
		while (left < right && (arr[right] >= arr[base]))
			right--;
		while (left < right && (arr[left] <= arr[base]))
			left++;
		if (left < right)
			swap(&arr[left], &arr[right]);
	}
	swap(&arr[base], &arr[left]);
	return left;
}
/*************************************************
函数功能：快速排序(挖坑法)
函数参数：arr:存放整型变量的数组元素首地址
		  left:数组的左下标
		  right：数组的右下标
返回值：两个下标遍历数组时相遇的位置.
**************************************************/
int PartSort2(int* arr, int left, int right)
{
	int base = arr[left];

	while (left < right)
	{
		while (left < right && (arr[right] >= base))
			right--;
		arr[left] = arr[right];

		while (left < right && (arr[left] <= base))
			left++;
		arr[right] = arr[left];
	}
	arr[left] = base;
	return left;
}

/*************************************************
函数功能：实现对整型数组的快速排序
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void QuickSort(int* arr, int left,int right)
{
	if (left >= right)
		return;

	int met = 0;

	met = PartSort2(arr, left, right);

	QuickSort(arr, left, met - 1);
	QuickSort(arr, met+1, right);
}


/*************************************************
函数功能：实现对整型数组的直接选择排序
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void SelectSort(int* arr, size_t size)
{
	size_t cur = 0;
	size_t  i = 0;
	size_t min = 0;

	while (cur < size)
	{
		for (i = cur; i < size; i++)
		{
			if (arr[i] < arr[min])
				min = i;
		}
		swap(&arr[cur],&arr[min]);
		cur++;
		min = cur;
	}
}

/*************************************************
函数功能：实现对整型数组的直接插入排序
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void InsertSort(int* arr, int size)
{
	int i = 0;
	int cur = 0;
	int temp = 0;
	for (i = 0; i < size-1; i++)
	{
		cur = i;
		temp = arr[cur+1];
		while (cur >= 0)
		{
			if (temp < arr[cur])
			{
				arr[cur + 1] = arr[cur];
				cur--;
			}
			else
				break;
		}
		arr[cur + 1] = temp;
	}
}


/*************************************************
函数功能：实现对整型数组的希尔排序
函数参数：arr:存放整型变量的数组元素首地址
		  size:数组中元素的个数
返回值：None.
**************************************************/
void HillSort(int* arr, int size)
{
	int i = 0;
	int cur = 0;
	int temp = 0;
	int gap = size / 2;
	while (gap)
	{
		for (i = 0; i < size - gap; i++)
		{
			cur = i;
			temp = arr[cur + gap];
			while (cur >= 0)
			{
				if (temp < arr[cur])
				{
					arr[cur + gap] = arr[cur];
					cur-=gap;
				}
				else
					break;
			}
			arr[cur + gap] = temp;
		}
		gap /= 2;
	}
}
