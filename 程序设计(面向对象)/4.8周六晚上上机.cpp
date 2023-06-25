//////////////////////////字符串排序
////////////////////////#include <iostream>
////////////////////////#include <string>
////////////////////////#include <list>
////////////////////////using namespace std;
////////////////////////
////////////////////////class A {
////////////////////////private:
////////////////////////	string name;
////////////////////////public:
////////////////////////	A(string n) :name(n) {}
////////////////////////	friend bool operator < (const class A& a1, const class A &a2);
////////////////////////	friend bool operator == (const class A &a1, const class A &a2) {
////////////////////////		if (a1.name.size() == a2.name.size())
////////////////////////			return true;
////////////////////////		else
////////////////////////			return false;
////////////////////////	}
////////////////////////	friend ostream & operator << (ostream &o, const A &a) {
////////////////////////		o << a.name;
////////////////////////		return o;
////////////////////////	}
////////////////////////	string get_name() const {
////////////////////////		return name;
////////////////////////	}
////////////////////////	int get_size() const {
////////////////////////		return name.size();
////////////////////////	}
////////////////////////};
////////////////// 在此处补充你的代码
////////////////bool operator < (const A&a1, const A&a2) {
////////////////	return a1.get_size() < a2.get_size();
////////////////}
////////////////
////////////////struct Print {
////////////////	void operator()(const A&a) {//有些传不了模板，那就直接打印，不跟他废话
////////////////		cout << a.get_name() << " ";
////////////////	}
////////////////};
////////////////template<class T,class T1>
////////////////void Show(T first, T last, T1 op) {
////////////////	for (; first != last; ++first) {
////////////////		op(*first);
////////////////	}
////////////////}
////////////////template<class A>
////////////////struct MyLarge
////////////////{
////////////////	bool operator()(const A&x1, const A&x2) {
////////////////		if (x1.get_name() < x2.get_name())return true;
////////////////		return false;
////////////////	}
////////////////};
////////////////////////
////////////////////////int main(int argc, char* argv[])
////////////////////////{
////////////////////////	list<A> lst;
////////////////////////	int ncase, n, i = 1;
////////////////////////	string s;
////////////////////////	cin >> ncase;
////////////////////////	while (ncase--) {
////////////////////////		cout << "Case: " << i++ << endl;
////////////////////////		cin >> n;
////////////////////////		for (int i = 0; i < n; i++) {
////////////////////////			cin >> s;
////////////////////////			lst.push_back(A(s));
////////////////////////		}
////////////////////////		lst.sort();
////////////////////////		Show(lst.begin(), lst.end(), Print());
////////////////////////
////////////////////////		cout << endl;
////////////////////////		lst.sort(MyLarge<A>());
////////////////////////		Show(lst.begin(), lst.end(), Print());
////////////////////////		cout << endl;
////////////////////////		lst.clear();
////////////////////////
////////////////////////	}
////////////////////////	return 0;
////////////////////////}
//////////////////////
////////////////////////按距离排序
//////////////////////#include <iostream>
//////////////////////#include <cmath>
//////////////////////#include <algorithm>
//////////////////////#include <string>
//////////////////////using namespace std;
//////////////////////template <class T1, class T2>
//////////////////////struct Closer {
////////////////	// 在此处补充你的代码
////////////////private:
////////////////	T1 input;
////////////////	T2 dis;
////////////////public:
////////////////	Closer(T1 a, T2 b) :input(a), dis(b) {};
////////////////	bool operator()(const T1&a1,const T1&a2) {
////////////////		int dis1 = dis(input, a1);
////////////////		int dis2 = dis(input, a2);
////////////////		if (dis1 < dis2)return true;
////////////////		else if (dis1 > dis2)return false;
////////////////		else {
////////////////			if (a1 < a2)return true;
////////////////			return false;
////////////////		}
////////////////	}
////////////////};
////////////////
//////////////////////int Distance1(int n1, int n2) {
//////////////////////	return abs(n1 - n2);
//////////////////////}
//////////////////////int Distance2(const string & s1, const string & s2)
//////////////////////{
//////////////////////	return abs((int)s1.length() - (int)s2.length());
//////////////////////}
//////////////////////int a[10] = { 0,3,1,4,7,9,20,8,10,15 };
//////////////////////string b[6] = { "American","Jack","To","Peking","abcdefghijklmnop","123456789" };
//////////////////////int main()
//////////////////////{
//////////////////////	int n; string s;
//////////////////////	while (cin >> n >> s) {
//////////////////////		sort(a, a + 10, Closer<int, int(*)(int, int)>(n, Distance1));
//////////////////////		for (int i = 0; i < 10; ++i)
//////////////////////			cout << a[i] << ",";
//////////////////////		cout << endl;
//////////////////////		sort(b, b + 6, Closer<string, int(*)(const string &, const string &)>(s, Distance2));
//////////////////////		for (int i = 0; i < 6; ++i)
//////////////////////			cout << b[i] << ",";
//////////////////////		cout << endl;
//////////////////////	}
//////////////////////	return 0;
//////////////////////}
////////////////////
////////////////////#include <algorithm>
////////////////////#include <iostream>
////////////////////#include <stack>
////////////////////#include <queue>
////////////////////#include <vector>
////////////////////#include <cstring>
////////////////////#include <cstdlib>
////////////////////#include <string>
////////////////////#include <cmath>
////////////////////#include <map>
////////////////////#include <set>
////////////////////
////////////////////using namespace std;
////////////////////class MyFunc
////////////////////{
////////////////////	// 在此处补充你的代码
////////////////private:
////////////////	int val;//记录几次项
////////////////public:
////////////////	MyFunc(int n) :val(n) {};
////////////////	int operator ()(int n) {
////////////////		int tmp = n;
////////////////		for (int i = 0; i < this->val-1; i++) {
////////////////
////////////////			n *= tmp;
////////////////		}
////////////////		return n;//this->val记录的是几次项
////////////////	}
////////////////////};
////////////////////int main()
////////////////////{
////////////////////	int n;
////////////////////	cin >> n;
////////////////////	while (n--) {
////////////////////		vector<MyFunc> v;
////////////////////		for (int i = 0; i < 5; ++i)
////////////////////			v.push_back(MyFunc(i + 1));
////////////////////		int ans = 1;
////////////////////		for (int i = 0; i < 5; ++i)
////////////////////		{
////////////////////			int m;
////////////////////			cin >> m;
////////////////////			ans += v[i](m);
////////////////////			//cout << v[i](m) << endl;;
////////////////////		}
////////////////////		cout << ans << endl;
////////////////////	}
////////////////////}
////////////////
//////////////////4:printer
//////////////////#include<iostream>
//////////////////#include<algorithm>
//////////////////#include<vector>
//////////////////#include<bitset>
//////////////////
//////////////////using namespace std;
//////////////////
//////////////////
//////////////////class Printer {
//////////////////	// 在此处补充你的代码
////////////////private:
////////////////	int mu;
////////////////public:
////////////////	Printer(int x) :mu(x) {};//这应该是要单独循环吧
////////////////	void operator()(int x) {
////////////////		if (x > mu)
////////////////			cout << x << ",";
////////////////	}
////////////////	void operator()(string s) {
////////////////		if (s.size() > mu) {
////////////////			cout << s << ",";
////////////////		}
////////////////	}
//////////////////};
//////////////////	int main() {
//////////////////
//////////////////		int t;
//////////////////		cin >> t;
//////////////////		while (t--) {
//////////////////			int n, x;
//////////////////			cin >> x >> n;
//////////////////
//////////////////			vector<int> intVec;
//////////////////			for (int i = 0; i < n; ++i) {
//////////////////				int y;
//////////////////				cin >> y;
//////////////////				intVec.push_back(y);
//////////////////			}
//////////////////			for_each(intVec.begin(), intVec.end(), Printer(x));
//////////////////			cout << endl;
//////////////////
//////////////////			vector<string> strVec;
//////////////////			for (int i = 0; i < n; ++i) {
//////////////////				string str;
//////////////////				cin >> str;
////////////////////				strVec.push_back(str);
////////////////////			}
////////////////////			for_each(strVec.begin(), strVec.end(), Printer(x));
////////////////////			cout << endl;
////////////////////		}
////////////////////		return 0;
////////////////////	}
//////////////////
////////////
////////////
////////////
//////////////矩阵排序：要整理这道题！
////////////// Q759043.cpp : Defines the entry point for the console application.
//////////////
////////////
////////////
////////////
////////////#include <iostream>
////////////#include <vector>
////////////#include <algorithm>
////////////
////////////using namespace std;
////////////
////////////class Mat {
////////////	int h, w;
////////////public:
////////////	Mat(int height, int width) :h(height), w(width)
////////////		// 在此处补充你的代码
////////////	{
////////////		p = new int[h * w];
////////////		id = ++cnt;
////////////	}
////////////	int *p;
////////////	int id;
////////////	friend istream& operator>> (istream&, Mat&);
////////////	friend ostream& operator<< (ostream&, Mat&);//友元函数声明时注意格式
////////////	friend bool comparator_1(Mat a, Mat b);//传入两个原型的
////////////	friend struct comparator_2;
////////////	bool operator< (const Mat& other) const//为什么加const？
////////////	{
////////////		if (h * w < other.h * other.w)return true;
////////////		else if (h * w > other.h * other.w)return false;
////////////		else {
////////////			if (id > other.id)return true;
////////////			return false;
////////////		}
////////////	}
////////////	static int cnt;
////////////};
////////////
////////////int Mat::cnt = 0;
////////////
////////////istream& operator >> (istream& input, Mat& m)
////////////{
////////////	for (int i = 0; i < m.h * m.w; i++)
////////////		input >> m.p[i];
////////////	return input;
////////////}
////////////
////////////ostream& operator<<(ostream& output, Mat& m)
////////////{
////////////	for (int i = 0; i < m.h; i++)
////////////	{
////////////		for (int j = 0; j < m.w; j++)
////////////			output << m.p[i * m.w + j] << " ";
////////////		output << endl;
////////////	}
////////////	return output;
////////////}
////////////
////////////bool comparator_1(Mat a, Mat b) {
////////////	int sum1 = 0;
////////////	for (int i = 0; i < a.h * a.w; i++)
////////////		sum1 += a.p[i];
////////////	int sum2 = 0;
////////////	for (int i = 0; i < b.h * b.w; i++)
////////////		sum2 += b.p[i];
////////////	if (sum1 < sum2)return true;
////////////	else if (sum1 > sum2)return false;
////////////	else {
////////////		return a.id > b.id;
////////////	}
////////////}
////////////
////////////struct comparator_2 {
////////////	bool operator()(Mat a, Mat b) {
////////////		return a.id < b.id;
////////////	}
////////////};
////////////
////////////int main()
////////////{
////////////	vector<Mat> m;
////////////	m.push_back(Mat(2, 2));
////////////	m.push_back(Mat(3, 4));
////////////	m.push_back(Mat(2, 2));
////////////	cin >> m[0] >> m[1] >> m[2];
////////////	sort(m.begin(), m.end());
////////////	cout << m[0] << endl << m[1] << endl << m[2] << endl;
////////////	cout << "*************" << endl;
////////////	sort(m.begin(), m.end(), comparator_1);
////////////	cout << m[0] << endl << m[1] << endl << m[2] << endl;
////////////	cout << "*************" << endl;
////////////	sort(m.begin(), m.end(), comparator_2());
////////////	cout << m[0] << endl << m[1] << endl << m[2] << endl;
////////////	return 0;
////////////}
//////////
//////////#include <iostream>
//////////#include <string>
//////////#include <numeric>
//////////#include <algorithm>
//////////using namespace std;
//////////// 在此处补充你的代码
//////////template<class T>
//////////class Print {
//////////public:
//////////	int num;
//////////	Print(int n) :num(n) {};
//////////	Print<T>&operator+(const T&a) {
//////////		num--;
//////////		cout << a;
//////////		if (num == 0)cout << endl;
//////////		return *this;
//////////	}
//////////};
//////////int main() {
//////////	string s[20];
//////////	int num[20];
//////////	int m, n;
//////////
//////////	while (cin >> m >> n) {
//////////		for (int i = 0; i < m; i++) {
//////////			cin >> s[i];
//////////		}
//////////		accumulate(s, s + m, Print<string>(m));
//////////		for (int i = 0; i < n; i++) {
//////////			cin >> num[i];
//////////		}
//////////		accumulate(num, num + n, Print<int>(n));
//////////	}
//////////}
//////////
////////
//////////正向与反向输出
////////#include <cstring>
////////#include <cstdlib>
////////#include <string>
////////#include <iostream>
////////#include <vector>
////////#include <iterator>
////////using namespace std;
////////class C1 {
////////	// 在此处补充你的代码
////////private:
////////	int num;
////////	vector<int> a;
////////	bool re;
////////public:
////////	C1(int n, vector<int>s) :num(n) {
////////		a = s;
////////		re = 1;
////////	}
////////	int& operator[](int i) {//[]的重载
////////		return a[num-1-i];//一个小坑，copy是先反转再执行，所以要在[]中更改顺序
////////	}
////////	const int*operator*() {//小技巧，整理！
////////		if (re) {
////////			//vector<int>::iterator s = a.begin();
////////			//vector<int>::iterator e = a.end()-1;
////////			//int tmp = 0;
////////			//while (s <= e) {
////////			//	tmp = *s; *s= *e; *e= tmp;
////////			//	s++; e--;//代码重用率极高
////////			//}
////////			//但是这就先反转，再输出了
////////			//std::reverse(a.begin(), a.end());
////////			re = 0;
////////		}
////////		return &a[0];//返回首个地址，再加个星
////////	}
////////};
////////
////////int main()
////////{
////////	vector<int> v;
////////	int p;
////////	int size;
////////	int k;
////////	cin >> k;
////////	while (k--) {
////////		cin >> size;
////////		v.clear();
////////		for (int i = 0; i < size; ++i) {
////////			cin >> p;
////////			v.push_back(p);
////////		}
////////		C1 o1 = C1(size, v);
////////		ostream_iterator<int> it(cout, "---");
////////		copy(*o1, (*o1) + size, it);
////////		cout << endl;
////////		for (int i = 0; i < size; ++i) {
////////			o1[i] *= 2;
////////			cout << o1[i] << "***";
////////		}
////////		cout << endl;
////////	}
////////
////////}
//////
////////0508：找第一个最小的
//////#include <iostream>
//////#include <string>
//////#include <vector>
//////using namespace std;
//////// 在此处补充你的代码
//////template<class T1,class T2,class Pre>
//////T1 FindFirstLess(T1 p1, T1 p2, T2 m, Pre p) {
//////	for (T1 i = p1; i < p2; i++) {
//////		if (p(*i, m))
//////			return i;
//////	}
//////	return p2;//再复盘一下，这个迭代器可以直接返回对应的类型
//////}
//////int main()
//////{
//////	int t;
//////	cin >> t;
//////	while (t--) {
//////		int n;
//////		string type;
//////		cin >> n >> type;
//////		vector<int> vi;
//////		vector<string> vs;
//////		if (type == "N") {
//////			int a, m;
//////			for (int i = 0; i < n - 1; ++i) {
//////
//////				cin >> a;
//////				vi.push_back(a);
//////			}
//////			cin >> m;
//////			vector<int>::iterator p = FindFirstLess(vi.begin(), vi.end(), m, less<int>());
//////			if (p != vi.end())
//////				cout << *p << endl;
//////			else
//////				cout << "Not Found" << endl;
//////
//////		}
//////		else {
//////			string a, m;
//////			for (int i = 0; i < n - 1; ++i) {
//////				cin >> a;
//////				vs.push_back(a);
//////			}
//////			cin >> m;
//////			vector<string>::iterator p = FindFirstLess(vs.begin(), vs.end(), m, less<string>());
//////			if (p != vs.end())
//////				cout << *p << endl;
//////			else
//////				cout << "Not Found" << endl;
//////
//////		}
//////	}
//////	return 0;
//////}
////
////#include <iostream>
////#include <iterator>
////using namespace std;
////
////template<class T1, class T2>
////void Copy(T1 s, T1 e, T2 x) {
////	for (; s != e; ++s, ++x)
////		*x = *s;
////}
////// 在此处补充你的代码
////class Fib {
////public:
////	int n;
////	int pre; int now;
////	Fib(int n_) :n(n_) {
////		now = 1; pre = 0;
////	}
////	bool operator!=(const Fib&a) {//注意copy函数中用到了！=要实现重载！
////		if (n != a.n)return true;
////		return false;
////	}
////	void operator++() {//利用copy函数的++属性实现计算
////		n++;
////		int tmp = now + pre;
////		pre = now;
////		now = tmp;
////	}
////	int operator*() {
////		return now;
////	}
////};
////int main() {
////	while (true) {
////		int n;
////		cin >> n;
////		if (n == 0)
////			break;
////
////		Fib f1(1), f2(n);
////		ostream_iterator<int> it(cout, " ");
////		Copy(f1, f2, it);
////		cout << endl;
////	}
////	return 0;
////}
////
//////改良3D
////#include <iostream>
////#include <iomanip>
////#include <cstring>
////using namespace std;
////template <class T>
////class CArray3D
////{
////private:
////	T*p;
////	int f; int r; int c;
////public:
////	CArray3D(int f_, int r_, int c_) :f(f_), r(r_), c(c_) {
////		p = new T[f*c*r];//f层r行c列
////	}
////	class CArray2D {
////	public:
////		T*fp;//一层元素的起始位置
////		int c;
////		CArray2D(T*p_, int c_) :fp(p_), c(c_) {}
////		T*operator[](int r) {
////			return fp + r * c;//返回本层第r行起始位置
////		}
////		operator T*() {//重载T*类型转换符号
////			return fp;//a[1]是一个对象，不能直接初始化，所以类型构造返回本层地址
////		}
////	};
////	CArray2D operator[](int layer) {
////		return CArray2D(p + layer * r*c, c);//获得第layer层的起始地址
////	}
////	~CArray3D() {
////		delete[]p;
////	}
////	operator int*() {
////		return p;
////	}
////
////
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
////	for (int i = 0; i < 3; ++i)
////		for (int j = 0; j < 4; ++j)
////			for (int k = 0; k < 5; ++k)
////				a[i][j][k] = No++;
////	PrintA();
////	memset(a, -1, 60 * sizeof(int));        //注意这里
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
//
//
//#include<iostream>
//#include<stdio.h>
//#include<stack>
//using namespace std;
//const int N = 1001001;
//int ans[N];
//int temperature[N];
//int main() {
//	int n;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> temperature[i];
//	}
//	stack<int> s;
//	for (int i = 0; i < n; i++) {
//		while (!s.empty() && temperature[i] > temperature[s.top()])
//		{
//			int val = s.top();
//			s.pop();
//			ans[val] = i - val;
//		}
//		s.push(i);
//	}
//	for (int i = 0; i < n; i++) {
//		cout << ans[i] << " ";
//	}
//	cout << endl;
//	return 0;
//}