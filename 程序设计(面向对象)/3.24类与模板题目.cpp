////////////////A
//////////////#include <iostream>
//////////////#include <string>
//////////////using namespace std;
//////////////template <class T>
//////////////T SumArray(T*a,T*b){
//////////////	T sum = *a;//��Ϊ�������һ��ָ�룬�Ƚ����õõ���Ӧ���ڴ�����
//////////////	for (T*i = a+1; i < b; i++) {
//////////////		sum += *i;
//////////////	}
//////////////	return sum;
//////////////	// �ڴ˴�������Ĵ���
//////////////	
//////////////}
//////////////int main() {
//////////////	string array[4] = { "Tom","Jack","Mary","John" };
//////////////	cout << SumArray(array, array + 4) << endl;
//////////////	int a[4] = { 1, 2, 3, 4 };  //��ʾ��1+2+3+4 = 10
//////////////	cout << SumArray(a, a + 4) << endl;
//////////////	return 0;//�������൱��һ��ָ��
//////////////}
////////////
//////////////B��
////////////#include <iostream>
////////////#include <string>
////////////using namespace std;
////////////// �ڴ˴�������Ĵ���
////////////template<class T,class T1>//�������ڲ�����Ҫ�����µ�����ģ��
////////////void MyForeach(T*a,T*b,void func(T1 t)){//����ģ����к���������
////////////	for (T*i = a; i < b; i++) {//�������ָ�룬��ȻҪ�ö�Ӧ���͵�ָ�������г�ʼ��
////////////		func(*i);//��Ҫ�����ã�
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
////////////�򵥵�Filter
//////////#include <iostream>
//////////#include <string>
//////////using namespace std;
//////////// �ڴ˴�������Ĵ���
//////////template<class T,class T1>
////////////��ʵ��дģ�������return��c�Ķ��󼴿�
//////////T*Filter(T*a, T*b, T*n, T1*pt) {//��һ������ָ�룬��������Ϊ��֪�������ķ���������ʲô���������൱��֪���˺���һ����void�͵ģ���ֻ���β����Ͳ�һ��
//////////	for (T*i = a; i < b; i++) {
//////////		if (pt(*i)) {//������T1���������ĸ����µ����飬����������ָ��ĺ��ƣ����ڸ�ֵ������һ����ͬ���͵ģ����Կ��Զ���ͬһ��ģ����ʵ��
//////////			*n = *i;
//////////			++n;//ָ�����
//////////		}
//////////	}
//////////	return n;//����ָ��
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
////////	// �ڴ˴�������Ĵ���
////////private:
////////	bool bstop;
////////public:
////////	MyCin() {//һ����ܻ���Ҫ�ڹ��캯��������һ�£�������
////////		bstop = false;
////////	}
////////	 operator bool(){//����()��Ϊ������Mycin�������
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
////////F:���ģ�岢����
//////#include <iostream>
//////#include <string>
//////#include <cstring>
//////using namespace std;
//////template <class T>
//////class myclass {
//////	// �ڴ˴�������Ĵ���
//////private:
//////	int size;
//////	T*p;
//////public:
//////	myclass(const T*m, int n) : size(n) {
//////		p = new T[size + 1];
//////		for (int i = 0; i < size; i++) {
//////			p[i] = m[i];//�ø����������ʵ�ָ�ֵ
//////		}
//////	};
//////	~myclass() {//��ָ����Լ�дһ����������
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
////template <class T1, class T2>//����ָ��ͺ�������Ӧ��û�в��
////void mysort(T1*start, T1*end, T2* func) {//T1һ��Ϊint���Ͷ���int*������û����temp������
////	for (int i = 0; i < end - start; i++) {//��Ϊ����������������Կ϶���Ҫ��ָ�봫�룬����[]���Դ������õ�Ч�������������ǿ��Ե�
////		for (int j = 0; j < end - start; j++) {
////			if (func(start[i], start[j])) {
////				T1 temp = start[i];
////				start[i] = start[j];
////				start[j] = temp;
////			}//ʵ�ʾ���һ����������
////		}
////	}
////}
////	// �ڴ˴�������Ĵ���
////
////#define NUM 5
////int main()
////{
////	int an[NUM] = { 8,123,11,10,4 };
////	mysort(an, an + NUM, Greater1); //��С�������� 
////	for (int i = 0; i < NUM; i++)
////		cout << an[i] << ",";
////	mysort(an, an + NUM, Greater2); //�Ӵ�С���� 
////	cout << endl;
////	for (int i = 0; i < NUM; i++)
////		cout << an[i] << ",";
////	cout << endl;
////	double d[6] = { 1.4,1.8,3.2,1.2,3.1,2.1 };
////	mysort(d + 1, d + 5, Greater3); //��������±�1���±�4��С�������� 
////	for (int i = 0; i < 6; i++)
////		cout << d[i] << ",";
////	return 0;
////}
//
////E��ɽկ��istream_iterator
//#include <iostream>
//#include <string>
//
//using namespace std;
//template <class T>
//class CMyistream_iterator
//{
//	// �ڴ˴�������Ĵ���
//private:
//	T n;//��ֵ�õ�
//	istream&input;//ʹ�����ã�������ù��캯��
//public:
//	CMyistream_iterator(istream&s):input(s) {
//		input >> n;
//	}
//	T operator*() {//��Ϊ�����T���͵�
//		return n;
//	}
//	void operator++(int) {//��int��ʾ�Ǻ���++
//		input >> n;
//	}
//};
//
////��Ҫ���ص�Ŀ�������++���ƺ�
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--) {
//		CMyistream_iterator<int> inputInt(cin);
//		int n1, n2, n3;
//		n1 = *inputInt; //���� n1
//		int tmp = *inputInt;
//		cout << tmp << endl;
//		inputInt++;
//		n2 = *inputInt; //���� n2
//		inputInt++;
//		n3 = *inputInt; //���� n3
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