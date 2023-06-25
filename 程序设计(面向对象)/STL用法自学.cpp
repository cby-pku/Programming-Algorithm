////#include<iostream>
////#include<stdio.h>
////#include<algorithm>
////#include<vector>
////#include<cmath>
////using namespace std;
////int main() {
////	//迭代器的使用
////	vector<int>v;
////	for (int n = 0; n < 5; ++n) {
////		v.push_back(n);
////	}
////	vector<int>::iterator i;
////	for (i = v.begin(); i != v.end(); i++) {
////		cout << *i << " ";
////		*i *= 2;
////	}
////	cout << endl;
////	vector<int>::reverse_iterator j;
////	for (j = v.rbegin(); j != v.rend(); j++) {
////		cout << *j << " ";
////	}
////}
////使用list解决约瑟夫问题
//#include<iostream>
//#include<list>
//using namespace std;
//int main() {
//	list<int>monkeys;
//	int n, m;
//	while (true) {
//		cin >> n >> m;
//		if (n == 0 && m == 0)break;
//		monkeys.clear();
//		for (int i = 1; i <= n; i++) {
//			monkeys.push_back(i);
//		}
//		list<int>::iterator it = monkeys.begin();
//		while (monkeys.size() > 1) {//不只一只猴子
//			for (int i = 1; i < m; i++)
//			{
//				it++; if (it == monkeys.end()) {//这返回 是最后一个元素的后一个元素
//					it = monkeys.begin();
//				}
//			}
//			it = monkeys.erase(it);
//			if (it == monkeys.end()) {
//				it = monkeys.begin()	;
//			}
//
//		}
//		cout << monkeys.front();
//	}
//}