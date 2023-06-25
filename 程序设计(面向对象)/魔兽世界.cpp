//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<iomanip>
//using namespace std;
//
//class Model {
//private:
//	int m; int flag = 0;//判断是否结束
//	int rednum = 0; //总士兵数目
//	int bluenum = 0;
//	int total = 1;
//	int tmpred = 0; int tmpblue = 0;//其实如果封装的好的话，都可以换成单一tmp；但要加指针指代不同的字符数组
//	int warriorsnum[5] = { 0,0,0,0,0 };//各自的士兵数目
//	int redstrengh[5] = { 0,0,0,0,0 };//dragon,ninja,iceman,lion,wolf
//	int bluestrengh[5] = { 0,0,0,0,0 };
//	const string red_warriors[5] = { "iceman","lion","wolf","ninja","dragon" };
//	const string blue_warriors[5] = { "lion","dragon","ninja","iceman","wolf" };
//public:
//	static int redstop;
//	static int bluestop;
//	static int stop;//放入全局循环记得初始化，一旦为2，则跳出
//	Model(int mo,int s1,int s2,int s3,int s4,int s5){//构造函数
//		m = mo;//生命元
//		redstrengh[0] = s3; bluestrengh[0] = s4;
//		redstrengh[1] = s4; bluestrengh[1] = s1;
//		redstrengh[2] = s5; bluestrengh[2] = s2;
//		redstrengh[3] = s2; bluestrengh[3] = s3;
//		redstrengh[4] = s1; bluestrengh[4] = s5;
//
//	}
//public:
//	void redprint() {
//		//
//		int ii = 0;
//		for ( ii = 0; ii < 5; ii++) {
//			tmpred = rednum %5 ;
//			if (m - redstrengh[tmpred] >= 0) {
//				flag = 1;//说明可以打印
//				//rednum在后续的操作中，实现++
//				break;//如果可以，直接退出开始打印
//			}
//			else {
//				rednum++;//如果不能，则+1再试试
//			}
//		}
//		if (ii == 5 && flag == 0) {//找了一圈无果
//			//结束吧
//			cout << "red headquarter stops making warriors" << endl;
//			stop++; redstop++;
//			return;
//		}
//		if (flag) {//flag为1,则一直打印，找到就可以跳出来
//			cout << "red " << red_warriors[tmpred] << " ";
//			cout << total << " " << "born with strength " << redstrengh[tmpred];
//			warriorsnum[tmpred]++;
//			cout << "," << warriorsnum[tmpred] << " " << red_warriors[tmpred] << " in red headquarter" << endl;
//			rednum++; total++;//总士兵
//			m -= redstrengh[tmpred];//实现生命值减少
//			flag = 0;
//			return;
//		}
//	}
//	void blueprint() {
//		int ir = 0;
//		for (ir = 0; ir < 5; ir++) {
//			tmpblue = bluenum % 5;
//			if (m - bluestrengh[tmpblue] >= 0) {
//				flag = 1;
//				break;
//			}
//			else {
//				bluenum++;
//			}
//		}
//		if (ir == 5 && flag == 0) {
//			cout << "blue headquarter stops making warriors" << endl;
//			 stop++; bluestop++;
//			return;
//		}
//		if (flag) {//这在逻辑上其实是满足按顺序制造的
//			cout << "blue " << blue_warriors[tmpblue] << " ";
//			cout << total << " " << "born with strength " << bluestrengh[tmpblue];
//			warriorsnum[tmpblue]++;
//			cout << "," << warriorsnum[tmpblue] << " " << blue_warriors[tmpblue] << " in blue headquarter" << endl;
//			bluenum++; total++;
//			m -= bluestrengh[tmpblue];
//			flag = 0;
//			return;
//		}
//	}
//};
//int Model::stop = 0;
//int Model::redstop = 0;//防止不同case间最后才调用
//int Model::bluestop = 0;
//int main() {
//	int N;
//	int&a = Model::stop;
//	int&ared = Model::redstop;
//	int &ablue = Model::bluestop;//引用一下
//
//	cin >> N;
//	for(int t=1;t<=N;t++) {
//		a = 0; ared = 0; ablue = 0;//初始化一下
//		int mo, s1, s2, s3, s4, s5;
//		cin >> mo >> s1 >> s2 >> s3 >> s4 >> s5;
//		cout << "Case:" << t << endl;
//		Model red(mo, s1, s2, s3, s4, s5);
//		Model blue(mo, s1, s2, s3, s4, s5);//并未用额外的指针区分，而是在类内直接进行区分
//		for (int n = 0; a < 2; n++) {
//			if (!ared) {
//				cout << setfill('0') << setw(3) << n << " ";//用cout调一下数据
//				red.redprint();
//			}
//			if (!ablue) {
//				cout << setfill('0') << setw(3) << n << " ";//用cout调一下数据
//				blue.blueprint();
//			}
//			a = Model::stop;//再进行赋值
//			ared = Model::redstop;
//			ablue = Model::bluestop;
//		}
//	}
//	return 0;
//
//}
