////////归并排序
//////#include<iostream>
//////#include<algorithm>
//////#include<stdio.h>
//////int a[10] = { 13,17,15,12,18,19,21,35,4,5 };
//////int b[10];
//////void Merge(int a[], int s, int mid, int e, int tmp[]) {
//////	//采用双指针法合并
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
//////		//tmp是已经排好序的了，接下来就是把它复制回a
//////		for (int i = 0; i < e - s + 1; ++i) {//e-s+1个数
//////			a[s + i] = tmp[i];//左闭右闭区间
//////		}
//////}
//////void MergeSort(int a[], int s, int e, int tmp[]) {
//////	if (s < e) {
//////		int m = s + (e - s) / 2;
//////		MergeSort(a, s, m, tmp);
//////		MergeSort(a, m + 1, e, tmp);
//////		//其实关键的操作步骤在最后一步
//////		Merge(a, s, m, e, tmp);//实现了对单元的合并
//////	}
//////}
//////using namespace std;
//////int main() {
//////	int size = sizeof(a) / sizeof(int);
//////	MergeSort(a, 0, size - 1, b);//左闭右闭区间
//////	for (int i = 0; i < size; i++) {
//////		cout << a[i] << " ";
//////	}
//////	cout << endl; return 0;
//////}
//////
////////2：快速排序
////#include<iostream>
////#include<stdio.h>
////#include<algorithm>
////using namespace std;
////void swap(int &a, int &b) {
////	int temp = a;
////	a = b;
////	b = temp;//调用地址,参数是引用
////}
////void QuickSort(int a[], int s, int e) {//调用数组可以直接更改
////	if (s >= e)return;
////	int k = a[s];
////	int i = s, j = e;
////	while (i != j) {
////		while (j > i&&a[j] >= k) {
////			j--;
////		}
////		swap(a[i], a[j]);
////		while (i < j&&a[i] <= k) {//因为可能经过上面的过程i已经等于j了
////			i++;
////		}
////		swap(a[i], a[j]);
////	}//处理完后a[i]=k;
////	QuickSort(a, s, i - 1);
////	QuickSort(a, i + 1, e);
////}
////int a[10] = { 13,17,15,12,18,19,21,35,4,5 };
////int main() {
////	int size = sizeof(a) / sizeof(int);
////	QuickSort(a, 0, size - 1);//左闭右闭区间
////	for (int i = 0; i < size; i++) {
////		cout << a[i] << " ";
////	}
////	cout << endl; return 0;
////}
//
////3:输出前m大的数√
////key和k不要弄混
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
//	return i;//返回索引值
//}
//void arrangeRight(int key,int a[],int s,int e) {
//	if (s >= e)return;//必须设置终止条件
//	int k = a[s];
//	int i = s, j = e;
//	while (i != j) {
//			while (j > i&&a[j] >= k) {
//				j--;
//			}
//			swap(a[i], a[j]);
//			while (i < j&&a[i] <= k) {//因为可能经过上面的过程i已经等于j了
//				i++;
//			}
//			swap(a[i], a[j]);
//	}//处理完后a[i]=k;
//	//计数
//	int temp = num(a, k);//返回坐标
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
