//4.1完成复习


//////////////////
////////////////////B：两种计数
//////////////////#include <iostream>
//////////////////using namespace std;
//////////////////
//////////////////class Counter {
//////////////////
//////////////////
//////////////////private:
//////////////////	static int nGlobalNumber;
//////////////////	int nLocalNumber;
//////////////////public:
//////////////////	// 在此处补充你的代码
//////	Counter(int m=1):nLocalNumber(m){
//////		nGlobalNumber++;
//////	}
//////	Counter(Counter&c) {
//////		nLocalNumber = c.nLocalNumber;
//////		nGlobalNumber++;
//////	}
//////	~Counter() {
//////		nGlobalNumber--;
//////	}
//////////////////	void add(int n) { nLocalNumber += n; }
//////////////////
//////////////////	void PrintLocalNumber() {
//////////////////		cout << nLocalNumber << endl;
//////////////////	}
//////////////////	static void PrintGlobalNumber() {
//////////////////		cout << nGlobalNumber << endl;
//////////////////	}
//////////////////
//////////////////};
//////////////////int Counter::nGlobalNumber = 0;
//////////////////
//////////////////int main()
//////////////////{
//////////////////	Counter::PrintGlobalNumber();
//////////////////	Counter b1, b2;
//////////////////	Counter::PrintGlobalNumber();
//////////////////	b1.PrintLocalNumber();
//////////////////	b2.add(10);
//////////////////	b2.PrintLocalNumber();
//////////////////	Counter* b3 = new Counter(7);
//////////////////	b3->PrintLocalNumber();
//////////////////	Counter b4 = b2;
//////////////////	b4.PrintLocalNumber();
//////////////////	Counter::PrintGlobalNumber();
//////////////////	if (b3 != NULL)
//////////////////	{
//////////////////		delete b3;
//////////////////		b3 = NULL;
//////////////////	}
//////////////////	Counter::PrintGlobalNumber();
//////////////////
//////////////////
//////////////////	return 0;
//////////////////}
//////////////////C:分数类
////////////////#include <iostream>
////////////////using namespace std;
////////////////int gcd(int x, int y) {
////////////////	return x % y == 0 ? y : gcd(y, x%y);
////////////////}
////////////////class Fraction
////////////////{
////////////////	int num, den;
////////////////public:
//////	// 在此处补充你的代码
//////	Fraction(int m = 0,int n=1):num(m),den(n){}//初始化
//////	Fraction&operator*=(const Fraction&c) {
//////		num *= c.num;
//////		den *= c.den;
//////		return *this;
//////	}
//////	Fraction&operator/=(const Fraction&c) {
//////		num *= c.den;
//////		den *= c.num;
//////		return *this;
//////	}
//////	Fraction operator*(const Fraction&c) {
//////		Fraction tmp(num*c.num, den*c.den);
//////		return tmp;//因为作右值，所以还真得返回变量，然后让编译器自己做类型转换
//////	}
//////	Fraction operator/(const Fraction&c) {
//////		Fraction tmp(num*c.den, den*c.num);
//////		return tmp;
//////	}
//////	operator float () {
//////		return 1.0*num /den;
//////	}
//////	friend ostream&operator<<(ostream&os,const Fraction&c) {
//////		int t = gcd(c.num, c.den);
//////		os << c.num/t <<"/"<< c.den/t;
//////		return os;
//////	}//整理此处算法，辗转相除法
////////////////};
////////////////
////////////////int main() {
////////////////	int a, b, c;
////////////////	cin >> a >> b >> c;
////////////////	Fraction f(a, b), g(c);
////////////////	f *= g;
////////////////	cout << f << endl;
////////////////	f /= g;
////////////////	cout << f << endl;
////////////////	f = f * f;
////////////////	cout << f << endl;
////////////////	f = f / g;
////////////////	cout << f << endl;
////////////////	cout << (float)f << endl;
////////////////	return 0;
////////////////}
//////////////
////////////////D：静态成员
//////////////#include <iostream>
//////////////#include <vector>
//////////////using namespace std;
//////////////
//////////////class A {
//////////////	static int count;
//////////////public:
//////////////	// 在此处补充你的代码
//////	A() {
//////		count++;
//////	}
//////	static int theNumberOfA() {
//////		return count;
//////	}
//////////////};
//////////////
//////////////int A::count = 0;
//////////////
//////////////int main() {
//////////////	vector<A> v;
//////////////
//////////////	for (int i = 0; i < 3; i++) {
//////////////		{
//////////////			A a;
//////////////			v.push_back(a);
//////////////		}
//////////////		cout << A::theNumberOfA() << endl;
//////////////	}
//////////////
//////////////	return 0;
//////////////}
////////////
//////////////整理
//////////////#include <stdio.h>
//////////////#include <iostream>
//////////////using namespace std;
//////////////class MyNum {
//////////////public:
//////////////	char C;
//////////////	MyNum(char c = '0') : C(c) {}
//////////////	// 在此处补充你的代码
//////	MyNum operator*(const MyNum&c) {
//////		int n = C - '0';
//////		int m = c.C -'0';
//////
//////		MyNum tmp(n*m+'0');
//////		return tmp;
//////	}
//////	operator int() {
//////		return C - '0';
//////	}
//////////////};
//////////////
//////////////int main() {
//////////////	char m, n;
//////////////	cin >> m >> n;
//////////////	MyNum n1(m), n2(n);
//////////////	MyNum n3;
//////////////	n3 = n1 * n2;
//////////////	cout << int(n3) << endl;
//////////////	return 0;
//////////////}
////////////
////////06:二进制数位复制并取反
//////#include<iostream>
//////#include<bitset>
//////using namespace std;
//////int main() {
//////	int a, b, i, j;
//////	cin >> a >> b >> i >> j;
//////	int flag= 0;
//////	for (int l = i; l <= j; l++) {
//////		flag = (b >> l) & 1;//把第i位提炼出来的正确方法
//////		if (flag) {
//////			//flag这时候为1
//////			a &= ~(1 << l);
//////		}
//////		else {
//////			a |= (1 << l);
//////		}
//////	}
//////	cout << a << endl; return 0;
//////}
//////////#include <iostream>
//////////using namespace std;
//////////int gcd(int a, int b) { // 计算两个数的最大公约数
//////////	return (!b) ? a : gcd(b, a % b);
//////////}
//////////class Fraction {
//////////	int p, q;
//////////public:
//////////	// 在此处补充你的代码
//////	Fraction(int p_ = 0, int q_ = 1) :p(p_), q(q_) {};
//////	friend istream&operator>>(istream&is,  Fraction&c) {
//////		is >> c.p >> c.q;
//////		return is;
//////	}
//////	friend ostream&operator<<(ostream&os, const Fraction&c) {
//////		int t = gcd(c.p, c.q);
//////		if (c.q / t == 1) {
//////			os << c.p/t; return os;
//////		}
//////		os << c.p/t << '/' << c.q/t;
//////		return os;
//////	}
//////	Fraction operator*(const Fraction&c) {
//////		Fraction tmp(p*c.p, q*c.q);
//////		return tmp;
//////	}
//////////};
//////////
//////////int main() {
//////////	int testcases;
//////////	cin >> testcases;
//////////	while (testcases--) {
//////////		Fraction a, b, two(2);
//////////		cin >> a >> b;
//////////		cout << a << " * " << b << " = " << a * b << endl;
//////////		cout << "2 * " << a << " = " << two * a << endl;
//////////		cout << b << " * 3 = " << b * 3 << endl;
//////////	}
//////////	return 0;
//////////}
//////
////单目运算符，真有你的！
//#include <iostream>
//using namespace std;
//class A {
//private:
//	int value;
//public:
//	A(int n) {
//		value = n;
//	}
//	int get_value() {
//		return value;
//	}
//	A *operator->() {
//		return this;
//	}//强制把左边这个表达式右值转换为左值
//	A&operator+(const A*c) {
//		value = value + c->value;
//		return *this;
//	}
//
//
//};
//class B :public A {//这是在考察继承类的构造函数
//public:
//	B(int n) :A(n) {};
//	int get_value() {
//		A::get_value();
//	}
//};
//class C :public A {
//public:
//	C(int n) :A(n) {};
//	int get_value() {
//		A::get_value();
//	}
//
//};
//
//// 在此处补充你的代码
//int main() {
//	int t;
//	cin >> t;
//	while (t--) {
//		int aa, bb, cc;
//		cin >> aa >> bb >> cc;
//		A a(aa);
//		B b(bb);
//		C c(cc);
//		A* x = &a;
//		A* y = &b;
//		A* z = &c;
//		cout << (x->get_value() + y->get_value() + z->get_value()) << " ";
//		cout << ((*x) + y + z)->get_value() << endl;
//	}
//	return 0;
//}
////////#include <iostream>
////////using namespace std;
////////int getByte(int x, int i) {
////////	return
////////		// 在此处补充你的代码
//////		//(x >> i * 8) & 255;//对啊应该是255，那11111111是十进制的啊！
////////}
////////int main() {
////////	int n;
////////	cin >> n;
////////	while (n--) {
////////		int x, i;
////////		cin >> x >> i;
////////		cout << getByte(x, i) << endl;
////////	}
////////	return 0;
////////}