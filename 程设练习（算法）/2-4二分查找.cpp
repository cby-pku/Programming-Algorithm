//////int BinarySearch(int a[], int size, int p) {
//////	int L = 0;
//////	int R = size - 1;
//////	while (L <= R) {//����ұ�
//////		int mid = L + (R - L) / 2;
//////		if (p == a[mid]) {
//////			return mid;
//////		}
//////		else if (p > a[mid]) {
//////			L = mid + 1;
//////		}
//////		else {
//////			R = mid - 1;
//////		}
//////	}
//////	return -1;
//////}//���Ӷ�o(log(n))
//////
//////int LowerBound(int a[], int size, int p) {
//////	int L = 0;
//////	int R = size - 1;
//////	int lastpos = -1;
//////	while (L <= R) {
//////		int mid = L + (R - L) / 2;
//////		if (a[mid] >= p) {
//////			R = mid - 1;
//////		}
//////		else {
//////			lastpos = mid;//����һ����¼�±꣬���ϸ��¾��ܵõ���
//////			L = mid + 1;
//////		}
//////	}
//////}
//////
////////���ַ����
////#include<iostream>
////#include<stdio.h>
////#include<cmath>
////#include<algorithm>
////using namespace std;
////double EPS = 1e-6;
////double f(double x) {
////	return x * x*x - 5 * x*x + 10 * x - 80;
////}
////int main() {
////	double root, x1 = 0, x2 = 100, y;
////	root = x1 + (x2 - x1) / 2;
////	int triedTimes = 1;
////	y = f(root);
////	while (fabs(y) > EPS) {
////		if (y > 0)x2 = root;
////		else x1 = root;
////		root = x1 + (x2 - x1) / 2;
////		y = f(root);
////		triedTimes++;
////	}
////	printf("%.8f\n", root);
////	printf("%d", triedTimes);
//////	return 0;
//////}
//
////��������֮��
////#include<iostream>
////#include<algorithm>
////#include<cmath>
////const int N = 101000;
////using namespace std;
////int a[N];
////int main() {
////	int b; int num = 0;
////	while (cin >> b) {
////		a[num++] = b;//num��¼������Ŀ
////	}
////	int m;
////	cin >> m;
////	sort(a, a + num);
////	int i, j;
////	for ( i = 0, j = num - 1; a[i] + a[j] != m&&i<j;) {
////		if (a[i] + a[j] > m) { j--; }
////		else {
////			i++;
////		}
////	}
////	//��ֹʱ i��jӦ���ܵõ�
////	if (i >= j)cout << "-1";
////	else {
////		cout << a[i] << a[j] << endl;
////	}
////}
//
////2456��aggressive cows
//#include<iostream>
//#include<algorithm>
//#include<cmath>
//const int N = 101100;
//using namespace std;
//int a[N];
//int n; int c;
//int isok(int D, int a[]) {
//	int start = a[0];
//	int num = 1; int flag = 1;
//	while (flag < n || num < c) {
//		for (; a[flag] - start <= D; flag++); //�ҵ��������Сflag�±�
//		start = a[flag - 1];//����Ϊ�µ�start
//		num++;//Ϊһͷţ�ҵ���λ�ã���c��
//	}
//	//����ʱ���num�Ƿ���ڵ���c
//	if (num >= c)return 1;
//	return 0;
//}
//int main() {
//
//	cin >> n>>c;
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a, a + n);
//	int L = 0; int R = (a[n - 1] - a[0]) / (c - 1);
//	int ans = 0;
//	while (L <= R) {
//		int mid = L + (R - L) / 2;
//		if (isok(mid,a)) {
//			ans = mid;
//			L = mid + 1;
//		}
//		else if (!isok(mid, a)) {
//			R = mid - 1;
//		}
//	}
//	cout << ans << endl; return 0;
//
//}
