#include "stdafx.h"
#include<iostream>
#include<vector>
using namespace std;

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������
//==================================================================

// ����:
//        target:     �����ҵ���
//        array:      ��ά����(��vector�洢)
// ����ֵ:             
//        true  - �����ҵ��˸���
//        false - ����


bool Find(int target, vector<vector<int> > array) {
	int n = array.size();     //������
	int m = array[0].size();  //������
	if (n <= 0 || m <= 0) {
		return false;
	}
	int i = n - 1;
	int j = 0;
	while (i >= 0 && i<n && j >= 0 && j<m) {
		if (array[i][j] == target) {
			return true;
		}
		else if (array[i][j] < target) {
			j++;
		}
		else {
			i--;
		}
	}
	return false;
}

void test1() {
	printf("Test1:\n");

}

void run() {
	test1();
}