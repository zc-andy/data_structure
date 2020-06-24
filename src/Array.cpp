#include "Array.h"

/** 构造函数 **/
Array::Array()
{}

/** 析构函数 **/
Array::~Array()
{}

/** 数组左移n单位 **/
int32_t Array::TurnLeftArray(char arr_src[], int32_t len, int32_t offset)
{
	if (len != strnlen(arr_src, STR_MAX_SIZE) || offset > len)
	{
		std::cout<<"#Array::TurnLeftArray:14 str size error!"<<std::endl;
		return DS_FAIL;
	}

	ReverseArray(arr_src, 0, offset);
	ReverseArray(arr_src, offset, len - offset);
	ReverseArray(arr_src, 0, len);

	return DS_OK;
}

/** 数组n单位反转 **/
int32_t Array::ReverseArray(char arr_src[], int32_t start, int32_t offset)
{
	if (start >= strnlen(arr_src, STR_MAX_SIZE) 
					|| offset > strnlen(arr_src, STR_MAX_SIZE))
	{
		std::cout<<"#Array::ReverseArray:29 start pos or offset error!"<<std::endl;
		return DS_FAIL;
	}

	int32_t index = start;
	int32_t end = start + offset - 1;

	if (end >= strnlen(arr_src, STR_MAX_SIZE)) 
	{
		std::cout<<"#Array::ReverseArray:39 end pos error!"<<std::endl;
		return DS_FAIL;
	}

	for (; index < end; ++index, --end)
	{
		char temp = arr_src[index];
		arr_src[index] = arr_src[end];
		arr_src[end] = temp;
	}

	return DS_OK;
}
