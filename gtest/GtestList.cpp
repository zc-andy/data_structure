#include "List.h"
#include "gtest/gtest.h"

namespace 
{
    class TestList : public testing::Test
    {
        void SetUp() override
        {};

        void TearDown() override
        {};
    };
}

class Demo
{
    public:
        Demo() : m_iValue(0)
        {}

        ~Demo()
        {}

    public:
        int32_t m_iValue;
        char m_ch;
};

TEST_F(TestList, TEST_LIST)
{
    NS_LIST::List<Demo> m_List;

    NS_LIST::List<Demo> *pNode1 = new NS_LIST::List<Demo>;
    pNode1->m_list_data.m_iValue = 1;
    pNode1->m_list_data.m_ch = 'A';
    ASSERT_EQ(DS_OK, m_List.InsertNodeAtHead(pNode1));
    NS_LIST::List<Demo> *pCur = pNode1;

    pNode1 = new NS_LIST::List<Demo>;
    pNode1->m_list_data.m_iValue = 3;
    pNode1->m_list_data.m_ch = 'C';
    ASSERT_EQ(DS_OK, m_List.InsertNodeAtHead(pNode1));

    pNode1 = new NS_LIST::List<Demo>;
    pNode1->m_list_data.m_iValue = 2;
    pNode1->m_list_data.m_ch = 'B';
    ASSERT_EQ(DS_OK, m_List.InsertNodeAtCur(pCur, pNode1));
    
    pNode1 = new NS_LIST::List<Demo>;
    pNode1->m_list_data.m_iValue = 4;
    pNode1->m_list_data.m_ch = 'D';
    ASSERT_EQ(DS_OK, m_List.InsertNodeAtCur(pCur, pNode1));

    NS_LIST::List<Demo> *pTemp = nullptr;
    ASSERT_EQ(DS_OK, m_List.GetCurNode(pTemp));
    ASSERT_EQ(3, pTemp->m_list_data.m_iValue);
    ASSERT_EQ(DS_OK, m_List.GetCurNode(pTemp));
    ASSERT_EQ(1, pTemp->m_list_data.m_iValue);
    ASSERT_EQ(DS_OK, m_List.GetCurNode(pTemp));
    ASSERT_EQ(4, pTemp->m_list_data.m_iValue);
    ASSERT_EQ(DS_OK, m_List.GetCurNode(pTemp));
    ASSERT_EQ(2, pTemp->m_list_data.m_iValue);
}
