//#include<iostream>
//#include<string>
//#include<stdio.h>
//#include<iomanip>
//using namespace std;
//
//class Model {
//private:
//	int m; int flag = 0;//�ж��Ƿ����
//	int rednum = 0; //��ʿ����Ŀ
//	int bluenum = 0;
//	int total = 1;
//	int tmpred = 0; int tmpblue = 0;//��ʵ�����װ�ĺõĻ��������Ի��ɵ�һtmp����Ҫ��ָ��ָ����ͬ���ַ�����
//	int warriorsnum[5] = { 0,0,0,0,0 };//���Ե�ʿ����Ŀ
//	int redstrengh[5] = { 0,0,0,0,0 };//dragon,ninja,iceman,lion,wolf
//	int bluestrengh[5] = { 0,0,0,0,0 };
//	const string red_warriors[5] = { "iceman","lion","wolf","ninja","dragon" };
//	const string blue_warriors[5] = { "lion","dragon","ninja","iceman","wolf" };
//public:
//	static int redstop;
//	static int bluestop;
//	static int stop;//����ȫ��ѭ���ǵó�ʼ����һ��Ϊ2��������
//	Model(int mo,int s1,int s2,int s3,int s4,int s5){//���캯��
//		m = mo;//����Ԫ
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
//				flag = 1;//˵�����Դ�ӡ
//				//rednum�ں����Ĳ����У�ʵ��++
//				break;//������ԣ�ֱ���˳���ʼ��ӡ
//			}
//			else {
//				rednum++;//������ܣ���+1������
//			}
//		}
//		if (ii == 5 && flag == 0) {//����һȦ�޹�
//			//������
//			cout << "red headquarter stops making warriors" << endl;
//			stop++; redstop++;
//			return;
//		}
//		if (flag) {//flagΪ1,��һֱ��ӡ���ҵ��Ϳ���������
//			cout << "red " << red_warriors[tmpred] << " ";
//			cout << total << " " << "born with strength " << redstrengh[tmpred];
//			warriorsnum[tmpred]++;
//			cout << "," << warriorsnum[tmpred] << " " << red_warriors[tmpred] << " in red headquarter" << endl;
//			rednum++; total++;//��ʿ��
//			m -= redstrengh[tmpred];//ʵ������ֵ����
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
//		if (flag) {//�����߼�����ʵ�����㰴˳�������
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
//int Model::redstop = 0;//��ֹ��ͬcase�����ŵ���
//int Model::bluestop = 0;
//int main() {
//	int N;
//	int&a = Model::stop;
//	int&ared = Model::redstop;
//	int &ablue = Model::bluestop;//����һ��
//
//	cin >> N;
//	for(int t=1;t<=N;t++) {
//		a = 0; ared = 0; ablue = 0;//��ʼ��һ��
//		int mo, s1, s2, s3, s4, s5;
//		cin >> mo >> s1 >> s2 >> s3 >> s4 >> s5;
//		cout << "Case:" << t << endl;
//		Model red(mo, s1, s2, s3, s4, s5);
//		Model blue(mo, s1, s2, s3, s4, s5);//��δ�ö����ָ�����֣�����������ֱ�ӽ�������
//		for (int n = 0; a < 2; n++) {
//			if (!ared) {
//				cout << setfill('0') << setw(3) << n << " ";//��cout��һ������
//				red.redprint();
//			}
//			if (!ablue) {
//				cout << setfill('0') << setw(3) << n << " ";//��cout��һ������
//				blue.blueprint();
//			}
//			a = Model::stop;//�ٽ��и�ֵ
//			ared = Model::redstop;
//			ablue = Model::bluestop;
//		}
//	}
//	return 0;
//
//}
