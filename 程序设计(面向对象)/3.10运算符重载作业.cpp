//4.1完成复习

//////#include <iostream>
//////#include <string>
//////#include <cstring>
//////using namespace std;
//////class MyString {
//////	char * p;
//////public:
//////	MyString(const char * s) {
//////		if (s) {
//////			p = new char[strlen(s) + 1];
//////			strcpy(p, s);
//////		}
//////		else
//////			p = NULL;
//////
//////	}
//////	~MyString() { if (p) delete[] p; }
//////	// 在此处补充你的代码
//////	MyString & operator =(const MyString&s) {
//////		if (p == s.p) {
//////			return*this;
//////		}
//////		if (p)
//////			delete[]p;
//////		if (s.p) {
//////			p = new char[strlen(s.p) + 1];
//////			strcpy(p, s.p);
//////		}
//////		else
//////			p = NULL;
//////		return *this;
//////	}
//////	MyString & operator = (const char*s) {
//////		if (p)delete[] p;
//////		if (s) {
//////			p = new char[strlen(s) + 1];
//////			strcpy(p, s);
//////		}
//////		else
//////			p = NULL;
//////		return *this;
//////	}
//////	void Copy(const char*s) {
//////		if (p)
//////			delete[]p;
//////		p = new char[strlen(s) + 1];
//////		strcpy(p, s);
//////	}
//////	friend ostream & operator<<(ostream& os, const MyString&c) {
//////		os << c.p; return os;
//////	}
//////	MyString(MyString&s) {
//////		if (s.p) {
//////			p = new char[strlen(s.p) + 1];
//////			strcpy(p, s.p);
//////		}
//////		else
//////			p = NULL;
//////	}
//////};
//////int main()
//////{
//////	char w1[200], w2[100];
//////	while (cin >> w1 >> w2) {
//////		MyString s1(w1), s2 = s1;
//////		MyString s3(NULL);
//////		s3.Copy(w1);
//////		cout << s1 << "," << s2 << "," << s3 << endl;
//////
//////		s2 = w2;
//////		s3 = s2;
//////		s1 = s3;
//////		cout << s1 << "," << s2 << "," << s3 << endl;
//////
//////	}
//////}
////
//////B:好坑啊
////#include <iostream> 
////using namespace std;
////class MyInt
////{
////	int nVal;
////public:
////	MyInt(int n) { nVal = n; }
////	// 在此处补充你的代码
////	MyInt& operator-(int n) {
////		nVal = nVal - n;
////		 return*this;//有连续运算，返回操作数的引用 
////	}
////	operator int() {
////		return nVal;
////	}
////};
////int Inc(int n) {
////	return n + 1;
////}
////int main() {
////	int n;
////	while (cin >> n) {
////		MyInt objInt(n);
////		objInt - 2 - 1 - 3;
////		cout << Inc(objInt);
////		cout << ",";
////		objInt - 2 - 1;
////		cout << Inc(objInt) << endl;
////	}
////	return 0;
////}
////
//////C：point竟然能这样输入输出
////#include <iostream> 
////using namespace std;
////class Point {
////private:
////	int x;
////	int y;
////public:
////	Point() { };
////	// 在此处补充你的代码
////	friend istream&operator>>(istream & is, Point&c) {
////		is >> c.x >> c.y; return is;
////	}
////	friend ostream&operator<<(ostream&os, const Point&c) {
////		os << c.x << "," << c.y;
////		return os;
////	}
////};
////int main()
////{
////	Point p;
////	while (cin >> p) {
////		cout << p << endl;
////	}
////	return 0;
////}
//
//
//
//////D:二维数组
////#include <iostream>
////#include <cstring>
////using namespace std;
////
////class Array2 {
////	// 在此处补充你的代码
////private:
////	int **ptr;
////	int r, c;//不然没办法获得等值工作
////public:
////	Array2(const int row=0, const int col=0) {
////		if (row + col) {
////			r = row; c = col;
////			ptr = new int *[r];//行是指针，可以看作是1*n数组
////			for (int i = 0; i < r; i++) {
////				ptr[i] = new int[c];
////			}//申请二维数组
////		}
////		else {
////			ptr = NULL;
////		}
////	}
////	int&operator()(int i, int j) {//用操作数做左值
////		return ptr[i][j];
////	}
////	int*& operator[](int i) {//因为要返回那一行的指针哇
////		return ptr[i];//??二维数组的固定返回方式？
////	}
////
////	Array2& operator=(const Array2&arra) {
////		r = arra.r;
////		c = arra.c;
////		if (ptr != NULL) {//先清零
////			for (int i = 0; i < r; i++) {
////				delete[]ptr[i];
////			}
////			delete[]ptr;
////		}
////		if (!arra.ptr) { return*this; }
////			ptr = new int*[r];
////			for (int i = 0; i < r; i++) {
////				ptr[i] = new int[c];
////				memcpy(ptr[i], arra.ptr[i], sizeof(int)*c);//先把行复制上
////			}
////			for (int i = 0; i < r; i++) {
////				for (int j = 0; j < c; j++) {
////					ptr[i][j] = arra.ptr[i][j];
////				}
////			}
////			return *this;
////	}
////	~Array2() {
////		if (ptr != NULL) {
////			for (int i = 0; i < r; i++) {
////				delete[]ptr[i];
////			}
////			delete[]ptr;
////		}
////	}
////};
////
////int main() {
////	Array2 a(3, 4);
////	int i, j;
////	for (i = 0; i < 3; ++i)
////		for (j = 0; j < 4; j++)
////			a[i][j] = i * 4 + j;
////	for (i = 0; i < 3; ++i) {
////		for (j = 0; j < 4; j++) {
////			cout << a(i, j) << ",";
////		}
////		cout << endl;
////	}
////	cout << "next" << endl;
////	Array2 b;     b = a;
////	for (i = 0; i < 3; ++i) {
////		for (j = 0; j < 4; j++) {
////			cout << b[i][j] << ",";
////		}
////		cout << endl;
////	}
////	return 0;
////}
//
//
////E:别叫，这个大整数很简化？？qtmd
//#include <iostream> 
//#include <cstring> 
//#include <cstdlib>
//#include <cstdio> 
//using namespace std;
//const int MAX = 110;
//class CHugeInt {
//	// 在此处补充你的代码
//private:
//	char result[210];
//public:
//	void reverse(char*str) {//提前进行数组翻转
//		int len = strlen(str);
//		int s = 0; int end = len - 1;
//		while (s <= end) {
//			swap(str[s], str[end]);
//			s++; end--;
//		}
//	}
//	CHugeInt(int i){
//		memset(result, '\0', sizeof(result));
//		sprintf(result, "%d", i);
//		reverse(result);
//	}
//	CHugeInt(char*str) {
//		memset(result, '\0', sizeof(result));
//		strcpy(result, str);
//		reverse(result);
//	}
//	CHugeInt operator+(int n) {//定义类加整数
//		return *this + CHugeInt(n);
//	}
//
//
//	CHugeInt operator+(const CHugeInt&c) {//定义类间加法
//		CHugeInt tmp(0);//作为最后的输出类
//		int carry = 0;
//		for (int i = 0; i < 210; i++) {
//			char c1 = result[i]; char c2 = c.result[i];
//			if (c1 == 0 && c2 == 0 && carry == 0)break;//即终止符，全终止，即跳出
//			if (c1 == 0)
//				c1 = '0';//如果有人提前终止了，那就当数字0处理
//			if (c2 == 0)
//				c2 = '0';
//			int k = c1 - '0' + c2 - '0' + carry;//关键等式
//			if (k >= 10) {
//				k %= 10;
//				tmp.result[i] = k + '0';//一步步往上进位
//				carry = 1;
//			}
//			else {
//				carry = 0;//无进位
//				tmp.result[i] = k + '0';
//			}
//		}
//		return tmp;
//	}
//	friend CHugeInt operator+(int n,  CHugeInt&c) {//不能加const
//		return c + n;//因为已经定义了整数加一个类，所以外类当然好定义为
//	}
//
//	friend ostream&operator<<(ostream&os, const CHugeInt&c) {//重载输出
//		int len = strlen(c.result);
//		for (int i = len - 1; i >= 0; i--) {
//			cout << c.result[i];
//		}return os;
//	}
//	CHugeInt& operator+=(int n) {//重载+=
//		*this = *this + n;//相当于进行整数和类的加法，创建临时变量（你会发现不同函数之间相互利用
//		return *this;
//	}
//	CHugeInt&operator++() {//重载前置运算符
//		*this = *this + 1; return *this;
//	}
//	CHugeInt operator++(int) {//后置++重载
//		CHugeInt tmp(*this);
//		*this = tmp + 1;
//		return tmp;
//	}
//
//};
//int  main()
//{
//	char s[210];
//	int n;
//
//	while (cin >> s >> n) {
//		//CHugeInt a(s);
//		CHugeInt b(n);
//
//		//cout << a + b << endl;
//		//cout << n + a << endl;
//		//cout << a + n << endl;
//		b += n;
//		cout << ++b << endl;
//		cout << b++ << endl;
//		cout << b << endl;
//	}
//	return 0;
//}
