#include"stdafx.h"
#include<iostream>
#include<vector>
#include<stack>
#include"List.h"
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

 
//struct ListNode {  //"List.cpp"���Ѿ�����
//    int val;
//    ListNode *next;
//	//struct ListNode *next; 
//    //ListNode(int x) :
//    //        val(x), next(NULL) {
//    //}
//};

class Solution6 {
public:
/***--------------------------------------------------------------
˼·1�����á�ջ�����Ƚ���������ʡ�
--------------------------------------------------------------***/
	vector<int> printListFromTailToHead1(ListNode* phead) {
		vector<int> v;
		if (phead == nullptr) return v;
		stack<int> s;
		ListNode* pnode = phead;
		while (pnode != nullptr) {
			s.push(pnode->val);
			pnode = pnode->next; //�ǵü�������ָ�������������ǣ�����
		}
		while (!s.empty()) {
			v.push_back(s.top());
			s.pop();
		}
		return(v);
	}

/***--------------------------------------------------------------
˼·2�����õݹ�ġ�ѹջ�����ʡ�
--------------------------------------------------------------***/
	void reverse_order_recursive(ListNode* pnode, vector<int>& v) {
		if (pnode->next != nullptr) {
			reverse_order_recursive(pnode->next, v);
		}
		v.push_back(pnode->val);  //Ҫ����if���棡������ĩβԪ�طŲ���ȥ��
	}
	
	vector<int> printListFromTailToHead2(ListNode* phead) {
		vector<int> v;
		if (phead == nullptr) return v;
		reverse_order_recursive(phead, v);
		return(v);
	}
	
	//============================test===============================
	//��include"List.cpp"�еĺ�������ΪList.cpp���Ѿ�����stuct�����ﲻ���ٶ��壩
	void Test(ListNode* phead) {
		vector<int> v = printListFromTailToHead1(phead);
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << endl;
	}

	//1->2->3->4
	void test1() {
		printf("Test1:\n");
		ListNode* pHead = nullptr; //һ��Ҫ��ʼ��Ϊ��ָ�룡����
		PushBackNode(&pHead, 1); 
		PushBackNode(&pHead, 2);
		PushBackNode(&pHead, 3);
		PushBackNode(&pHead, 4);
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	//ֻ��һ���ڵ�1
	void test2() {
		printf("Test2:\n");
		ListNode* pHead = nullptr;
		PushBackNode(&pHead, 1);
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	//������
	void test3() {
		printf("Test3:\n");
		ListNode* pHead = nullptr;
		printf("Original List:\n");
		PrintList(pHead);
		printf("My Answer:\n");
		Test(pHead);
	}

	void run() {
		test1();
		test2();
		test3();
	}
};

int main() {
	Solution6 s;
	s.run();
}


