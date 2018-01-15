#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

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

void test5() {
	int a[5] = { 3, 2, 5, 7, 8 };
	int length = sizeof(a)/sizeof(int);
	vector<int> v;
	v.reserve(length);
	for (int i = 0; i < length; i++) {
		v.push_back(a[i]);
	}
	
}

//int main() {
//	test5();
//}