struct ListNode {
	int val;
	ListNode *next;
	//struct ListNode *next; 
	//ListNode(int x) :  //���������ַ�ʽ����ֵΪx�Ľڵ�
	//	val(x), next(NULL) {
	//}
}; 

ListNode* CreateListNode(int value);
void ConnectListNodes(ListNode* pCurrent, ListNode* pNext);
void PrintList(ListNode* pHead);
void DestroyList(ListNode* pHead);
void PushBackNode(ListNode** ppHead, int value);
void RemoveNode(ListNode** ppHead, int value);