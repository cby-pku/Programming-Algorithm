////goodcopy
////////////#include <iostream>
////////////#include<string>
////////////using namespace std;
////////////
////////////
////////////template <class T>
////////////struct GoodCopy {
////////////	// �ڴ˴�������Ĵ���
////////////	void operator()( T*start,  T*end,  T*t) {
////////////		if (t > end) {//�ڴ�û���໥Ӱ��
////////////			for (T*i = start; i != end; i++) {
////////////				*t = *i;
////////////				t++;
////////////			}
////////////		}
////////////		else {
////////////			T*t1= end;
////////////			t = t + (end - start);//ָ�����Ƶ�����ȥ��ͬʱ�Ӻ��濪ʼ��ֵ����ֹ����
////////////			for (; t1 >= start; t1--, t--) {
////////////				*t = *t1;
////////////			}
////////////		}
////////////	}
////////////};
////////////
////////////int a[200];
////////////int b[200];
////////////string c[200];
////////////string d[200];
////////////
////////////template <class T>
////////////void Print(T s, T e) {
////////////	for (; s != e; ++s)
////////////		cout << *s << ",";
////////////	cout << endl;
////////////}
////////////
////////////int main()
////////////{
////////////	int t;
////////////	cin >> t;
////////////	while (t--) {
////////////		int m;
////////////		cin >> m;
////////////		for (int i = 0; i < m; ++i)
////////////			cin >> a[i];
////////////		GoodCopy<int>()(a, a + m, b);
////////////		Print(b, b + m);
////////////		GoodCopy<int>()(a, a + m, a + m / 2);
////////////		Print(a + m / 2, a + m / 2 + m);
////////////
////////////		for (int i = 0; i < m; ++i)
////////////			cin >> c[i];
////////////		GoodCopy<string>()(c, c + m, d);
////////////		Print(c, c + m);
////////////		GoodCopy<string>()(c, c + m, c + m / 2);
////////////		Print(c + m / 2, c + m / 2 + m);
////////////	}
////////////	return 0;
////////////}
////����������
//////////#include <iostream>
//////////#include <cmath>
//////////#include <algorithm>
//////////#include <string>
//////////using namespace std;
//////////template <class T1, class T2>
//////////struct Closer {
//////////	// �ڴ˴�������Ĵ���
//////////private:
//////////	T1 input;
//////////	T2 op;
//////////public:
//////////	Closer(T1 in, T2 opt) :input(in), op(opt) {};//�������ıȽϱ������Ǿ��ڽṹ���ڶ���˽�б���
//////////	bool operator()(const T1&x1, const T1&x2) {//�����бȽϣ��ͱ��뷵��boolֵ
//////////		int d1 = op(x1, input);
//////////		int d2 = op(x2, input);
//////////		if (d1 < d2)return true;
//////////		else if (d1 > d2)return false;
//////////		else {
//////////			if (x1 < x2)return true;
//////////			return false;
//////////		}
//////////	}
//////////};
//////////
//////////int Distance1(int n1, int n2) {
//////////	return abs(n1 - n2);
//////////}
//////////int Distance2(const string & s1, const string & s2)
//////////{
//////////	return abs((int)s1.length() - (int)s2.length());
//////////}
//////////int a[10] = { 0,3,1,4,7,9,20,8,10,15 };
//////////string b[6] = { "American","Jack","To","Peking","abcdefghijklmnop","123456789" };
//////////int main()
//////////{
//////////	int n; string s;
//////////	while (cin >> n >> s) {
//////////		sort(a, a + 10, Closer<int, int(*)(int, int)>(n, Distance1));
//////////		for (int i = 0; i < 10; ++i)
//////////			cout << a[i] << ",";
//////////		cout << endl;
//////////		sort(b, b + 6, Closer<string, int(*)(const string &, const string &)>(s, Distance2));
//////////		for (int i = 0; i < 6; ++i)
//////////			cout << b[i] << ",";
//////////		cout << endl;
//////////	}
//////////	return 0;
//////////}
////////
//////3D������
////////#include <iostream>
////////#include <iomanip> 
////////#include <cstring>
////////using namespace std;
////////template <class T>
////////class CArray3D
////////{
////////	// �ڴ˴�������Ĵ���
////////public:
////////	T*p;
////////	int f, r, c;
////////	CArray3D(int f_, int r_, int c_) :f(f_), r(r_), c(c_) {
////////		p = new T[r*f*c];
////////	};
////////	~CArray3D() {
////////		delete[]p;
////////	}
////////	class CArray2D {
////////	public:
////////		T*fp; int c;
////////		CArray2D(T*p_, int c_) :fp(p_), c(c_) {};
////////		T* operator[](int r) {
////////			return fp + r * c;
////////		}
////////		operator T*() {
////////			return fp;//���ر�����ʼ��ַ������memset��ֵ
////////		}
////////	};
////////	CArray2D operator[](int layer) {
////////		return CArray2D(p + layer * r*c, c);
////////	}
////////
////////
////////};
////////
////////CArray3D<int> a(3, 4, 5);
////////CArray3D<double> b(3, 2, 2);
////////void PrintA()
////////{
////////	for (int i = 0; i < 3; ++i) {
////////		cout << "layer " << i << ":" << endl;
////////		for (int j = 0; j < 4; ++j) {
////////			for (int k = 0; k < 5; ++k)
////////				cout << a[i][j][k] << ",";
////////			cout << endl;
////////		}
////////	}
////////}
////////void PrintB()
////////{
////////	for (int i = 0; i < 3; ++i) {
////////		cout << "layer " << i << ":" << endl;
////////		for (int j = 0; j < 2; ++j) {
////////			for (int k = 0; k < 2; ++k)
////////				cout << b[i][j][k] << ",";
////////			cout << endl;
////////		}
////////	}
////////}
////////
////////int main()
////////{
////////
////////	int No = 0;
////////	for (int i = 0; i < 3; ++i) {
////////		a[i];
////////		for (int j = 0; j < 4; ++j) {
////////			a[j][i];
////////			for (int k = 0; k < 5; ++k)
////////				a[i][j][k] = No++;
////////			a[j][i][i];
////////		}
////////	}
////////	PrintA();
////////	memset(a[1], -1, 20 * sizeof(int));
////////	memset(a[1], -1, 20 * sizeof(int));
////////	PrintA();
////////	memset(a[1][1], 0, 5 * sizeof(int));
////////	PrintA();
////////
////////	for (int i = 0; i < 3; ++i)
////////		for (int j = 0; j < 2; ++j)
////////			for (int k = 0; k < 2; ++k)
////////				b[i][j][k] = 10.0 / (i + j + k + 1);
////////	PrintB();
////////	int n = a[0][1][2];
////////	double f = b[0][1][1];
////////	cout << "****" << endl;
////////	cout << n << "," << f << endl;
////////
////////	return 0;
////////}
////////��������Ĺ�����
//////#include <iostream>
//////#include <vector>
//////#include<algorithm>
//////using namespace std;
//////
//////
//////struct A {
//////	int v;
//////	A() { }
//////	A(int n) :v(n) { };
//////	bool operator<(const A & a) const {
//////		return v < a.v;
//////	}
//////};
//////// �ڴ˴�������Ĵ���
//////template<class T>
//////class FilterClass {
//////private:
//////	T start; T end;
//////public:
//////	FilterClass(const T&m, const T&n) :start(m), end(n) {};//�ǵò��ڲ������ͣ�����ȽϵĻ����϶���Ҫ���ͬһ���ͣ�����Ĺ��캯��Ӧ������ʱ����ת����һ��
//////	bool operator()(const T& a) {
//////		if ( start< a && a < end)
//////			return 1;
//////		return 0;
//////	}
//////};
//////template <class T>
//////void Print(T s, T e)
//////{
//////	for (; s != e; ++s)
//////		cout << *s << ",";
//////	cout << endl;
//////}
//////template <class T1, class T2, class T3>
//////T2 Filter(T1 s, T1 e, T2 s2, T3 op)
//////{
//////	for (; s != e; ++s) {
//////		if (op(*s)) {
//////			*s2 = *s;
//////			++s2;
//////		}
//////	}
//////	return s2;
//////}
//////
//////ostream & operator <<(ostream & o, A & a)
//////{
//////	o << a.v;
//////	return o;
//////}
//////vector<int> ia;
//////vector<A> aa;
//////int main()
//////{
//////	int m, n;
//////	while (cin >> m >> n) {
//////		ia.clear();
//////		aa.clear();
//////		int k, tmp;
//////		cin >> k;
//////		for (int i = 0; i < k; ++i) {
//////			cin >> tmp;
//////			ia.push_back(tmp);
//////			aa.push_back(tmp);
//////		}
//////		vector<int> ib(k);
//////		vector<A> ab(k);
//////		vector<int>::iterator p = Filter(ia.begin(), ia.end(), ib.begin(), FilterClass<int>(m, n));
//////		Print(ib.begin(), p);
//////		vector<A>::iterator pp = Filter(aa.begin(), aa.end(), ab.begin(), FilterClass<A>(m, n));
//////		Print(ab.begin(), pp);
//////
//////	}
//////	return 0;
//////}
//////
////
//////E���׸���list����
////#include <cstdio>
////#include <iostream>
////#include <algorithm>
////#include <list>
////using namespace std;
////int main()
////{
////	double a[] = { 1.2,3.4,9.8,7.3,2.6 };
////	list<double> lst(a, a + 5);
////	lst.sort(greater<double>()//�������greater��֮ǰҪ��֤�����ع����ںţ�����������ģ��
////		// �ڴ˴�������Ĵ���
////	);
////
////	for (list<double>::iterator i = lst.begin(); i != lst.end(); ++i)
////		cout << *i << ",";
////	return 0;
////}
//
//#include <iostream>
//#include <list>
//#include <string>
//using namespace std;
//
//template <class T1, class T2>
//void Copy(T1 s, T1 e, T2 x)
//{
//	for (; s != e; ++s, ++x)
//		*x = *s;
//}
//
//
//template<class T>
//class myostream_iteraotr
//{
//	// �ڴ˴�������Ĵ���
//public:
//	ostream &os;
//	string s;//��Ҫ����++x
//	//T��ʲô�ã��������������cout��ô����:��ostream
//	myostream_iteraotr( ostream&out, const string&c) :os(out), s(c) {};
//	void operator =(const T&t) { os << t << s; }//�����ڲ����ڵ�ʵ��
//	myostream_iteraotr& operator++() { return *this; };
//	myostream_iteraotr& operator*() {
//		return*this;//ָ��ֱ�ӷ��ص���ָ�룬���ǽ�����
//	}
//
//
//};
//
//
//int main()
//{
//	const int SIZE = 5;
//	int a[SIZE] = { 5,21,14,2,3 };
//	double b[SIZE] = { 1.4, 5.56,3.2,98.3,3.3 };
//	list<int> lst(a, a + SIZE);
//	myostream_iteraotr<int> output(cout, ",");
//	Copy(lst.begin(), lst.end(), output);
//	cout << endl;
//	myostream_iteraotr<double> output2(cout, "--");
//	Copy(b, b + SIZE, output2);
//	return 0;
//}
