//////////////////#include <iostream>
//////////////////using namespace std;
//////////////////// 在此处补充你的代码
//template<class T,class T1>
//int sum(T*a, T b, T1*pt) {
//	T sum = pt(*a);
//	for (T*i = a + 1; i < a + b; i++) {
//		sum += pt(*i);
//	}
//	return sum;
//}
//////////////////
//////////////////int sqr(int n) {
//////////////////	return n * n;
//////////////////}
//////////////////int main() {
//////////////////	int t, n, a[0x100];
//////////////////	cin >> t;
//////////////////	for (int c = 0; c < t; ++c) {
//////////////////		cin >> n;
//////////////////		for (int i = 0; i < n; ++i) cin >> a[i];
//////////////////		cout << sum(a, n, sqr) << endl;
//////////////////	}
//////////////////	return 0;
//////////////////}
////////////////#include <iostream>
////////////////#include <string>
////////////////using namespace std;
////////////////// 在此处补充你的代码
//template<class T,int num>
//class A {
//private:
//	T*pr;
//public:
//	A(const T*c) {
//		pr = new T[num];
//		for (int i = 0; i < num; i++) {
//			pr[i] = c[i];
//		}
//	}
//	T operator[](int i) {
//		return pr[i];
//	}
//	T sum() {
//		T sum = *pr;
//		for (T*i = pr + 1; i < pr + num; i++) {
//			sum += *i;
//		}
//		return sum;
//	}
//};
////////////////int main() {
////////////////
////////////////	int t;
////////////////	cin >> t;
////////////////	while (t--) {
////////////////		int b1[10];
////////////////		for (int i = 0; i < 10; ++i)
////////////////
////////////////			cin >> b1[i];
////////////////		A<int, 10> a1 = b1;
////////////////		cout << a1[2] << endl;
////////////////
////////////////
////////////////		double b2[5];
////////////////		for (int i = 0; i < 5; ++i)
////////////////			cin >> b2[i];
////////////////
////////////////		A<double, 5> a2 = b2;
////////////////		cout << a2.sum() << endl;
////////////////
////////////////
////////////////		string b3[4];
////////////////		for (int i = 0; i < 4; ++i)
////////////////			cin >> b3[i];
////////////////
////////////////		A<string, 4> a3 = b3;
////////////////		cout << a3.sum() << endl;
////////////////	}
////////////////	return 0;
////////////////}
//////////////
//////////////#include <iostream>
//////////////using namespace std;
//////////////template <class T>
//////////////class Add {
//////////////public:
//////////////	// 在此处补充你的代码
//	T val;
//	Add(T n) :val(n) {};
//	T operator()(T a,T b) {
//		return a + b - val;
//	}
//////////////};
//////////////
//////////////int main() {
//////////////	double f;
//////////////	int n;
//////////////	while (cin >> f >> n) {
//////////////
//////////////		Add<double> a1(f);
//////////////		Add<int> a2(n);
//////////////		double x, y;
//////////////		int p, q;
//////////////		cin >> x >> y >> p >> q;
//////////////		cout << a1(x, y) << endl;
//////////////		cout << a2(p, q) << endl;
//////////////	}
//////////////	return 0;
//////////////}
////////////#include<iostream>
////////////using namespace std;
////////////template<class T>
//// 在此处补充你的代码
//void f(T*a, int len) {
//	int  s = 0; int end = len - 1;
//	T tmp;
//	while (s <= end) {
//		tmp = a[s]; a[s] = a[end];
//		a[end] = tmp;
//		s++; end--;
//	}
//}
////////////int main()
////////////{
////////////	int a[5] = { 10, 21, 34, 4, 50 };
////////////	double d[6] = { 4.1, 11.1, 10.1, 9.1, 8.1, 7.1 };
////////////	f(a, 5);
////////////	f(d, 6);
////////////	for (int i = 0; i < 5; i++)
////////////	{
////////////		cout << a[i] << " ";
////////////	}
////////////	cout << endl;
////////////	for (int j = 0; j < 6; j++)
////////////	{
////////////		cout << d[j] << " ";
////////////	}
////////////	cout << endl;
////////////	return 0;
////////////}
//////////#include <cstdio>
//////////#include <iostream>
//////////#include <string>
//////////#include <cstring>
//////////using namespace std;
//////////// 在此处补充你的代码
//template<class T,int num>
//class A {
//private:
//	T*pr;
//public:
//	A(const T*c) {
//		pr = new T[num];
//		for (int i = 0; i < num; i++) {
//			pr[i] = c[i];
//		}
//	}
//	T operator[](int i) {
//		return pr[i];
//	}
//	~A() {
//		delete[]pr;
//	}
//	template<class T1>
//	T1 sum(int a, int b, T1 (*func)(T x)){//这个括号加的就很灵性
//		T1 s = func(pr[a]);
//		for (int i = a + 1; i <= b; i++) {
//			s += func(pr[i]);
//		}
//		return s;
//	}
//
//};
////////////learn it !保证传入的为函数指针
//////////
//////////string int2string(int x) { return to_string(x); }
//////////int int2squareint(int x) { return x * x; }
//////////
//////////int string2int(string str) {
//////////	int res = 0;
//////////	for (string::iterator iter = str.begin(); iter != str.end(); ++iter)
//////////		res += *iter;
//////////	return res;
//////////}
//////////string string2longerstring(string str) { return str + str; }
//////////
//////////int main() {
//////////
//////////	int t;
//////////	cin >> t;
//////////	while (t--) {
//////////		int b1[10];
//////////		for (int i = 0; i < 10; ++i)
//////////
//////////			cin >> b1[i];
//////////		A<int, 10> a1 = b1;
//////////		cout << a1.sum(2, 6, int2squareint) << endl;
//////////		cout << a1.sum(2, 6, int2string) << endl;
//////////
//////////		string b2[4];
//////////		for (int i = 0; i < 4; ++i)
//////////			cin >> b2[i];
//////////
//////////		A<string, 4> a2 = b2;
//////////		cout << a2.sum(0, 3, string2int) << endl;
//////////		cout << a2.sum(0, 3, string2longerstring) << endl;
//////////	}
//////////	return 0;
//////////}
////////
////////#include <iostream>
////////#include <string>
////////using namespace std;
////////template <class T>
////////class container {
////////	// 在此处补充你的代码
//private :
//	T in;
//public:
//	container(const T&c) {
//		in = c;
//	}
//	friend ostream&operator<<(ostream&os,const container<T>&c) {
//		os << c.in; return os;
//	}
//	container<T>&  operator+(const T&c) {
//		in = in + c;//这是正常同类型的加
//		return*this;
//	}
//	container<T>  operator+(const container<T> &b) {
//		container<T> tmp ( in + b.in+b.in);
//		return tmp;
//	}
//
////////};
////////int main() {
////////	int n, m;
////////	cin >> n >> m;
////////	string s1, s2;
////////	cin >> s1 >> s2;
////////	container <int> a = n;
////////	container <int> b = m;
////////	cout << a + b << endl;
////////	cout << a + m << endl;
////////	container <string> sa = string(s1);
////////	container <string> sb = string(s2);
////////	cout << sa + sb << endl;
////////	cout << sa + s2 << endl;
////////}
//////
//////#include <iostream>
//////#include <cstring> 
//////#include <vector>
//////#include <cstdio> 
//////using namespace std;
//////// 在此处补充你的代码
//template<class T>
//class CMyClass {
//private:
//	int size;
//	T*pr;
//public:
//	CMyClass(T*input, int n) {
//		size = n;
//		pr = new T[size];
//		for (int i = 0; i < n; i++) {
//			pr[i] = input[i];
//		}
//	}
//	T operator[](int i) {
//		return pr[i];
//	}
//};
//////int  a[40];
//////int main(int argc, char** argv) {
//////	int t;
//////	scanf_s("%d", &t);
//////	while (t--) {
//////		int m;
//////		scanf_s("%d", &m);
//////		for (int i = 0; i < m; ++i)
//////			scanf_s("%d", a + i);
//////		char s[100];
//////		scanf_s("%s", s);
//////		CMyClass<int> b(a, m);
//////		CMyClass<char> c(s, strlen(s));
//////		printf("%d %c\n", b[5], c[7]);
//////	}
//////	return 0;
//////}
////
//////整理这道题！！
////#include <iostream>
////#include <iomanip> 
////#include <cstring>
////using namespace std;
////template <class T>
////class CArray3D
////{
//	// 在此处补充你的代码
//	//还不能用三重指针哇
//private:
//	T*p;
//	int f; int r; int c;
//public:
//	CArray3D(int f_, int r_, int c_) :f(f_), r(r_), c(c_) {
//		p = new T[f*c*r];//f层r行c列
//	}
//	class CArray2D {
//	public:
//		T*fp;//一层元素的起始位置
//		int c;
//		CArray2D(T*p_, int c_) :fp(p_), c(c_) {}
//		T*operator[](int r) {
//			return fp + r * c;//返回本层第r行起始位置
//		}
//		operator T*() {//重载T*类型转换符号
//			return fp;//a[1]是一个对象，不能直接初始化，所以类型构造返回本层地址
//		}
//	};
//	CArray2D operator[](int layer) {
//		return CArray2D(p + layer * r*c, c);//获得第layer层的起始地址
//	}
//	~CArray3D() {
//		delete[]p;
//	}
////};
////
////CArray3D<int> a(3, 4, 5);
////CArray3D<double> b(3, 2, 2);
////void PrintA()
////{
////	for (int i = 0; i < 3; ++i) {
////		cout << "layer " << i << ":" << endl;
////		for (int j = 0; j < 4; ++j) {
////			for (int k = 0; k < 5; ++k)
////				cout << a[i][j][k] << ",";
////			cout << endl;
////		}
////	}
////}
////void PrintB()
////{
////	for (int i = 0; i < 3; ++i) {
////		cout << "layer " << i << ":" << endl;
////		for (int j = 0; j < 2; ++j) {
////			for (int k = 0; k < 2; ++k)
////				cout << b[i][j][k] << ",";
////			cout << endl;
////		}
////	}
////}
////
////int main()
////{
////
////	int No = 0;
////	for (int i = 0; i < 3; ++i) {
////		a[i];
////		for (int j = 0; j < 4; ++j) {
////			a[j][i];
////			for (int k = 0; k < 5; ++k)
////				a[i][j][k] = No++;
////			a[j][i][i];
////		}
////	}
////	PrintA();
////	memset(a[1], -1, 20 * sizeof(int));
////	memset(a[1], -1, 20 * sizeof(int));
////	PrintA();
////	memset(a[1][1], 0, 5 * sizeof(int));
////	PrintA();
////
////	for (int i = 0; i < 3; ++i)
////		for (int j = 0; j < 2; ++j)
////			for (int k = 0; k < 2; ++k)
////				b[i][j][k] = 10.0 / (i + j + k + 1);
////	PrintB();
////	int n = a[0][1][2];
////	double f = b[0][1][1];
////	cout << "****" << endl;
////	cout << n << "," << f << endl;
////
////	return 0;
////}