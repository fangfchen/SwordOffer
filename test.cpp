#include "stdafx.h"
#include<iostream>
#include<vector>
#include <iterator> 
using namespace std;

int test_sizeof() {  //sizeof
	int a[] = { 1,2,3,4,5 };
	int size1 = sizeof(a);
	int size2 = sizeof(a[0]);
	int size3 = size1 / size2;
	//cout << size1 << size2 << size3;
	printf("%d, %d, %d\n", size1, size2, size3);

	int* b = a;
	int size4 = sizeof(b);
	cout << size4 << endl;
	return 0;
}

void test1() {  //���� sizeof memset��ʼ��
	int a[10];
	cout << a[2] << endl;   //�����
	memset(a, 0, sizeof(a));
	cout << a[2] << endl;   //0

	int length = 10;
	int* const b = (int*)malloc(sizeof(int)*length);
	cout << sizeof(b) << endl;  //4����Ȼ��b����������ڴ棬������Ϊ��������intָ�룬����sizeof(b)��4������������
	cout << b[2] << endl;	//�����
	memset(b, 0, sizeof(b));
	cout << b[2] << endl;	//�����
	cout << b[0] << endl;   //0
	memset(b, 0, sizeof(int)*length);   //��malloc�����memset����ֱ����sizeof(b)��Ҫдsizeof(int)*length������
	cout << b[2] << endl;

	int* const c = (int*)calloc(length,sizeof(int));  //calloc(��������n����Сһ�����ڴ�ռ�)���Զ���ʼ��Ϊ0����������
	cout << c[2] << endl;
	
}

void swap(int& a, int& b) {   //����
	int c = a;
	a = b;
	b = c;
}

void test2() {  //����
	int a = 1;
	int b = 2;
	printf("Original: a = %d, b = %d\n", a, b);   //1 2
	swap(a, b);
	printf("After swap: a = %d, b = %d\n", a, b); //2 1 �������ú�swap�б仯������Ҳ��仯��
}


void test3() {  //����
	int a = 1;
	int& b = a;
	printf("a = %d, b = %d\n", a, b); //1 1
	b = 3;
	printf("a = %d, b = %d\n", a, b); //3 3
	a = 5;
	printf("a = %d, b = %d\n", a, b); //5 5 �����ú�a,b��ֵʼ�ձ���һ�£�����
	int& c = a;
	c = 7;
	printf("a = %d, b = %d, c= %d\n", a, b, c);
	int& d = b;
	d = 9;
	printf("a = %d, b = %d, c= %d, d= %d\n", a, b, c, d);
}

void test4() {  //bool�Ͷ�̬�����ʼ��
	bool* hash = new bool[5]();
	for (int i = 0; i < 5; i++) {
		if (hash[i] == true) {
			cout << "true" << endl;
		}
		else {
			cout << "false" << endl;
		}
	}
}

void test5() {   //vector��ʼ��
	int a[5] = { 3, 2, 5, 7, 8 };
	int length = sizeof(a)/sizeof(int);
	//��push_back��һ����
	vector<int> v1;       //��ֱ�������ﶨ��(length)����ᶼ��ʼ��Ϊ0��push_back�������е�0���������ӣ�(0 0 0 0 0 3 2 5 7 8)
	v1.reserve(length);   //��д���Ҳ��,��д�˿��Լ����ڴ�������
	for (int i = 0; i < length; i++) {
		v1.push_back(a[i]);
	}
	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));  //��ӡvector����
	cout << endl;
	
	//����㡿����ʱֱ�Ӵ�����֪�����ͷ��βָ��
	vector<int> v2(&a[0], &a[length]);
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//�������insert��֪�����ͷ��βָ��
	vector<int> v3;	     //��ֱ�������ﶨ��(length)����ᶼ��ʼ��Ϊ0��insert�����һ��0(3 2 5 7 8 0 0 0 0 0)
	v3.reserve(length);  //��д���Ҳ��,��д�˿��Լ����ڴ�������
	v3.insert(v3.begin(), &a[0], &a[length]);
	copy(v3.begin(), v3.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//��άvector
	//1 2 8  9
	//2 4 9  12
	//4 7 10 13
	//6 8 11 15
	int n = 4;
	int m = 4;
	int a4[4][4] = { { 1, 2, 8, 9 },{ 2, 4, 9, 12 },{ 4, 7, 10, 13 },{ 6, 8, 11, 15 } };
	vector<vector<int>> v4(n, vector<int>(m));  //�����άvector��
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			v4[i][j] = a4[i][j];
		}
		copy(v4[i].begin(), v4[i].end(), ostream_iterator<int>(cout, " "));
		cout << endl;
	}
}

void test6() {		//vector
	vector<int> v(10);
	//vector<double> v(10);       //�����СΪ10������ʼ��Ϊ0������ʱ��push_back������v[10]��
	//vector<double> v(10, 2.5);  //��ʼ��ÿ����Ϊ2.5
	//vector<int> v2(v1);         //��������

	//v.push_back(3);        //��ĩβ���3
	//v.insert(v.end(), 10); //��ĩβ����10����ָ��һ����������
	//v[i] = 5;              //�ѵ�iλ��ֵΪ5


	//v.size()    //vector��С��Ԫ�ظ�����
	//v.empyt()   //�ж϶����Ƿ�Ϊ�գ���Ϊ�շ���1�����շ���0
	//v.clear()   //��ն���
	//v.front()   //vector�ĵ�һ��Ԫ��ֵ
	//v.back()    //vector�����һ��Ԫ��ֵ
	//v.push_back(a);    //��ĩβ���һ����Ԫ��a
	//v.pop_back();      //ɾ��ĩβԪ�� ע������Ϊ��ʱ������pop��
	//if (!v.empty()) v.pop_back();  //�жϲ�Ϊ����ɾ��
	//v.erase(v.begin()) //ɾ����ͷ��Ԫ��
		
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}

	vector<int>::iterator i;
	for (i = v.begin(); i != v.end(); i++) {
		cout << *i << endl;
	}
}


//int main() {
//	test6();
//}
