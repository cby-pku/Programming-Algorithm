//4.1完成复习

////#include <iostream>
////using namespace std;
////class Apple {
////public:
////	static int nTotalNumber;
////	// 在此处补充你的代码
////
////	Apple() {
////		nTotalNumber++;//初始设立变量时进行初始化
////	}
////	~Apple() {//有对象消亡，就要自动调用
////		nTotalNumber--;
////	}
////	static void PrintTotal() {
////		cout << nTotalNumber << endl;
////	}
////};
////int Apple::nTotalNumber = 0;
////Apple Fun(const Apple & a) {//定义一个函数调用了apple里面的变量
////	a.PrintTotal();//默认初始为4
////	//cout << 1 << endl;
////	return a;
////}
////int main()
////{
////	Apple * p = new Apple[4];
////	Fun(p[2]);
////	Apple p1, p2;
////	Apple::PrintTotal();
////	delete[] p;//调用析构函数，复制构造函数的临时对象消亡
////	p1.PrintTotal();//最后也会调用析构函数
////	return 0;
////}
//////构造4次；调用一次复制构造，消亡-1；声明两变量+2变为5；消灭指针调用4次析构函数，变为1；最后消灭全局变量
////
////B：返回什么才好呢
//#include <iostream>
//using namespace std;
//class A {
//public:
//	int val;
//	A() {
//		val = 123;
//	}
//	A(A&n) {//尝试定义复制构造函数
//		val = n.val;
//	}
//	A &GetObj() {//返回值为地址引用
//		//指向自己，注意返回的是一个临时对象
//		return *this;
//	}
//	A(int n) {//实现m的赋值
//		val = n;
//	}
//};
//int main()
//{
//	int m, n;
//	A a;
//	cout << a.val << endl;
//	while (cin >> m >> n) {
//		a.GetObj() = m;//也可以用类型构造转化为A的对象
//		cout << a.val << endl;
//		a.GetObj() = A(n);//生成了一个A类的对象
//		cout << a.val << endl;
//	}
//	return 0;
//}
//
//
////#include <iostream>
////#include <string>
////using namespace std;
////class Base {
////public:
////	int k;
////	Base(int n) :k(n) { }
////};
////class Big
////{
////public:
////	int v;
////	Base b;//其实你会发现封闭类不是在写魔兽的时候也用到了嘛，所以其实很简单，就是一个小类，但是要记得初始化
////	// 在此处补充你的代码
////	Big(int n) : b(n),v(n) {
////	}
////	Big(const Big& a):v(a.v),b(a.v) {//同时要进行初始化
////	}
////};
////int main()
////{
////	int n;
////	while (cin >> n) {
////		Big a1(n);
////		Big a2 = a1;
////		cout << a1.v << "," << a1.b.k << endl;
////		cout << a2.v << "," << a2.b.k << endl;
////	}
////}
//
//////D：奇怪的类复制
////#include <iostream>
////using namespace std;
////class Sample {
////public:
////	int v;
////	// 在此处补充你的代码
////	Sample(int n) {//用于d的初始化
////		v = n;
////	}
////	Sample(){}//用于a的初始化
////	Sample(const Sample&a) {//用于b 的初始化
////		v = a.v + 2;//调用了两次复制构造函数
////	}
////
////};
////void PrintAndDouble(Sample o)
////{
////	cout << o.v;
////	cout << endl;
////}
////int main()
////{
////	Sample a(5);
////	Sample b = a;
////	PrintAndDouble(b);//调用了两次复制构造函数
////	Sample c = 20;
////	PrintAndDouble(c);//以c为对象的时候又默认生成临时对象然后调用了一次
////	Sample d;
////	d = a;
////	cout << d.v;
////	return 0;
////}