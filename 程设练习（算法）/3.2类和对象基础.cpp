////类的成员函数和类的定义分开写
///*
//class CRectangle {
//public:
//	int w, h;
//	int Area();
//	int Perimeter();
//	void init(int w_, int h_);
//};
//
//int CRectangle::Area()//双引号代表是成员函数而并非全局函数
//{
//	return w*h;
//}
//
//int CRectangle::Perimeter()
//{
//	return 2*(w+h);
//}
//
//void CRectangle::init(int w_, int h_)
//{
//	w = w_; h = h_;
//}
//*/
//
////构造函数
///*
//class Complex {
//private:
//	double real, imag;
//public:
//	Complex(double r, double i = 0);
//};
//
//Complex::Complex(double r, double i)
//{
//	real = r; imag = i;
//}
//
//Complex c1;//要提供构造函数的基本参数，否则会出错
//Complex *pc = new Complex(3,4);//缺少基本参数也会出错
//Complex c2(2);//ok
//
//*/
//
//
////构造函数的重载
//class Complex {
//private:
//	double real, imag;
//public:
//	void Set(double r, double i);
//	Complex(double r, double i);
//	Complex(double r);
//	Complex(Complex c1, Complex c2);
//};
//
//void Complex::Set(double r, double i)
//{
//	real = r; imag = i;
//}
//
//Complex::Complex(double r, double i)
//{
//	real = r; imag = i;
//}
//
//Complex::Complex(double r)
//{
//	real = r; imag = 0;
//}
//
//Complex::Complex(Complex c1, Complex c2)
//{
//	real = c1.real + c2.real;
//	imag = c1.imag + c2.imag;
//}
//Complex c1(3), c2(1, 0), c3(c1, c2);
////c1{3,0},c2{1,0},c3{4,0}
//
////复制构造函数
//class Complex1 {
//private:
//	double real, imag;
//
//};
//Complex1 c11;//调用缺省无参构造函数
//Complex1 c2(c11);//调用缺省的复制构造函数，将c2初始化
//
////自主定义复制构造函数
//#include<iostream>
//using namespace std;
//class Complex2 {
//public:
//	double real, imag;
//	Complex2() {}
//	Complex2(const Complex2 &c) {
//		real = c.real;
//		imag = c.imag;
//		cout << "copy" << endl;
//	}
//};
//Complex2 c111;
//Complex2 c222(c111)