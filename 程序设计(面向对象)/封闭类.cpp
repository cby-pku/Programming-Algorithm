//4.1��ɸ�ϰ

////#include <iostream>
////using namespace std;
////class Apple {
////public:
////	static int nTotalNumber;
////	// �ڴ˴�������Ĵ���
////
////	Apple() {
////		nTotalNumber++;//��ʼ��������ʱ���г�ʼ��
////	}
////	~Apple() {//�ж�����������Ҫ�Զ�����
////		nTotalNumber--;
////	}
////	static void PrintTotal() {
////		cout << nTotalNumber << endl;
////	}
////};
////int Apple::nTotalNumber = 0;
////Apple Fun(const Apple & a) {//����һ������������apple����ı���
////	a.PrintTotal();//Ĭ�ϳ�ʼΪ4
////	//cout << 1 << endl;
////	return a;
////}
////int main()
////{
////	Apple * p = new Apple[4];
////	Fun(p[2]);
////	Apple p1, p2;
////	Apple::PrintTotal();
////	delete[] p;//�����������������ƹ��캯������ʱ��������
////	p1.PrintTotal();//���Ҳ�������������
////	return 0;
////}
//////����4�Σ�����һ�θ��ƹ��죬����-1������������+2��Ϊ5������ָ�����4��������������Ϊ1���������ȫ�ֱ���
////
////B������ʲô�ź���
//#include <iostream>
//using namespace std;
//class A {
//public:
//	int val;
//	A() {
//		val = 123;
//	}
//	A(A&n) {//���Զ��帴�ƹ��캯��
//		val = n.val;
//	}
//	A &GetObj() {//����ֵΪ��ַ����
//		//ָ���Լ���ע�ⷵ�ص���һ����ʱ����
//		return *this;
//	}
//	A(int n) {//ʵ��m�ĸ�ֵ
//		val = n;
//	}
//};
//int main()
//{
//	int m, n;
//	A a;
//	cout << a.val << endl;
//	while (cin >> m >> n) {
//		a.GetObj() = m;//Ҳ���������͹���ת��ΪA�Ķ���
//		cout << a.val << endl;
//		a.GetObj() = A(n);//������һ��A��Ķ���
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
////	Base b;//��ʵ��ᷢ�ַ���಻����дħ�޵�ʱ��Ҳ�õ����������ʵ�ܼ򵥣�����һ��С�࣬����Ҫ�ǵó�ʼ��
////	// �ڴ˴�������Ĵ���
////	Big(int n) : b(n),v(n) {
////	}
////	Big(const Big& a):v(a.v),b(a.v) {//ͬʱҪ���г�ʼ��
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
//////D����ֵ��ิ��
////#include <iostream>
////using namespace std;
////class Sample {
////public:
////	int v;
////	// �ڴ˴�������Ĵ���
////	Sample(int n) {//����d�ĳ�ʼ��
////		v = n;
////	}
////	Sample(){}//����a�ĳ�ʼ��
////	Sample(const Sample&a) {//����b �ĳ�ʼ��
////		v = a.v + 2;//���������θ��ƹ��캯��
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
////	PrintAndDouble(b);//���������θ��ƹ��캯��
////	Sample c = 20;
////	PrintAndDouble(c);//��cΪ�����ʱ����Ĭ��������ʱ����Ȼ�������һ��
////	Sample d;
////	d = a;
////	cout << d.v;
////	return 0;
////}