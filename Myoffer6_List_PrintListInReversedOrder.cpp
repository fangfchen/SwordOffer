#include"stdafx.h"
#include"list.h"
#include<iostream>
#include<vector>
using namespace std;
//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
//==================================================================

// ����:
//         head:    ��ͷ
// ����ֵ: 
//         vector<int>: ��������β��ͷ��˳������


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


