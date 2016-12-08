#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::endl;
using std::cin;

/*Ͱ���� */

//���δ��������������һ��Ԫ��ֵ
int GetMaxVal(int* arr, int len)
{
	int maxVal = arr[0]; //�������Ϊarr[0]

	for (int i = 1; i < len; i++)  //�����Ƚϣ��ҵ���ľ͸�ֵ��maxVal
	{
		if (arr[i] > maxVal)
			maxVal = arr[i];
	}

	return maxVal;  //�������ֵ
}
void BucketSort(int *numbers, int length){
	if (numbers == NULL || length <= 0){
		cout << "wrong input!";
		return;
	}
	int size = GetMaxVal(numbers,length) + 1;
	vector<int> bucket(size);
	for (int i = 0; i < length + 1; i++){
		bucket[i] = 0;
	}
	// ����������ÿ��Ԫ�س��ֵĴ���
	for (int i = 0; i < length; i++){
		int j = numbers[i];
		bucket[j] += 1;
	}
	// ����
	int count = 0;
	for (int i = 0; i < size; i++){
		if (bucket[i] > 0){
			for (int j = 0; j < bucket[i]; j++){
				numbers[count] = i;
				count++;
			}
		}
	}

}

void Test(int *numbers, int length){
	if (numbers == NULL)
		cout << "Test for NULL:";
	else{
		cout << "Test for array:{";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "}\n";
			else
				cout << ", ";
		}
	}
	BucketSort(numbers, length);
	if (numbers != NULL){
		cout << "after using BucketSort: ";
		for (int i = 0; i < length; i++){
			cout << numbers[i];
			if (i == length - 1)
				cout << "\n";
			else
				cout << ", ";
		}
	}
}

// ����
int main(void){
	int t1[] = { 1, 3, 5, 2, 4, 8, 10, 9 };
	int t2[] = { 1, 1, 3, 2, 2, 5, 6, 2, 10, 12, 8, 3 };
	Test(t1, 8);
	Test(t2, 12);
	Test(NULL, 2);


	system("pause");
	return 0;
}