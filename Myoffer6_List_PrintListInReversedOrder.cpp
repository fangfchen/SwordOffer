#include"stdafx.h"
#include"list.h"
#include<iostream>
#include<vector>
using namespace std;
//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。
//==================================================================

// 参数:
//         head:    表头
// 返回值: 
//         vector<int>: 把链表按从尾到头的顺序排列


struct ListNode {
    int val;
    ListNode *next;
	//struct ListNode *next; 
    //ListNode(int x) :
    //        val(x), next(NULL) {
    //}
};



class Solution6 {
public:
	void reverse_order_recursive(ListNode* pnode, vector<int>& v) {
		if (pnode->next != nullptr) {
			reverse_order_recursive(pnode->next, v);
			v.push_back(pnode->val);
		}
	}
	
	vector<int> printListFromTailToHead(ListNode* head) {
		vector<int> v;
		if (head == nullptr) return v;
		reverse_order_recursive(head, v);
		return(v);
	}
	
	//============================test===============================

	void test1() {
		ListNode* pHead;
		PushBackNode(&pHead, 1); //???????

	}

	void run() {
		test1();
	}
};


