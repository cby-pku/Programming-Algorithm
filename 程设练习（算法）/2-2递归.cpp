////////4147����ŵ��
//////#include<iostream>
//////#include<stdio.h>
//////using namespace std;
//////void move(int n, char s, char m, char e) {
//////	if (n == 1) {
//////		cout << "1:" << s << "->" << e << endl; return;
//////	}
//////	move(n - 1, s, e, m);
//////	cout << n << ':' << s << "->" << e << endl;//׷�ٵ����ƶ����̿϶������һ���̣���ʹ����move��n-1��Ҳ���õ����һ����
//////	//���ŷ��ջ��ⷽʽ������ȷ����n����׷�ٵ�
//////	move(n - 1, m, s, e);
//////}
//////int main() {
//////	int n; char s, m, e;
//////	cin >> n >> s >> m >> e;
//////	move(n, s, m, e);
//////
//////}
/////*
//////8�ʺ���������2698+2754����ʵѭ����ʱ����ǰ���Сѭ��������ν
////#include<iostream>
////#include<cmath>
////#include<memory.h>
////using namespace std;
////int N; int num; int b;
////int queenPos[100];
////int chessMap[8][8];
//////8�ʺ��������������ʽ����ʵ���ԶԸú������ֽţ�����ֱ������������Ҫ�û���
////void printmap() {
////	memset(chessMap, 0, sizeof(chessMap));
////	for (int i = 0; i < N; i++) {
////		chessMap[i][ queenPos[i]] = 1;
////	}
////	for (int i = 0; i < N; i++) {
////		for (int j = 0; j < N; j++) {
////			cout << chessMap[i][j]<<' ';
////		}
////		cout << endl;
////	}
////	return;
////}
////void NQueen(int k) {
////	int i;
////	if (k == N) {
////		num++;
////
////		//�����b����
////		//if (num == b) {
////		//	for ( i = 0; i < N; i++) {
////		//		cout << queenPos[i] + 1<<' ';
////		//	}cout << endl;
////		//}
////
////		//�����������
////		cout << "No. " << num << endl;
////		printmap();
////		return;
////	}
////	for ( i = 0; i < N; i++) {
////		int j;
////		for (j = 0; j < k; j++) {
////			//���Ѱںõ�k���ʺ���бȽ�
////			//��k�а��ڵ�i��
////			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) {//�Խ��ߺ�ǰ�������
////				break;
////			}
////		}
////		if (j == k) {
////			queenPos[k] = i;
////			NQueen(k + 1);//Ϊʲô���û��ݣ�����Ϊ����ÿ��i����ʵ���˸ı�queenPos������˻ʺ�������Щ���ᱻ�ı�
////		}
////	}
////}
////using namespace std;
////int main(){
////	//n�ʺ�����
////	//cin >> N;NQueen(0)
////	N = 8; num = 0;
////
////	//8�ʺ������������˳��
////	//int n;
////	//cin >> n;
////	//for (int i = 0; i < n; i++) {
////	//	num = 0;//ÿ�ο�ʼǰ��Ҫ��ָ���0
////	//	cin >> b;
////	//	NQueen(0);
////	//}
////
////	//8�ʺ��������
////	NQueen(0);
////
////}
//////����������ʽ���Ի������
////*/
////
////////2694:�������ʽ
////////���Ȿ��Ķ�����ǵݹ��
//////#include<iostream>
//////#include<cstring>
//////#include<stdio.h>
//////using namespace std;
//////double exp() {
//////	char s[20];
//////	cin >> s;
//////	switch (s[0])
//////	{
//////	case '+':return exp() + exp();
//////	case '*':return exp()*exp();
//////	case '/':return exp() / exp();
//////	case '-':return exp() - exp();
//////	default:
//////		return atof(s); break;
//////	}
//////}
//////int main() {
//////	printf("%lf", exp());
//////	return 0;
//////}
////
/////*
//////���ʽ��ֵ
////#include<iostream>
////#include<stdio.h>
////#include<cstdlib>
////#include<cstring>
////using namespace std;
////int factor_value();
////int term_value();
////int expression_value();
////int main() {
////	cout << expression_value() << endl;
////	return 0;
////}
//////��cin.peek()ǰհ����cin.get()���в�������ַ�ɾ��
////int factor_value()//��������
////{
////	int result = 0;
////	char c = cin.peek();
////	if (c == '(') {
////		cin.get();
////		result = expression_value();
////		cin.get();//�����������ӵ�
////	}
////	else {
////		while (isdigit(c)) {//�����ֱ�ӵ��ã�,�ȶ��������λ
////			result = 10 * result + c - '0';
////			cin.get();//��c�õ�
////			c = cin.peek();//������һ���ǲ��������ַ�
////		}
////	}
////	return result;
////}
////
////int term_value()//������
////{
////	int result = factor_value();
////	while (true) {
////		char op = cin.peek();
////		if (op == '*' || op == '/') {
////			cin.get();
////			int value = factor_value();
////			if (op == '*') {
////				result *= value;
////			}
////			else {
////				result /= value;
////			}
////		}
////		else { break; }
////	}
////	return result;
////}
////
////int expression_value()//������ʽ
////{
////	int result = term_value();//��ȡ��һ���ֵ
////	bool more = true;
////	while (more) {
////		char op = cin.peek();//��һ���ַ���ȡ��
////		if (op == '+' || op == '-') {
////			cin.get();
////			int value = term_value();
////			if (op == '+')result += value;
////			else {
////				result -= value;
////			}
////		}
////		else {
////			more = false;//һֱ��ȡֱ��û�мӼ���
////		}
////	}
////	return result;
////}
////*/
////
////////��¥��
//////#include<iostream>
//////using namespace std;
//////int floor(int n) {
//////	if (n==1)return 1;
//////	if (n == 2)return 2;
//////	return floor(n - 1) + floor(n - 2);
//////
//////}
//////int main() {
//////	int n;
//////	cin >> n;
//////	cout << floor(n) << endl;
//////}
////
////////1664;��ƻ��
//////#include<iostream>
//////using namespace std;
//////
//////int f(int m, int n) {
//////	if (n > m)return f(m, m);
//////	if (m == 0)return 1;
//////	if (n == 0)return 0;
//////	return f(m, n - 1) + f(m - n, n);
//////}
//////int main() {
//////	int t, m, n;
//////	cin >> t;
//////	while (t--) {
//////		cin >> m >> n;
//////		cout << f(m, n) << endl;
//////	}return 0;
//////}
//////Ӧ����������Ҫ���Լ���ˢһ����
//////2787����24
////#include<iostream>
////#include<cmath>
////using namespace std;
////double a[5];
////#define EPS 1e-6//���ʺ��ڶ���С��
////bool isZero(double x) {
////	return fabs(x) <= EPS;
////}
////bool count24(double a[], int n) {
////	//��a���n��������
////	if (n == 1) {
////		if (isZero(a[0] - 24))
////			return true;
////		else
////			return false;
////	}
////	double b[5];
////	for (int i = 0; i < n - 1; i++) {
////		for (int j = i + 1; j < n; j++) {
////			int m = 0;
////			for (int k = 0; k < n; k++) {
////				if (k != i && k != j) {
////					b[m++] = a[k];
////				}
////			}
////			b[m] = a[i] + a[j];
////			if (count24(b, n - 1))
////				return true;
////			b[m] = a[i] - a[j];
////			if (count24(b, n - 1))
////				return true;
////			b[m] = a[j] - a[i];
////			if (count24(b, n - 1))
////				return true;
////			b[m] = a[i] * a[j];
////			if (count24(b, n - 1))
////				return true;
////			if (!isZero(a[i])) {
////				b[m] = a[j] / a[i];
////				if (count24(b, n - 1))
////					return true;
////			}
////			if (!isZero(a[j])) {
////				b[m] = a[i] / a[j];
////				if (count24(b, n - 1))
////					return true;
////			}
////		}
////	}
////	return false;
////}
////
////int main() {
////	while (cin >> a[0] >> a[1] >> a[2] >> a[3]) {
////		if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0)break;
////		if (count24(a, 4))
////		{
////			cout << "YES" << endl; continue;
////		}
////		cout << "NO" << endl; 
////	}
////}
//
////�󼯺ϵ��ݼ�
//#include<iostream>
//#include<cstring>
//char anslist[21] = { 0 };
//char arry[21];
//using namespace std;
//void mi(int i, char*anslist) {
//	char reans[21];
//	strcpy_s(reans, anslist);
//	if (i == strlen(arry)) {
//		cout << "(" << anslist << ')';
//		return;
//	}
//	else {
//		mi(i + 1, reans);//��������ַ�
//		strncat_s(reans, arry + i, 1);
//		mi(i + 1, reans);
//
//	}
//
//}
//int main() {
//	int n;
//	cin >> n;
//	cin >> arry;//benlaijiushi shuruzifushuzu
//	mi(0, anslist);
//	return 0;
//}