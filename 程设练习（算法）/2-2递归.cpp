////////4147：汉诺塔
//////#include<iostream>
//////#include<stdio.h>
//////using namespace std;
//////void move(int n, char s, char m, char e) {
//////	if (n == 1) {
//////		cout << "1:" << s << "->" << e << endl; return;
//////	}
//////	move(n - 1, s, e, m);
//////	cout << n << ':' << s << "->" << e << endl;//追踪当下移动的盘肯定是最后一个盘，即使是在move（n-1）也是用的最后一个盘
//////	//拆信封的栈理解方式，便能确定用n可以追踪到
//////	move(n - 1, m, s, e);
//////}
//////int main() {
//////	int n; char s, m, e;
//////	cin >> n >> s >> m >> e;
//////	move(n, s, m, e);
//////
//////}
/////*
//////8皇后排序问题2698+2754，其实循环的时候就是按大小循环，无所谓
////#include<iostream>
////#include<cmath>
////#include<memory.h>
////using namespace std;
////int N; int num; int b;
////int queenPos[100];
////int chessMap[8][8];
//////8皇后问题输出棋盘形式；其实可以对该函数动手脚，否则直接用棋盘做就要用回溯
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
////		//输出第b个串
////		//if (num == b) {
////		//	for ( i = 0; i < N; i++) {
////		//		cout << queenPos[i] + 1<<' ';
////		//	}cout << endl;
////		//}
////
////		//输出所有棋盘
////		cout << "No. " << num << endl;
////		printmap();
////		return;
////	}
////	for ( i = 0; i < N; i++) {
////		int j;
////		for (j = 0; j < k; j++) {
////			//和已摆好的k个皇后进行比较
////			//第k行摆在第i列
////			if (queenPos[j] == i || abs(queenPos[j] - i) == abs(k - j)) {//对角线和前面的行列
////				break;
////			}
////		}
////		if (j == k) {
////			queenPos[k] = i;
////			NQueen(k + 1);//为什么不用回溯？，因为对于每个i，都实现了改变queenPos，不像八皇后棋盘有些不会被改变
////		}
////	}
////}
////using namespace std;
////int main(){
////	//n皇后问题
////	//cin >> N;NQueen(0)
////	N = 8; num = 0;
////
////	//8皇后排序问题输出顺序
////	//int n;
////	//cin >> n;
////	//for (int i = 0; i < n; i++) {
////	//	num = 0;//每次开始前都要把指标归0
////	//	cin >> b;
////	//	NQueen(0);
////	//}
////
////	//8皇后棋盘输出
////	NQueen(0);
////
////}
//////它和棋盘形式可以互相更改
////*/
////
////////2694:波兰表达式
////////问题本身的定义就是递归的
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
//////表达式的值
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
//////用cin.peek()前瞻，用cin.get()进行操作后的字符删除
////int factor_value()//读入因子
////{
////	int result = 0;
////	char c = cin.peek();
////	if (c == '(') {
////		cin.get();
////		result = expression_value();
////		cin.get();//把有括号再扔掉
////	}
////	else {
////		while (isdigit(c)) {//这可以直接调用？,先读到的最高位
////			result = 10 * result + c - '0';
////			cin.get();//把c拿掉
////			c = cin.peek();//看看下一个是不是数字字符
////		}
////	}
////	return result;
////}
////
////int term_value()//读入项
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
////int expression_value()//读入表达式
////{
////	int result = term_value();//读取第一项的值
////	bool more = true;
////	while (more) {
////		char op = cin.peek();//看一个字符不取走
////		if (op == '+' || op == '-') {
////			cin.get();
////			int value = term_value();
////			if (op == '+')result += value;
////			else {
////				result -= value;
////			}
////		}
////		else {
////			more = false;//一直读取直到没有加减号
////		}
////	}
////	return result;
////}
////*/
////
////////走楼梯
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
////////1664;放苹果
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
//////应该提升自我要求，自己多刷一点题
//////2787：算24
////#include<iostream>
////#include<cmath>
////using namespace std;
////double a[5];
////#define EPS 1e-6//更适合于定义小数
////bool isZero(double x) {
////	return fabs(x) <= EPS;
////}
////bool count24(double a[], int n) {
////	//用a里的n个数计算
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
////求集合的幂集
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
//		mi(i + 1, reans);//不添加新字符
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