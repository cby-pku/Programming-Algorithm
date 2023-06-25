//4.1完成复习

//BC其实是一样的，用异或实现翻转
////第i位翻转
//#include<iostream>
//using namespace std;
//int bitManipulation2(int n, int i) {
//	return n ^ (1 << i);//异或实现位翻转
//
//}
//int main() {
//	int t, n, i;
//	cin >> t;
//	while (t--) {
//		cin >> n >> i;
//		cout << bitManipulation2(n, i) << endl;
//	}return 0;
//}

////左边i位翻转
//#include<iostream>
//using namespace std;
//int bitManipulation3(int n, int i) {
//	return n ^ ((1 << 31)>>(i-1));//异或实现位翻转
//
//}
//int main() {
//	int t, n, i;
//	cin >> t;
//	while (t--) {
//		cin >> n >> i;
//		cout << bitManipulation3(n, i) << endl;
//	}return 0;
//}


////第i位替换（A）
//#include<iostream>
//using namespace std;
//int bitManipulation1(int n, int m, int i) {
//	if ((m >> i) & 1) { return n |= (1 << i); }return n &= ~(1 << i);
//}
//int main() {
//	int n, m, i, t;
//	cin >> t;
//	while (t--) {
//		cin >> n >> m >> i;
//		cout << bitManipulation1(n, m, i) << endl;
//	}
//	return 0;
//}
/*
void swap(int &a, int &b) {
	int tmp;
	tmp = a; a = b; b = tmp;
}
int n1, n2;
swap(n1,n2);*/