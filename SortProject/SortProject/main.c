/*
* ∏¥œ∞πÆπÃ£∫∞À¥Û≈≈–Ú÷–µƒ√∞≈›≈≈–Ú°¢—°‘Ò≈≈–Ú°¢≤Â»Î≈≈–Ú°¢œ£∂˚≈≈–Ú°£
* »’∆⁄£∫2022-11-22
*/

#include <stdio.h>
/*----------------------------√∞≈›≈≈–Ú£®START£©----------------------------*/
void swap(int* num1, int* num2)
{
	int temp = *num1;
	*num1 = *num2;
	*num2 = temp;
}

void BubbleSort(int* nums,size_t numSize)
{
	int i, j;
	for (i = 0; i < numSize - 1; i++)
	{
		for (j = i + 1; j < numSize; j++)
		{
			if (nums[i] > nums[j])
			{
				swap(&nums[i],&nums[j]);
			}
		}
	}
}

void Test01(void)
{
	int nums[10] = {1,8,6,5,3,4,7,2,9,0};

	BubbleSort(nums,sizeof(nums)/sizeof(nums[0]));

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ",nums[i]);
	}
	printf("\n");
}
/*----------------------------√∞≈›≈≈–Ú£®END£©----------------------------*/
/*----------------------------—°‘Ò≈≈–Ú£®START£©----------------------------*/
void SelectSort(int* nums, size_t numSize)
{
	int i = 0,j = 0;
	int minIndex = 0;
	for (i = 0; i < numSize-1; i++)
	{	
		minIndex = i;
		for (j = i + 1; j < numSize; j++)
		{
			if (nums[minIndex] > nums[j])
			{
				minIndex = j;
			}
		}
		swap(&nums[i], &nums[minIndex]);
	}
}

void Test02(void)
{
	int nums[10] = { 1,8,6,5,3,4,7,2,9,0 };

	SelectSort(nums, sizeof(nums) / sizeof(nums[0]));

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}
/*----------------------------—°‘Ò≈≈–Ú£®END£©----------------------------*/

/*----------------------------≤Â»Î≈≈–Ú£®START£©----------------------------*/

void InsertSort(int* nums, size_t numSize)
{
	int i = 0,j = 0;
	for (i = 1; i < numSize; i++)
	{
		int temp = nums[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (nums[j] > temp)
			{
				nums[j + 1] = nums[j];
			}
			else break;
		}
		nums[j + 1] = temp;
	}
}

void Test03(void)
{
	int nums[10] = { 1,8,6,5,3,4,7,2,9,0 };

	InsertSort(nums, sizeof(nums) / sizeof(nums[0]));

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}
/*----------------------------≤Â»Î≈≈–Ú£®END£©----------------------------*/


/*----------------------------œ£∂˚≈≈–Ú£®START£©----------------------------*/

void Shell(int* nums, size_t numSize, int gap)
{
	int i = 0, j = 0;
	for (i = gap; i < numSize; i++)
	{
		int temp = nums[i];
		for (j = i - gap; j >= 0; j -= gap)
		{
			if (nums[j] > temp)
			{
				nums[j + gap] = nums[j];
			}
			else break;
		}
		nums[j + gap] = temp;
	}
}

void ShellSort(int* nums, size_t numSize)
{
	int i = 0;
	int gap[3] = {4,2,1};
	for (i = 0; i < 1; i++)
	{
		Shell(nums, numSize, gap[i]);
	}
}

void Test04(void)
{
	int nums[10] = {5,7,1,3,9,6,8,2,4,0};

	ShellSort(nums, sizeof(nums) / sizeof(nums[0]));

	for (int i = 0; i < sizeof(nums) / sizeof(nums[0]); i++)
	{
		printf("%d ", nums[i]);
	}
	printf("\n");
}

/*----------------------------œ£∂˚≈≈–Ú£®END£©----------------------------*/

/**
  * @brief ÷˜∫Ø ˝
  * @param None.
  * @return None.
  */
int main(void)
{
	//Test01();

	//Test02();
	
	//Test03();

	Test04();

	return 0;
}
