//////////1.����ȥ�����̬
////////
////////#include <iostream>
////////using namespace std;
////////class B {
////////private:
////////	int nBVal;
////////public:
////////	void Print()
////////	{
////////		cout << "nBVal=" << nBVal << endl;
////////	}
////////	void Fun()
////////	{
////////		cout << "B::Fun" << endl;
////////	}
////////	B(int n) { nBVal = n; }
////////};
////////// �ڴ˴�������Ĵ���
////////class D :public B {
////////private:
////////	int nDVal;
////////public:
////////	D(int n) :B(3*n) {
////////		nDVal =  n;
////////	};
////////	virtual void Print() {
////////		B::Print();
////////		cout << "nDVal=" <<nDVal<< endl;
////////	}
////////	virtual void Fun() {
////////		cout << "D::Fun" << endl;
////////	}
////////};
////////int main() {
////////	B * pb; D * pd;
////////	D d(4); d.Fun();
////////	pb = new B(2); pd = new D(8);
////////	pb->Fun(); pd->Fun();
////////	pb->Print(); pd->Print();
////////	pb = &d; pb->Fun();//���������D�ĵ�ַ����Ϊʲô��
////////	pb->Print();
////////	return 0;
////////}
//////
////////2.
//////#include <iostream>
//////using namespace std;
//////
//////int bitManipulation1(int n, int m, int i) {
//////	// �ڴ˴�������Ĵ���
//////	if ((m >> i) & 1)return n |= (1 << i); return n &= ~(1 << i);
//////}
//////
//////int main() {
//////	int n, m, i, t;
//////	cin >> t;
//////	while (t--) {
//////		cin >> n >> m >> i;
//////		cout << bitManipulation1(n, m, i) << endl;
//////	}
//////	return 0;
//////}
////
////#include <iostream> 
////using namespace std;
////class A
////{
////public:
////	A() { }
////	// �ڴ˴�������Ĵ���
////	virtual ~A() {
////		
////		cout << "destructor A" << endl; }
////};
////class B :public A {
////public:
////	~B() { cout << "destructor B" << endl; }
////};
////int main()
////{
////	A * pa;
////	pa = new B;
////	delete pa;
////	return 0;
////}
//
//#include <iostream>
//using namespace std;
//class A {
//private:
//	int nVal;
//public:
//	void Fun()
//	{
//		cout << "A::Fun" << endl;
//	};
//	virtual void Do()
//	{
//		cout << "A::Do" << endl;
//	}
//};
//class B :public A {
//public:
//	virtual void Do()
//	{
//		cout << "B::Do" << endl;
//	}
//};
//class C :public B {
//public:
//	void Do()
//	{
//		cout << "C::Do" << endl;
//	}
//	void Fun()
//	{
//		cout << "C::Fun" << endl;
//	}
//};
//void Call(A*p
//	// �ڴ˴�������Ĵ���
//) {
//	p->Fun(); p->Do();
//}
//int main() {
//	Call(new A());
//	Call(new C());
//	return 0;
//}