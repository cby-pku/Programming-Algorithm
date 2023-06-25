//#include<iostream>
//#include<string>
//#include<cstdio>
//#include<cstring>
//#include<sstream>
//#include<cstdlib>
//#include<vector>
//using namespace std;
//class Student {
//private:
//	string name, age, number, grade[4];
//	string all; string s1, s2;
//	double ans;
//public:
//	void input() {
//		//cin >> all;
//		getline(cin, all);//带空格的字符串读入
//		int n = all.size();
//		int flag = 0;
//		int i=0;
//		for (i = 0; i<n; i++) {
//			if (all[i] == ',') {
//				flag++;
//			}
//			if(flag==3)
//			{
//				break;
//			}
//		}
//		//cout << all << endl;
//		//cout << flag << endl;
//		s1 = all.substr(0, i);//这是前面的输出子串
//		s2 = all.substr(i+1, n - i);//获取第i+1位及以后的n-i个字符
//		for (int j = 0; j < n - i; j++) {
//			if (s2[j] == ',') {
//				s2[j] = ' ';
//			}
//		}
//		//cout << s2 << endl;
//		istringstream is(s2);//利用空格分割
//		for (int k = 0; k < 4; k++) {
//			is >> grade[k];
//			//cout << grade[k] << endl;
//		}
//	}
//	void calculate() {
//		stringstream ss[4];
//		int tmp = 0;
//		ans = 0.0;
//		for (int i = 0; i < 4; i++) {
//			ss[i] << grade[i];//本质也是类中的变量，不像cout，cin
//			ss[i] >> tmp;
//			//cout << tmp;
//			ans += tmp;
//		}
//		ans = ans / 4;
//	}
//	void output() {
//		cout << s1 <<','<< ans;
//	}
//};
//int main() {
//	Student student;
//	student.input();
//	student.calculate();
//	student.output();
//}
////////学习到类的基本用法；按行读入字符串，字符串裁剪substr；string和int间快速转化
////
////#include <iostream>
////#include <cstring>
////#include <cstdlib>
////using namespace std;
////class Complex {
////private:
////	double r, i;
////public:
////	void Print() {
////		cout << r << "+" << i << "i" << endl;
////	}
////	// 在此处补充你的代码
////	Complex&operator=(const char *s){
////		r = s[0]-'0'; i = s[2]-'0';
////		return*this;
////	}//运算符重载
////};
////int main() {
////	Complex a;
////	a = "3+4i"; a.Print();
////	a = "5+6i"; a.Print();
////	return 0;
////}
////#include<iostream>
////using namespace std;
////int main() {
////	int m = 0, a = 0, b = 0, c = 0, d = 0, n = 0;
////	(m = a == b) || (n = c == d);
////	cout << m << endl << n;
////}