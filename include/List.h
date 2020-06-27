#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
//#include <template>
#include "Ds.h"

namespace NS_LIST
{
    template <typename T>
    class List
    {
        public:
            /**
             * @brief 构造函数
             */
            List() : m_next_ptr(nullptr), m_list_len(0)
            {
            }

            /**
             * @brief 析构函数
             */
            ~List()
            {}

            /**
             * @brief 头插
             *
             * @prama pNode 插入节点
             *
             * @return  DS_OK 成功; DS_FAIL 失败
             */
            int32_t InsertNodeAtHead(List<T> *&pNode)
            {
                if (nullptr == pNode) {
                    return DS_FAIL;
                }

                NS_LIST::List<T> *pTemp = m_next_ptr;
                m_next_ptr = pNode;
                pNode->m_next_ptr = pTemp;

                ++m_list_len;
                return DS_OK;
            }

            /**
             * @brief 当前节点后插入节点
             *
             * @prama pNode 插入节点, pCur 当前节点
             *
             * @return  DS_OK 成功; DS_FAIL 失败
             */
            int32_t InsertNodeAtCur(List<T> *&pCur, List<T> *&pNode)
            {
                if (nullptr == pNode || nullptr == pCur) 
                {
                    return DS_FAIL;
                }

                NS_LIST::List<T> *pTemp = pCur->m_next_ptr;
                pCur->m_next_ptr = pNode;
                pNode->m_next_ptr = pTemp;

                ++m_list_len;
                return DS_OK;
            }

            /**
             * @brief 删除当前节点后一个节点
             *
             * @prama pCur 当前节点
             *
             * @return  DS_OK 成功; DS_FAIL 失败
             */
            int32_t DeleteCurNode(List<T> *&pCur, List<T> *&pDel)
            {
                if (nullptr == pCur) {
                    return DS_FAIL;
                }

                pDel = pCur->m_next_ptr;
                pCur->m_next_ptr = pCur->m_next_ptr->m_next_ptr;

                --m_list_len;
                return DS_OK;
            }

            /**
             * @brief 获取当前节点后面一个节点
             *
             * @prama pCur 当前节点
             *
             * @return DS_OK 成功; DS_FAIL 失败 
             */
            int32_t GetCurNode(List<T> *&pCur)
            {
                if (nullptr == pCur) {
                    pCur = m_next_ptr;
                    return DS_OK;
                }

                pCur = pCur->m_next_ptr;
                return DS_OK;
            }

        public:
            /**
             * @brief 数据元素
             */ 
            T m_list_data;

            /**
             * @brief 后向指针
             */
            NS_LIST::List<T> *m_next_ptr;
            
            /**
             * @brief 单链表长度
             */
            uint16_t m_list_len;
    };
}

#endif
