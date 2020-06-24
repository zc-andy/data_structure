#ifndef _ARRAY_H_
#define _ARRAY_H_

#include <iostream>
#include <stdint.h>
#include <cstring>
#include "Ds.h"

#define STR_MAX_SIZE 1000

class Array
{
    public:
        /**
         * @brief 构造函数
         */         
        Array();

        /**
         * @brief 析构函数
         */         
        ~Array();

        /**
         * @brief 循环左移p单位
         *
         * @prama arr_src 原数组, len 字符串长度, offset 左移单位
         *
         * @return DS_OK 成功; DS_FAIL 失败
         */
        int32_t TurnLeftArray(char arr_src[], int32_t len, int32_t offset);

    private:
        /**
         * @brief 反转数组p字节 
         *
         * @prama arr_src 原数组, start 开始位置, offset 左移单位
         *
         * @return DS_OK 成功; DS_FAIL 失败
         */
        int32_t ReverseArray(char arr_src[], int32_t start, int32_t offset);

};

#endif
