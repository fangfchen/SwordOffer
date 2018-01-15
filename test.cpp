#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

void test1() {  //数组 sizeof memset初始化
	int a[10];
	cout << a[2] << endl;   //随机数
	memset(a, 0, sizeof(a));
	cout << a[2] << endl;   //0

	int length = 10;
	int* const b = (int*)malloc(sizeof(int)*length);
	cout << sizeof(b) << endl;  //4（虽然给b数组分配了内存，但是因为他现在是int指针，所以sizeof(b)是4！！！！！）
	cout << b[2] << endl;	//随机数
	memset(b, 0, sizeof(b));
	cout << b[2] << endl;	//随机数
	cout << b[0] << endl;   //0
	memset(b, 0, sizeof(int)*length);   //用malloc后进行memset不能直接用sizeof(b)！要写sizeof(int)*length！！！
	cout << b[2] << endl;

	int* const c = (int*)calloc(length,sizeof(int));  //calloc(连续分配n个大小一样的内存空间)会自动初始化为0！！！！！
	cout << c[2] << endl;
	
}

void swap(int& a, int& b) {   //引用
	int c = a;
	a = b;
	b = c;
}

void test2() {  //引用
	int a = 1;
	int b = 2;
	printf("Original: a = %d, b = %d\n", a, b);   //1 2
	swap(a, b);
	printf("After swap: a = %d, b = %d\n", a, b); //2 1 用了引用后，swap中变化，这里也会变化！
}


void test3() {  //引用
	int a = 1;
	int& b = a;
	printf("a = %d, b = %d\n", a, b); //1 1
	b = 3;
	printf("a = %d, b = %d\n", a, b); //3 3
	a = 5;
	printf("a = %d, b = %d\n", a, b); //5 5 （引用后，a,b的值始终保持一致！！）
	int& c = a;
	c = 7;
	printf("a = %d, b = %d, c= %d\n", a, b, c);
	int& d = b;
	d = 9;
	printf("a = %d, b = %d, c= %d, d= %d\n", a, b, c, d);
}

void test4() {  //bool型动态数组初始化
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