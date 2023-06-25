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
//////	MyString&operator=(const MyString&s) {//传引用
//////		if (p == s.p)return;//注意也必须是有的时候才传
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
//////输入输出声明友元
////friend ostream&operator<<(ostream&os, Myint&c) {
////	os << c.val; return os;
////}
//
////辗转相除
//int gcd(int x, int y) {
//	return x % y == 0 ? y : gcd(y, x%y);
////}
//#include<iostream>
//#include<stdio.h>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//bool Judge(int x) {//判断是否为素数，必须从3开始，2会误算
//	//这里限制到判断x，其实只要验证到sqrt(x)就可以了
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
//		m++;//对首位是2的单独判断
//	}
//	for (int i = 3;; i++) {//循环整数
//		if (Judge(i)) {
//			flag++;
//			if (flag >= m && flag < n) {
//				print++;//用于判断是否到行末该输出
//				if (print % 10) {
//					cout << i << ' ';
//				}
//				else if (print % 10==0) {//正好到第十个，开始换行
//					cout << i << endl;
//				}
//			}
//			if (flag == n) {
//				cout << i << endl;//最后一个输出，也不能输出空格
//			}
//			if (flag > n) { break; }
//		}
//	}
//	return 0;
//}