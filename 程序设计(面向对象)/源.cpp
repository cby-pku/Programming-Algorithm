//////#include<iostream>
//////#include<stdio.h>
//////#include<cstring>
//////#include<string>
//////using namespace std;
//////
//////class MyString {
//////private:
//////	char *p;
//////public:
//////	MyString(const char*s) {
//////		if (s) {
//////			p = new char[strlen(s) + 1];
//////			strcpy(p, s);
//////		}
//////		else {
//////			p = NULL;
//////		}
//////	}
//////	MyString&operator=(const MyString&s) {//������
//////		if (p == s.p)return;//ע��Ҳ�������е�ʱ��Ŵ�
//////		if (p)delete[]p;
//////		if (s.p) {
//////			p = new char[strlen(s.p) + 1];
//////			strcpy(p, s.p);
//////		}
//////		return*this;
//////	}
//////
//////};
//////int main() {
//////
//////}
////
//////�������������Ԫ
////friend ostream&operator<<(ostream&os, Myint&c) {
////	os << c.val; return os;
////}
//
////շת���
//int gcd(int x, int y) {
//	return x % y == 0 ? y : gcd(y, x%y);
////}
//#include<iostream>
//#include<stdio.h>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//bool Judge(int x) {//�ж��Ƿ�Ϊ�����������3��ʼ��2������
//	//�������Ƶ��ж�x����ʵֻҪ��֤��sqrt(x)�Ϳ�����
//	for (int i = 2; i <(x); i++) {
//		if (x%i == 0)return 0;
//	}
//	return 1;
//}
//int main() {
//	int m, n;
//	cin >> m >> n;
//	int flag = 1;
//	int print = 0;
//	if (m == 1) {
//		cout << 2 << " ";
//		m++;//����λ��2�ĵ����ж�
//	}
//	for (int i = 3;; i++) {//ѭ������
//		if (Judge(i)) {
//			flag++;
//			if (flag >= m && flag < n) {
//				print++;//�����ж��Ƿ���ĩ�����
//				if (print % 10) {
//					cout << i << ' ';
//				}
//				else if (print % 10==0) {//���õ���ʮ������ʼ����
//					cout << i << endl;
//				}
//			}
//			if (flag == n) {
//				cout << i << endl;//���һ�������Ҳ��������ո�
//			}
//			if (flag > n) { break; }
//		}
//	}
//	return 0;
//}