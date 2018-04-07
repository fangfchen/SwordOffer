#include"stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。
//==================================================================

class Solution11 {
public:

	int findmin(int a, int b) {
		if (a <= b)
			return a;
		else
			return b;
	}

	int minNumberInRotateArray(vector<int> rotateArray) {
		if (rotateArray.size() <= 0)
			return 0;
		if (rotateArray.size() == 1)
			return rotateArray[0];

		int start = 0;
		int end = rotateArray.size() - 1;
		while (end - start >= 1) {
			if (end - start == 1) {
				return findmin(rotateArray[start],rotateArray[end]);
			}
			
			//如果有个区间前>后，则最小值一定在这个区间中
			int mid = (start + end) / 2;
			if (rotateArray[start]>rotateArray[mid]) 
				end = mid;
			if (rotateArray[mid]>rotateArray[end])
				start = mid;
			
			//若都是前<=后，则不能缩小范围，只能顺序查找
			if (rotateArray[start] <= rotateArray[mid] && rotateArray[mid] <= rotateArray[end]) { 
				int min = rotateArray[start];
				for (int i = start+1; i <= end; i++) {
					if (rotateArray[i] < min) {
						min = rotateArray[i];
					}
				}
				return min;
			}
		}
	}


	//======================test==========================
	void Test(vector<int> rotarr) {
		cout << minNumberInRotateArray(rotarr)<<endl;
		cout << endl;
	}

	void PrintArray(vector<int> rotarr) {
		for (int i = 0; i < rotarr.size(); i++) {
			cout << rotarr[i] << " ";
		}
		cout << endl;
	}

	void test1() {
		vector<int> rotarr = { 4,5,1,2,3 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n1\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test2() {
		vector<int> rotarr = { 2,2,3,4,4,5,1,1};
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n1\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test3() {
		vector<int> rotarr = { 1,1,1,1,0,1 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n0\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test4() {
		vector<int> rotarr = { 3,1,2 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n1\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test5() {
		vector<int> rotarr = { 1 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n1\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test6() {
		vector<int> rotarr = { 0,1 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n0\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void test7() {
		vector<int> rotarr = { 1,0 };
		printf("Original Array:\n");
		PrintArray(rotarr);
		printf("Correct Answer:\n0\n");
		printf("My Answer:\n");
		Test(rotarr);
	}

	void run() {
		test1();
		test2();
		test3();
		test4();
		test5();
		test6();
		test7();
	}
};

int main() {
	Solution11 s;
	s.run();
}