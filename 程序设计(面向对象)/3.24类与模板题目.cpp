////////////////A
//////////////#include <iostream>
//////////////#include <string>
//////////////using namespace std;
//////////////template <class T>
//////////////T SumArray(T*a,T*b){
//////////////	T sum = *a;//因为传入的是一个指针，先解引用得到对应的内存数据
//////////////	for (T*i = a+1; i < b; i++) {
//////////////		sum += *i;
//////////////	}
//////////////	return sum;
//////////////	// 在此处补充你的代码
//////////////	
//////////////}
//////////////int main() {
//////////////	string array[4] = { "Tom","Jack","Mary","John" };
//////////////	cout << SumArray(array, array + 4) << endl;
//////////////	int a[4] = { 1, 2, 3, 4 };  //提示：1+2+3+4 = 10
//////////////	cout << SumArray(a, a + 4) << endl;
//////////////	return 0;//数组名相当于一个指针
//////////////}
////////////
//////////////B：
////////////#include <iostream>
////////////#include <string>
////////////using namespace std;
////////////// 在此处补充你的代码
////////////template<class T,class T1>//，函数内部参数要进行新的类型模板
////////////void MyForeach(T*a,T*b,void func(T1 t)){//用类模板进行函数的重载
////////////	for (T*i = a; i < b; i++) {//传入的是指针，当然要用对应类型的指针来进行初始化
////////////		func(*i);//需要解引用！
////////////	}
////////////}
////////////void Print(string s)
////////////{
////////////	cout << s;
////////////}
////////////void Inc(int & n)
////////////{
////////////	++n;
////////////}
////////////string array[100];
////////////int a[100];
////////////int main() {
////////////	int m, n;
////////////	while (cin >> m >> n) {
////////////		for (int i = 0; i < m; ++i)
////////////			cin >> array[i];
////////////		for (int j = 0; j < n; ++j)
////////////			cin >> a[j];
////////////		MyForeach(array, array + m, Print);
////////////		cout << endl;
////////////		MyForeach(a, a + n, Inc);
////////////		for (int i = 0; i < n; ++i)
////////////			cout << a[i] << ",";
////////////		cout << endl;
////////////	}
////////////	return 0;
////////////}
//////////
////////////简单的Filter
//////////#include <iostream>
//////////#include <string>
//////////using namespace std;
//////////// 在此处补充你的代码
//////////template<class T,class T1>
////////////其实编写模板类最后return出c的对象即可
//////////T*Filter(T*a, T*b, T*n, T1*pt) {//传一个函数指针，这里是因为不知道函数的返回类型是什么，而上面相当于知道了函数一定是void型的，而只是形参类型不一样
//////////	for (T*i = a; i < b; i++) {
//////////		if (pt(*i)) {//把满足T1函数条件的赋给新的数组，并进行数组指针的后移，由于赋值的数组一定是同类型的，所以可以都用同一个模板来实现
//////////			*n = *i;
//////////			++n;//指针后移
//////////		}
//////////	}
//////////	return n;//返回指针
//////////}
//////////bool LargerThan2(int n)
//////////{
//////////	return n > 2;
//////////}
//////////bool LongerThan3(string s)
//////////{
//////////	return s.length() > 3;
//////////}
//////////
//////////string as1[5] = { "Tom","Mike","Jack","Ted","Lucy" };
//////////string as2[5];
//////////int  a1[5] = { 1,2,3,4,5 };
//////////int a2[5];
//////////int main() {
//////////	string * p = Filter(as1, as1 + 5, as2, LongerThan3);
//////////	for (int i = 0; i < p - as2; ++i)
//////////		cout << as2[i];
//////////	cout << endl;
//////////	int * p2 = Filter(a1, a1 + 5, a2, LargerThan2);
//////////	for (int i = 0; i < p2 - a2; ++i)
//////////		cout << a2[i] << ",";
//////////	return 0;
//////////}
////////#include <iostream>
////////using namespace std;
////////class MyCin
////////{
////////	// 在此处补充你的代码
////////private:
////////	bool bstop;
////////public:
////////	MyCin() {//一般可能还需要在构造函数里输入一下，见下文
////////		bstop = false;
////////	}
////////	 operator bool(){//重载()因为调用了Mycin这个函数
////////		return !bstop;
////////	}
////////	MyCin&operator>>(int&n) {
////////		cin >> n;
////////		if (n == -1)bstop = true;
////////		return *this;
////////	}
////////};
////////int main()
////////{
////////	MyCin m;
////////	int n1, n2;
////////	while (m >> n1 >> n2)
////////		cout << n1 << " " << n2 << endl;
////////	return 0;
////////}
////////F:这个模板并不难
//////#include <iostream>
//////#include <string>
//////#include <cstring>
//////using namespace std;
//////template <class T>
//////class myclass {
//////	// 在此处补充你的代码
//////private:
//////	int size;
//////	T*p;
//////public:
//////	myclass(const T*m, int n) : size(n) {
//////		p = new T[size + 1];
//////		for (int i = 0; i < size; i++) {
//////			p[i] = m[i];//用给的这个数组实现赋值
//////		}
//////	};
//////	~myclass() {//有指针就自己写一下析构函数
//////		delete[] p;
//////	}
//////	void Show()
//////	{
//////		for (int i = 0; i < size; i++) {
//////			cout << p[i] << ",";
//////		}
//////		cout << endl;
//////	}
//////};
//////int a[100];
//////int main() {
//////	char line[100];
//////	while (cin >> line) {
//////		myclass<char> obj(line, strlen(line));;
//////		obj.Show();
//////		int n;
//////		cin >> n;
//////		for (int i = 0; i < n; ++i)
//////			cin >> a[i];
//////		myclass<int> obj2(a, n);
//////		obj2.Show();
//////	}
//////	return 0;
//////}
////
////#include <iostream>
////using namespace std;
////
////bool Greater2(int n1, int n2)
////{
////	return n1 > n2;
////}
////bool Greater1(int n1, int n2)
////{
////	return n1 < n2;
////}
////bool Greater3(double d1, double d2)
////{
////	return d1 < d2;
////}
////
////template <class T1, class T2>//函数指针和函数本身应该没有差别
////void mysort(T1*start, T1*end, T2* func) {//T1一定为int类型而非int*，否则没法给temp赋类型
////	for (int i = 0; i < end - start; i++) {//因为传入的是数组名所以肯定是要用指针传入，但是[]又自带解引用的效果，所以这样是可以的
////		for (int j = 0; j < end - start; j++) {
////			if (func(start[i], start[j])) {
////				T1 temp = start[i];
////				start[i] = start[j];
////				start[j] = temp;
////			}//实际就是一个交换代码
////		}
////	}
////}
////	// 在此处补充你的代码
////
////#define NUM 5
////int main()
////{
////	int an[NUM] = { 8,123,11,10,4 };
////	mysort(an, an + NUM, Greater1); //从小到大排序 
////	for (int i = 0; i < NUM; i++)
////		cout << an[i] << ",";
////	mysort(an, an + NUM, Greater2); //从大到小排序 
////	cout << endl;
////	for (int i = 0; i < NUM; i++)
////		cout << an[i] << ",";
////	cout << endl;
////	double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
////	mysort(d + 1, d + 5, Greater3); //将数组从下标1到下标4从小到大排序 
////	for (int i = 0; i < 6; i++)
////		cout << d[i] << ",";
////	return 0;
////}
//
////E：山寨版istream_iterator
//#include <iostream>
//#include <string>
//
//using namespace std;
//template <class T>
//class CMyistream_iterator
//{
//	// 在此处补充你的代码
//private:
//	T n;//存值用的
//	istream&input;//使用引用，避免调用构造函数
//public:
//	CMyistream_iterator(istream&s):input(s) {
//		input >> n;
//	}
//	T operator*() {//因为存的是T类型的
//		return n;
//	}
//	void operator++(int) {//用int显示是后置++
//		input >> n;
//	}
//};
//
////需要重载单目运算符和++后移号
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		CMyistream_iterator<int> inputInt(cin);
//		int n1, n2, n3;
//		n1 = *inputInt; //读入 n1
//		int tmp = *inputInt;
//		cout << tmp << endl;
//		inputInt++;
//		n2 = *inputInt; //读入 n2
//		inputInt++;
//		n3 = *inputInt; //读入 n3
//		cout << n1 << " " << n2 << " " << n3 << " ";
//		CMyistream_iterator<string> inputStr(cin);
//		string s1, s2;
//		s1 = *inputStr;
//		inputStr++;
//		s2 = *inputStr;
//		cout << s1 << " " << s2 << endl;
//	}
//	return 0;
//}