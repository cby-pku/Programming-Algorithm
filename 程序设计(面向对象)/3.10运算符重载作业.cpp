//4.1��ɸ�ϰ

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
//////	// �ڴ˴�������Ĵ���
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
//////B:�ÿӰ�
////#include <iostream> 
////using namespace std;
////class MyInt
////{
////	int nVal;
////public:
////	MyInt(int n) { nVal = n; }
////	// �ڴ˴�������Ĵ���
////	MyInt& operator-(int n) {
////		nVal = nVal - n;
////		 return*this;//���������㣬���ز����������� 
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
//////C��point��Ȼ�������������
////#include <iostream> 
////using namespace std;
////class Point {
////private:
////	int x;
////	int y;
////public:
////	Point() { };
////	// �ڴ˴�������Ĵ���
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
//////D:��ά����
////#include <iostream>
////#include <cstring>
////using namespace std;
////
////class Array2 {
////	// �ڴ˴�������Ĵ���
////private:
////	int **ptr;
////	int r, c;//��Ȼû�취��õ�ֵ����
////public:
////	Array2(const int row=0, const int col=0) {
////		if (row + col) {
////			r = row; c = col;
////			ptr = new int *[r];//����ָ�룬���Կ�����1*n����
////			for (int i = 0; i < r; i++) {
////				ptr[i] = new int[c];
////			}//�����ά����
////		}
////		else {
////			ptr = NULL;
////		}
////	}
////	int&operator()(int i, int j) {//�ò���������ֵ
////		return ptr[i][j];
////	}
////	int*& operator[](int i) {//��ΪҪ������һ�е�ָ����
////		return ptr[i];//??��ά����Ĺ̶����ط�ʽ��
////	}
////
////	Array2& operator=(const Array2&arra) {
////		r = arra.r;
////		c = arra.c;
////		if (ptr != NULL) {//������
////			for (int i = 0; i < r; i++) {
////				delete[]ptr[i];
////			}
////			delete[]ptr;
////		}
////		if (!arra.ptr) { return*this; }
////			ptr = new int*[r];
////			for (int i = 0; i < r; i++) {
////				ptr[i] = new int[c];
////				memcpy(ptr[i], arra.ptr[i], sizeof(int)*c);//�Ȱ��и�����
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
////E:��У�����������ܼ򻯣���qtmd
//#include <iostream> 
//#include <cstring> 
//#include <cstdlib>
//#include <cstdio> 
//using namespace std;
//const int MAX = 110;
//class CHugeInt {
//	// �ڴ˴�������Ĵ���
//private:
//	char result[210];
//public:
//	void reverse(char*str) {//��ǰ�������鷭ת
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
//	CHugeInt operator+(int n) {//�����������
//		return *this + CHugeInt(n);
//	}
//
//
//	CHugeInt operator+(const CHugeInt&c) {//�������ӷ�
//		CHugeInt tmp(0);//��Ϊ���������
//		int carry = 0;
//		for (int i = 0; i < 210; i++) {
//			char c1 = result[i]; char c2 = c.result[i];
//			if (c1 == 0 && c2 == 0 && carry == 0)break;//����ֹ����ȫ��ֹ��������
//			if (c1 == 0)
//				c1 = '0';//���������ǰ��ֹ�ˣ��Ǿ͵�����0����
//			if (c2 == 0)
//				c2 = '0';
//			int k = c1 - '0' + c2 - '0' + carry;//�ؼ���ʽ
//			if (k >= 10) {
//				k %= 10;
//				tmp.result[i] = k + '0';//һ�������Ͻ�λ
//				carry = 1;
//			}
//			else {
//				carry = 0;//�޽�λ
//				tmp.result[i] = k + '0';
//			}
//		}
//		return tmp;
//	}
//	friend CHugeInt operator+(int n,  CHugeInt&c) {//���ܼ�const
//		return c + n;//��Ϊ�Ѿ�������������һ���࣬�������൱Ȼ�ö���Ϊ
//	}
//
//	friend ostream&operator<<(ostream&os, const CHugeInt&c) {//�������
//		int len = strlen(c.result);
//		for (int i = len - 1; i >= 0; i--) {
//			cout << c.result[i];
//		}return os;
//	}
//	CHugeInt& operator+=(int n) {//����+=
//		*this = *this + n;//�൱�ڽ�����������ļӷ���������ʱ��������ᷢ�ֲ�ͬ����֮���໥����
//		return *this;
//	}
//	CHugeInt&operator++() {//����ǰ�������
//		*this = *this + 1; return *this;
//	}
//	CHugeInt operator++(int) {//����++����
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
