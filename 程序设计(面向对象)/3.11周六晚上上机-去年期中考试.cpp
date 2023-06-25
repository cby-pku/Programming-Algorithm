//4.1完成复习
////////////////A输出200
////////////////#include<iostream>
////////////////using namespace std;
////////////////class Number {
////////////////public:
////////////////	int num;
//////////	Number(int n = 0) : num(n) {}
//////	Number operator*(const Number& c) {
//////		Number tmp(num * c.num);
//////		return tmp;
//////	}
//////	operator int() {
//////		return num;//返回一个常量输出
//////	}
////////////////};
////////////////
////////////////int main() {
////////////////	Number n1(10), n2(20);
////////////////	Number n3;
////////////////	n3 = n1 * n2;//因为是作为右值，不能返回地址，要返回一个常量
////////////////	cout << int(n3) << endl;
////////////////	return 0;
////////////////}
////////////////B：输出指定结果
////////////////#include <iostream>
////////////////using namespace std;
////////////////class Number {
////////////////public:
////////////////	int num;
////////////////	Number(int n) : num(n) {
////////////////	}
////////////////	// 在此处补充你的代码
//////	Number(Number& c) {
//////		num = c.num;
//////	}
//////	int& value() {
//////		return num;
//////	}
//////	Number& operator+(const Number& c) {
//////		num = num + c.num; return *this;
//////	}
////////////////};
////////////////int main() {
////////////////	Number a(2);
////////////////	Number b = a;
////////////////	cout << a.value() << endl;
////////////////	cout << b.value() << endl;
////////////////	a.value() = 8;
////////////////	cout << a.value() << endl;
////////////////	a + b;//这个整体是右值，但是式子的意思是，在a的基础上+b，所以要返回*this，仍然指向a
////////////////	cout << a.value() << endl;
////////////////	return 0;
////////////////}
////////////////C：计算整数的平方和
////////////////#include <iostream>
////////////////using namespace std;
//////class CType {
//////private:
//////	int num;
//////public:
//////	void setvalue(int n) {
//////		num = n;
//////	}
//////	friend ostream& operator<<(ostream& os, const CType& c) {
//////		os << c.num; return os;
//////	}
//////	CType operator++(int) {
//////		CType tmp(*this);
//////		num = num * num;
//////		return tmp;//要返回右值才能输出
//////	}
//////
//////};
////////////////int main(int argc, char* argv[]) {
////////////////	CType obj;
////////////////	int   n;
////////////////	cin >> n;
////////////////	while (n) {
////////////////		obj.setvalue(n);
////////////////		cout << obj++ << " " << obj << endl;
////////////////		cin >> n;
////////////////	}
////////////////	return 0;
////////////////}
////////D；计算整数k
//////#include<iostream>
//////#include<bitset>
//////using namespace std;
//////int main() {
//////	int t, n, i, j;
//////	cin >> t;
//////	while (t--) {
//////		cin >> n >> i >> j;
//////		bitset<32>b(n);
//////		for (int l = 0; l < i; l++) {
//////			b.reset(l);
//////		}
//////		for (int l = i + 1; l < j; l++) {
//////			b.set(l);
//////		}
//////		for (int l = j + 1; l < 32; l++) {
//////			b.reset(l);
//////		}
//////		b.flip(j);
//////		cout << hex << b.to_ulong() << endl;
//////	}return 0;
//////}
//////
//////////////
//////////////
//////////////
////////////////E：两数相乘
////////////////#include <iostream>
////////////////using namespace std;
////////////////class Number {
////////////////public:
////////////////	int num;
////////////////	Number(int n) : num(n) {}
//////////	// 在此处补充你的代码
//////	Number& operator*(int n) {
//////		num = num * n; return *this;
//////	}
//////	Number(Number& c) {
//////		num = c.num;
//////	}
//////	friend int operator==(int n, const Number& c) {
//////		if (n == c.num)return 1;
//////		return 0;
//////	}
//////	friend ostream& operator<<(ostream& os, const Number& c) {
//////		os << c.num; return os;
//////	}
////////////////};
////////////////int main() {
////////////////	int t;
////////////////	int m, n;
////////////////	cin >> t;
////////////////	while (t--) {
////////////////		cin >> m >> n;
////////////////		Number n1(m), n2 = n1 * n;
////////////////		if (m * n == n2)
////////////////			cout << n2 << endl;
////////////////	}
////////////////	return 0;
////////////////}
////////////////6：输出指定结果
////////////////#include <iostream>
////////////////using namespace std;
////////////////
////////////////class A {
////////////////public:
//////	// 在此处补充你的代码
//////	int num;
//////	A(int n) :num(n) {}
//////	A(A& c) { num = c.num; }
//////	friend ostream& operator<<(ostream& os, const A& c) {
//////		os << c.num; return os;
//////	}
//////	A& getValue() {
//////		return *this;
//////	}
//////	A& operator+=(const A& c) {
//////		num += c.num; return *this;
//////	}
//////	A& operator-=(int n) {
//////		num -= n; return *this;//因为b本身在变，所以也要返回*this，然后再和a+=的时候相当于自动转换成右值进行相关运算了
//////	}
////////////////};
////////////////
////////////////int main() {
////////////////	int t;
////////////////	cin >> t;
////////////////	while (t--) {
////////////////		int m, n, k;
////////////////		cin >> m >> n >> k;
////////////////		A a(m);
////////////////		A b = a;
////////////////		cout << b << endl;
////////////////		cout << (a += b -= n) << endl;
////////////////		cout << a.getValue() << endl;
////////////////		a.getValue() = k;
////////////////		cout << a << endl;
////////////////	}
////////////////	return 0;
////////////////}
////////////////7：实现复数类
////////////////#include <iostream>
////////////////using namespace std;
//////class Complex {
//////private:
//////	int real; int imag;
//////public:
//////	Complex(int r = 0, int i = 0) :real(r), imag(i) {}
//////	Complex(Complex& c) {
//////		real = c.real; imag = c.imag;
//////	}
//////	Complex(const char* s) {
//////		real = s[0] - '0'; imag = s[2] - '0';
//////	}
//////	friend ostream& operator<<(ostream& os, const Complex& c) {
//////		if (c.imag == 0) {
//////			cout << c.real; return os;
//////		}
//////		if (c.real == 0 && c.imag != 0) {
//////			cout << c.imag << 'i'; return os;
//////		}
//////		os << c.real << '+' << c.imag << 'i'; return os;
//////	}
//////	Complex operator*(const Complex& c) {
//////		int tmpr = real * c.real - imag * c.imag;
//////		int tmpi = real * c.imag + imag * c.real;
//////		Complex tmp(tmpr, tmpi);
//////		return tmp;
//////	}
//////	Complex operator+(const Complex& c) {
//////		Complex tmp(real + c.real, imag + c.imag);
//////		return tmp;
//////	}
//////	Complex operator-(const Complex& c) {
//////		Complex tmp(real - c.real, imag - c.imag);
//////		return tmp;
//////	}
//////	Complex& operator+=(const Complex& c) {
//////		real += c.real; imag += c.imag;
//////		return *this;
//////	}
//////	Complex& operator-=(const Complex& c) {
//////		real -= c.real; imag -= c.imag;
//////		return *this;
//////	}
//////	Complex& operator*=(const Complex& c) {
//////		int tmpr = real * c.real - imag * c.imag;
//////		int tmpi = real * c.imag + imag * c.real;
//////		real = tmpr; imag = tmpi;
//////		return *this;
//////	}
//////};
////////////////int main() {
////////////////	Complex c1;
////////////////	Complex c2("3+2i"); // 用字符串初始化时，只需考虑"a+bi"的形式，其中a和b都是1位数字
////////////////	Complex c3(c2);
////////////////	Complex c4(-15);
////////////////	cout << c2 << endl;
////////////////	cout << c3 << endl;
////////////////	cout << c4 << endl;
////////////////	cout << c2 + c4 << endl;
////////////////	cout << c2 - c3 << endl;
////////////////	cout << c2 * c3 << endl;
////////////////	c2 += c4;
////////////////	cout << c2 << endl;
////////////////	c2 -= -12;
////////////////	cout << c2 << endl;
////////////////	c3 *= c3;
////////////////	cout << c3 << endl;
////////////////	return 0;
////////////////}
////////////////08:二进制输出
//////////////#include <iostream>
//////////////#include <string>
//////////////using namespace std;
//////////////string dec2bin(int x) {
//////////////	// 在此处补充你的代码
//////	string s1; string s = "";
//////	while (x) {
//////		if (x % 2) {
//////			s1 = "1";
//////		}
//////		else { s1 = "0"; }
//////		s = s1 + s;
//////		x /= 2;
//////	}
//////	for (int i = s.size(); i < 31; i++) {
//////		s = "0" + s;
//////	}return s;
//////////////}
//////////////int main() {
//////////////	int n;
//////////////	cin >> n;
//////////////	while (n--) {
//////////////		int x;
//////////////		cin >> x;
//////////////		cout << dec2bin(x) << endl;
//////////////	}
//////////////	return 0;
//////////////}
////////////#include <iostream>
////////////using namespace std;
////////////class A
////////////{
////////////	static int num;
////////////public:
////////////	A() { num += 1;}
////////////	void func()
////////////	{
////////////		cout << num << endl;
////////////	}
////////////	// 在此处补充你的代码
//////	void func()const {
//////		cout << --num << endl;
//////	}
////////////};
////////////
////////////int A::num = 1;
////////////
////////////int main()
////////////{
////////////	A a1;
////////////	const A a2 = a1;
////////////	A & a3 = a1;
////////////	const A & a4 = a1;
////////////
////////////	a1.func();
////////////	a2.func();
////////////	a3.func();
////////////	a4.func();
////////////
////////////	return 0;
////////////}
////////////10.三生三世
//////////#include<iostream>
//////////#include<cstring>
//////////#include<list>
//////////#include<algorithm>
//////////using namespace std;
//////////
//////////class TV_Drama {
//////////public:
//////////	char name[100];
//////////	int actor;
//////////	int story;
//////////	int acting_skill;
//////////	// 在此处补充你的代码
//////	TV_Drama( char*n,int a,int s,int ac):actor(a),story(s),acting_skill(ac){
//////		int len = 0;
//////		for (int i = 0; n[i] != '\0'; i++) {
//////			name[i] = n[i];
//////			len++;
//////		}
//////		name[len] = '\0';
//////	}
//////	bool operator<(TV_Drama&l) {//比较时都是传引用?
//////		return actor > l.actor;//默认的比较方式
//////	}
//////
//////};
//////void Printer(TV_Drama x) {
//////	cout << x.name << ";";
//////}
//////bool comparator_1(TV_Drama&x1, TV_Drama&x2) {
//////	return x1.story > x2.story;
//////}
//////class comparator_2
//////{public:
//////	comparator_2(){}//用一个类的构造函数，真行
//////	bool operator()(TV_Drama&x1, TV_Drama&x2) {
//////		return x1.acting_skill > x2.acting_skill;
//////	}
//////};
//////////	int main() {
//////////		list<TV_Drama> lst;
//////////		int n;
//////////
//////////		cin >> n;
//////////		char  _name[100];
//////////		int _actor, _story, _acting_skill;
//////////		for (int i = 0; i < n; i++) {
//////////			cin.ignore();
//////////			cin.getline(_name, 100);
//////////			cin >> _actor >> _story >> _acting_skill;
//////////			lst.push_back(TV_Drama(_name, _actor, _story, _acting_skill));
//////////		}
//////////
//////////		lst.sort();
//////////		for_each(lst.begin(), lst.end(), Printer);
//////////		cout << endl;
//////////
//////////		lst.sort(comparator_1);
//////////		for_each(lst.begin(), lst.end(), Printer);
//////////		cout << endl;
//////////
//////////		lst.sort(comparator_2());//构造了一个类，出现了一个临时对象，然后重载（）实现比较
//////////		for_each(lst.begin(), lst.end(), Printer);
//////////		cout << endl;
//////////
//////////		return 0;
//////////	}