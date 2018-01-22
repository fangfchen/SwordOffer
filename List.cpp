#include"stdafx.h"
#include<iostream>
#include"List.h"
using namespace std;



//�����ڵ�
ListNode* CreateListNode(int value) {
	ListNode* pNode = new ListNode();
	pNode->val = value;
	pNode->next = nullptr;  //Ĭ��nextΪ��
	return pNode;
}

//����2���ڵ�
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext) {
	if (pCurrent == nullptr) {  //�����ǰ�ڵ�ָ��Ϊ�գ��򱨴��˳�
		printf("Error to connect 2 nodes.\n");
	}
	else {
		pCurrent->next = pNext;
	}
}

//��ӡ����
void PrintList(ListNode* pHead) {
	//printf("PrintList starts.\n");
	ListNode* pNode = pHead;
	while (pNode != nullptr) {
		cout << pNode->val << " ";
		pNode = pNode->next;
	}
	cout << endl;
	//printf("PrintList ends.\n");
}

//��������ɾ�����нڵ㣩
void DestroyList(ListNode* pHead) {
	ListNode* pNode = pHead;
	ListNode* pNext;
	while (pNode != nullptr) {
		pNext = pNode->next;
		delete pNode;
		pNode = pNext;
	}
}

//������ĩβ���һ���ڵ㣨����push_back(value)��
void PushBackNode(ListNode** ppHead, int value) {
	//�½��ڵ�
	ListNode* pNew = new ListNode();
	pNew->val = value;
	pNew->next = nullptr;
	//�ж��Ƿ�Ϊ������(��ͷΪ��)
	if (*ppHead == nullptr) {  
		*ppHead = pNew;  //��Ϊ�գ���ͷָ���½ڵ�
	}
	else {
		ListNode* pNode = *ppHead;
		while (pNode->next != nullptr) {  
			pNode = pNode->next;
		}
		pNode->next = pNew;  //��ĩβ�ڵ�ָ���½ڵ�
	}
}

//���������ҵ�ֵΪvalue�Ľڵ㲢ɾ��(����remove(value))
void RemoveNode(ListNode** ppHead, int value) {
	//��������ͷΪ�գ�
	if (ppHead == nullptr || *ppHead == nullptr) {
		cout << "The List is empty.\n";
		return;
	}
	//��ͷָ��ĵ�һ���ڵ����Ҫɾ���ĵ㣨��ı��ͷ��
	ListNode* pDeleteNode = nullptr;
	if ((*ppHead)->val == value) {
		pDeleteNode = *ppHead;
		*ppHead = (*ppHead)->next;
	}
	else {
		ListNode* pNode = *ppHead;
		while (pNode->val != value && pNode != nullptr) {
			pNode = pNode->next;
		}
		if (pNode->val == value) {
			pDeleteNode = pNode;
			pNode = pNode->next;
		}
	}
	//ɾ���ڵ�
	if (pDeleteNode != nullptr) {
		delete pDeleteNode;
		pDeleteNode = nullptr;
	}
}

