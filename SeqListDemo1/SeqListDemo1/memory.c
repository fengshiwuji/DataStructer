#include "memory.h"


/**
  * @brief 内存拷贝函数
  * @param dest:目的地址
  * @param src:源地址
  * @param count:拷贝字节数
  * @return 目的地址.
  */
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest&&src);
	void* temp = dest;
	/*若目的地址比源地址小则从前往后拷贝，否则反之*/
	if (dest < src)
	{
		while (count--)
		{
			*(char*)dest = *(char*)src;
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