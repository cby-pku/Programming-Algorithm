////////�鲢����
//////#include<iostream>
//////#include<algorithm>
//////#include<stdio.h>
//////int a[10] = { 13,17,15,12,18,19,21,35,4,5 };
//////int b[10];
//////void Merge(int a[], int s, int mid, int e, int tmp[]) {
//////	//����˫ָ�뷨�ϲ�
//////	int pb = 0; int p1 = s, p2 = mid + 1;
//////	while (p1 <= mid && p2 <= e) {
//////		if (a[p1] < a[p2]) {
//////			tmp[pb++] = a[p1++];
//////		}
//////		else {
//////			tmp[pb++] = a[p2++];
//////		}
//////	}
//////		while (p2 <= e) {
//////			tmp[pb++] = a[p2++];
//////		}
//////
//////		while (p1 <= mid) {
//////			tmp[pb++] = a[p1++];
//////		}
//////		//tmp���Ѿ��ź�����ˣ����������ǰ������ƻ�a
//////		for (int i = 0; i < e - s + 1; ++i) {//e-s+1����
//////			a[s + i] = tmp[i];//����ұ�����
//////		}
//////}
//////void MergeSort(int a[], int s, int e, int tmp[]) {
//////	if (s < e) {
//////		int m = s + (e - s) / 2;
//////		MergeSort(a, s, m, tmp);
//////		MergeSort(a, m + 1, e, tmp);
//////		//��ʵ�ؼ��Ĳ������������һ��
//////		Merge(a, s, m, e, tmp);//ʵ���˶Ե�Ԫ�ĺϲ�
//////	}
//////}
//////using namespace std;
//////int main() {
//////	int size = sizeof(a) / sizeof(int);
//////	MergeSort(a, 0, size - 1, b);//����ұ�����
//////	for (int i = 0; i < size; i++) {
//////		cout << a[i] << " ";
//////	}
//////	cout << endl; return 0;
//////}
//////
////////2����������
////#include<iostream>
////#include<stdio.h>
////#include<algorithm>
////using namespace std;
////void swap(int &a, int &b) {
////	int temp = a;
////	a = b;
////	b = temp;//���õ�ַ,����������
////}
////void QuickSort(int a[], int s, int e) {//�����������ֱ�Ӹ���
////	if (s >= e)return;
////	int k = a[s];
////	int i = s, j = e;
////	while (i != j) {
////		while (j > i&&a[j] >= k) {
////			j--;
////		}
////		swap(a[i], a[j]);
////		while (i < j&&a[i] <= k) {//��Ϊ���ܾ�������Ĺ���i�Ѿ�����j��
////			i++;
////		}
////		swap(a[i], a[j]);
////	}//�������a[i]=k;
////	QuickSort(a, s, i - 1);
////	QuickSort(a, i + 1, e);
////}
////int a[10] = { 13,17,15,12,18,19,21,35,4,5 };
////int main() {
////	int size = sizeof(a) / sizeof(int);
////	QuickSort(a, 0, size - 1);//����ұ�����
////	for (int i = 0; i < size; i++) {
////		cout << a[i] << " ";
////	}
////	cout << endl; return 0;
////}
//
////3:���ǰm�������
////key��k��ҪŪ��
//#include<iostream>
//#include<stdio.h>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//int a[10] = { 13,17,15,12,18,19,21,35,4,5 };
//void swap(int &a, int &b) {
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//int num(int a[], int k) {
//	int i;
//	for ( i = 0; i < 10; i++) {
//		if (a[i] == k)break;
//	}
//	return i;//��������ֵ
//}
//void arrangeRight(int key,int a[],int s,int e) {
//	if (s >= e)return;//����������ֹ����
//	int k = a[s];
//	int i = s, j = e;
//	while (i != j) {
//			while (j > i&&a[j] >= k) {
//				j--;
//			}
//			swap(a[i], a[j]);
//			while (i < j&&a[i] <= k) {//��Ϊ���ܾ�������Ĺ���i�Ѿ�����j��
//				i++;
//			}
//			swap(a[i], a[j]);
//	}//�������a[i]=k;
//	//����
//	int temp = num(a, k);//��������
//	int result = 10-temp;
//	if (result == key)return;
//	else if (result > key) {
//		arrangeRight(key, a, temp + 1, e);
//	}
//	else if (result < key) {
//		arrangeRight(key - result, a, s, temp - 1);
//	}
//
//}
//int main() {
//	int m;
//	cin >> m;
//	arrangeRight(m, a, 0,9);
//	for (int i = 0; i < 10; i++) {
//		cout << a[i] << " ";
//	}
//}
