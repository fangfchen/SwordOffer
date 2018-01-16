#include "stdafx.h"
#include<iostream>
using namespace std;

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����
//==================================================================

// ����:
//         str:     �ַ���
//         length:  �ַ�������(����������в��죬����ָ���ǿ��õ�������)
// ����ֵ: ��             

/***--------------------------------------------------------------
˼·��ʱ�临�Ӷ�O(n)
�ȱ���һ���ַ���ͳ�ƿո�����������������ַ������滻����ܳ���=ԭ����+2*�ո�����
�������Ӻ���ǰ�����ơ��滻�ַ�����׼������ָ��p1��p2��p1ָ��ԭ�ַ�����ĩβ��p2ָ���滻���ַ�����ĩβ����ʵ�϶���һ���ַ����У���
���p1�ϵ�ֵ���ǿո����Ƶ�p2λ���ϣ�����ǿո���p2��ǰ��λ����"%20"��
p1��p2������ǰ�ƣ�ֱ��p1��p2�غϡ�
--------------------------------------------------------------***/

class solution5 {
public:
	void replaceSpace(char *str, int length) {
		if (str == nullptr) { return; }
		//һ���Դ�ӡ�ַ�����3������
		//cout << str <<endl;  
		//printf("%s\n", str);
		//puts(str);            //�Դ��س�
		int num_space=0;
		for (int i = 0; i < length; i++) {
			if (str[i] == ' ') num_space++;  //ע�����������ַ���˫�������ַ���
		}
		int new_length = length + num_space * 2;
		int p1 = length;  //������
		int p2 = new_length;
		while (p1 < p2) {
			if (str[p1] != ' ') {
				str[p2] = str[p1];
			}
			else {   //str[p1]==' '
				str[p2] = '0';
				str[--p2] = '2';
				str[--p2] = '%';
			}
			p1--;
			p2--;
		}
		//cout << str << endl; //test
	}

	void test1() {
		cout << "Test1:" << endl;
		char str[] = "i am chinese!";
		int length = 14;
		replaceSpace(str, length);
		cout << "Correct Answer:\ni%20am%20chinese!\n\n";
		
	}

	void test2() {
		cout << "Test2:" << endl;
		char str[] = " ";
		int length = 2;
		replaceSpace(str, length);
		cout << "Correct Answer:\n%20\n\n";
	}

	void test3() {
		cout << "Test3:" << endl;
		char str[] = "wow    ";
		int length = 8;
		replaceSpace(str, length);
		cout << "Correct Answer:\nwow%20%20%20%20\n\n";
	}

	void test4() {
		cout << "Test4:" << endl;
		char str[] = "";
		int length = 1;
		replaceSpace(str, length);
		cout << "Correct Answer:���ַ���\n\n";
	}

	void run() {
		test1();
		test2();
		test3();
		test4();
	}
};

//int main() {
//	solution5 s;
//	s.run();
//}