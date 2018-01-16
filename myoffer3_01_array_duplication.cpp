#include "stdafx.h"
#include<iostream>
using namespace std;

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ������3��һ�����ҳ��������ظ�������
// ��Ŀ����һ������Ϊn����������������ֶ���0��n-1�ķ�Χ�ڡ�������ĳЩ�������ظ��ģ�����֪���м��������ظ��ˣ�
// Ҳ��֪��ÿ�������ظ��˼��Ρ����ҳ�����������һ���ظ������֡����磬������볤��Ϊ7������{2, 3, 1, 0, 2, 5, 3}��
// ��ô��Ӧ��������ظ�������2����3��
//==================================================================

// Parameters:
//        numbers:     an array of integers
//        length:      the length of array numbers
//        duplication: (Output) the duplicated number in the array number
// Return value:       true if the input is valid, and there are some duplications in the array number
//                     otherwise false

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
//        duplication: (���) �����е�һ���ظ�������
// ����ֵ:             
//        true  - ������Ч�����������д����ظ�������
//        false - ������Ч������������û���ظ�������
class solution3 {
public:
	bool duplicate1(int numbers[], int length, int* duplication) {
		/***--------------------------------------------------------------
		˼·1(���ı�ԭ���飬���ù�ϣ��)��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(n)
		������ϣ�����������е�Ԫ�أ���ÿ��Ԫ�أ���������ڹ�ϣ���У��ͼӽ�ȥ��������ڹ�ϣ���У�˵���Ѿ��ظ������ˣ��������Ǵ𰸡�
		����Ĺ�ϣ�����ֱ����һ������Ϊn��������ģ�⣬��ʼֵΪ0����false�������統ǰ������������k���������±�Ϊk��λ���Ƿ�Ϊ1����true����
		�������������Ϊk��λ���Ƿ�Ϊ1����true�����������˵���Ѿ��ظ���
		ע�������ҵ��ĵ�һ����Ϊ��һ���ظ�������
		--------------------------------------------------------------***/
		if (numbers == nullptr || length <= 0) {  //������Ϊ��ָ��򳤶�<=0������Ч
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i]<0 || numbers[i]>length - 1) {      //�����������Χ������Ч(�赥��һ��ѭ������ֹ�ظ����ĺ�������Ч����)
				return false;
			}
		}

		int* record = new int[length]();  //�������Ϊ(0)�����ֳ�ʼ���������ϱ�����clang c++������Ȼ���ؿ������У�����
		//����Ҳ���Խ���bool�ͻ�vector
		for (int i = 0; i<length; i++) {
			int temp = numbers[i];
			if (record[temp] != 0) {
				*duplication = temp;
				return true;
			}
			else{
				record[temp] = 1;
			}
		}
		delete[]record;
		return false;   //�����ظ������򷵻�false
	}

	bool duplicate2(int numbers[], int length, int* duplication) {
		/***--------------------------------------------------------------
		˼·2����ԭ�������ţ���ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
		��Ϊ���鳤��Ϊn��ÿ��������0~n-1��Χ�ڣ��������������û���ظ�����ô�������������iӦ�ó������±�i��λ�á�
		�����������飬��ͷ��β����ɨ�裬ɨ�赽����i��ʱ��Ϳ������±��Ƿ�Ϊi�������˵��������ȷ��λ���ϣ�
		������ǣ����ٿ��±�Ϊi��λ���Ƿ��Ѿ�����i������ǣ�˵��i�Ѿ����ظ���������ǣ��򽻻�i���±�Ϊi������
		ע�������ҵ��Ĳ�һ���ǵ�һ���ظ�������
		--------------------------------------------------------------***/
		if (numbers == nullptr || length <= 0) {  //������Ϊ��ָ��򳤶�<=0������Ч
			return false;
		}
		for (int i = 0; i < length; i++) {
			if (numbers[i]<0 || numbers[i]>length - 1) {      //�����������Χ������Ч(�赥��һ��ѭ������ֹ�ظ����ĺ�������Ч����)
				return false;
			}
		}
		for (int i = 0; i < length; i++) {
			while (numbers[i] != i) {
				if (numbers[numbers[i]] == numbers[i]) {
					*duplication = numbers[i];
					return true;
				}
				else {
					int temp = numbers[i];    //����
					numbers[i] = numbers[numbers[i]];
					numbers[temp] = temp;     //����һ��Ҫ��numbers[temp]����Ϊnumbers[i]�е�ֵ�Ѿ����ı䣡
				}
			}
		}
		return false;

	}

	//======================test==========================

	//1���ظ�
	void test1(int funclabel) {
		printf("test1:\n");
		int numbers[] = { 1,5,4,3,8,6,0,7,5 }; 
		int length = 9;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: 5\n\n");
	}

	//����ظ�
	void test2(int funclabel) {
		printf("test2:\n");
		int numbers[] = {0, 1, 5, 1, 4, 5 };
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: 1 or 5\n\n");
	}

	//���ظ�
	void test3(int funclabel) {
		printf("test3:\n");
		int numbers[] = { 0, 1, 3, 2, 5, 4 };
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}

	//������
	void test4(int funclabel) {
		printf("test4:\n");
		int* numbers = nullptr;
		int length = 0;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}

	//��ΧԽ��
	void test5(int funclabel) {
		printf("test5:\n");
		int numbers[] = {2,8,3,4,2,0};
		int length = 6;
		int dupli = 0;
		bool result = false;
		if (funclabel == 1) {
			result = duplicate1(numbers, length, &dupli);
		}
		else {
			result = duplicate2(numbers, length, &dupli);
		}
		if (result == true) {
			cout << dupli << endl;
		}
		else {
			cout << "False!" << endl;
		}
		printf("Correct Answer: False\n\n");
	}


	void run() {
		//bool(*func)(int* , int, int* ); //���庯��ָ��func������ָ��ĺ�������3���������ҷ���bool
		int funclabel = 1;
		test1(funclabel);
		test2(funclabel);
		test3(funclabel);
		test4(funclabel);
		test5(funclabel);
	}
};



//int main() {
//	solution3 s;
//	s.run();
//}
