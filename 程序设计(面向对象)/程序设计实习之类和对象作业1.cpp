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
//		getline(cin, all);//���ո���ַ�������
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
//		s1 = all.substr(0, i);//����ǰ�������Ӵ�
//		s2 = all.substr(i+1, n - i);//��ȡ��i+1λ���Ժ��n-i���ַ�
//		for (int j = 0; j < n - i; j++) {
//			if (s2[j] == ',') {
//				s2[j] = ' ';
//			}
//		}
//		//cout << s2 << endl;
//		istringstream is(s2);//���ÿո�ָ�
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
//			ss[i] << grade[i];//����Ҳ�����еı���������cout��cin
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
////////ѧϰ����Ļ����÷������ж����ַ������ַ����ü�substr��string��int�����ת��
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
////	// �ڴ˴�������Ĵ���
////	Complex&operator=(const char *s){
////		r = s[0]-'0'; i = s[2]-'0';
////		return*this;
////	}//���������
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