#include "memory.h"


/**
  * @brief �ڴ濽������
  * @param dest:Ŀ�ĵ�ַ
  * @param src:Դ��ַ
  * @param count:�����ֽ���
  * @return Ŀ�ĵ�ַ.
  */
void* my_memmove(void* dest, const void* src, size_t count)
{
	assert(dest&&src);
	void* temp = dest;
	/*��Ŀ�ĵ�ַ��Դ��ַС���ǰ���󿽱�������֮*/
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