////#define  _CRT_SECURE_NO_WARNINGS
//#include<iostream>
//#include<stdio.h>
//#include<string>
//using namespace std;
//const int WARRIOR_NUM = 5;
///*
//static Warrior::names[WARRIOR_NUM]={"dragon","ninja","iceman","lion","wolf"};
//红方司令部按照iceman、lion、wolf、ninja、dragon的顺序循环制造武士。
//2.3.4.1.0
//蓝方司令部按照lion、dragon、ninja、iceman、wolf的顺序循环制造武士
//3.0.1.2.4
//*/
//class Headquarter;
//class Warrior {
//private:
//	Headquarter*pHeadquarter;//首先要指向对应的司令部
//	int kindNo;//有自己的种类编号
//	int no;//该兵种对应的数目
//public:
//	static string weapons[3];
//	static string names[WARRIOR_NUM];//共享一个总的数组
//	static int initialLifeValue[WARRIOR_NUM];//初始化生产所需生命元
//	Warrior(Headquarter*p, int no_, int kindno_);
//	void PrintResult(int nTime);
//	void PrintWeapon(int no_, int nkindNo);
//};
//class Headquarter {
//private:
//	int totalLifeValue;
//	bool stopped;
//	int color; int totalWarrirNum;//要输出司令部内部的总的士兵数目
//	int curMakingSeqIdx;//当前制造的武士是第几个
//	int warriorNum[WARRIOR_NUM];//存放各兵种数目
//	Warrior*pWarriors[1000];//创建了几个成员的对象
//public:
//	friend class Warrior;//声明友元类可以访问
//	static int makingSeq[2][WARRIOR_NUM];//武士的制作顺序
//	void Init(int color_, int lv);
//	~Headquarter();
//	int Produce(int nTime);
//	string GetColor();
//
//};
//Warrior::Warrior(Headquarter*p, int no_, int kindno_) {
//	pHeadquarter = p;
//	no = no_;
//	kindNo = kindno_;
//}
//void Warrior::PrintWeapon(int no_, int nkindNo) {
//	int tmp = 0;
//	if (nkindNo == 0) {//dragon
//		//剩余的生命元
//		tmp = pHeadquarter->totalLifeValue;
//		double morale = 1.0*tmp / initialLifeValue[nkindNo];
//		printf("It has a %s,and it's morale is %.2lf\n"
//			, weapons[no_ % 3].c_str(), morale);
//	}
//	else if (nkindNo == 1) {//ninja
//		printf("It has a %s and a %s\n"
//			, weapons[no_ % 3].c_str(), weapons[(no_ + 1) % 3].c_str());
//	}
//	else if (nkindNo == 2) {//iceman
//		printf("It has a %s\n", weapons[no_ % 3].c_str());
//	}
//	else if (nkindNo == 3) {//lion
//		tmp = pHeadquarter->totalLifeValue;
//		printf("It's loyalty is %d\n", tmp);
//	}return;
//}
//void Warrior::PrintResult(int nTime) {//打印前已经减掉 
//	//首先获取司令部颜色
//	string color = pHeadquarter->GetColor();
//	printf("%03d %s %s %d born with strength %d,%d %s in %s headquarter\n",
//		nTime, color.c_str(), names[kindNo].c_str(), no + 1, initialLifeValue[kindNo],
//		pHeadquarter->warriorNum[kindNo], names[kindNo].c_str(), color.c_str());
//	//所以关键在于kindNo的获取
//	PrintWeapon(no + 1, kindNo);//传入的编号要加1
//}
//void Headquarter::Init(int color_, int lv) {
//	color = color_;
//	totalLifeValue = lv; totalWarrirNum = 0;
//	stopped = false; curMakingSeqIdx = 0;
//	for (int i = 0; i < WARRIOR_NUM; i++) {
//		warriorNum[i] = 0;
//	}
//}
//Headquarter::~Headquarter() {
//	for (int i = 0; i < totalWarrirNum; i++) {
//		delete pWarriors[i];//现用现生产
//	}
//}
//int Headquarter::Produce(int nTime) {
//	if (stopped) {
//		return 0;
//	}
//	int searchingTimes = 0;
//	while (Warrior::initialLifeValue[makingSeq[color][curMakingSeqIdx]] > totalLifeValue&&searchingTimes < WARRIOR_NUM) {//如何往下找，大于且不到5
//		curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
//		searchingTimes++;
//	}
//	int kindNo = makingSeq[color][curMakingSeqIdx];
//	if (Warrior::initialLifeValue[kindNo] > totalLifeValue) {
//		stopped = true;
//		if (color == 0) {
//			printf("%03d red headquarter stops making warriors\n", nTime);
//		}
//		else {
//			printf("%03d blue headquarter stops making warriors\n", nTime);
//		}
//		return 0;
//	}
//	totalLifeValue -= Warrior::initialLifeValue[kindNo];
//	curMakingSeqIdx = (curMakingSeqIdx + 1) % WARRIOR_NUM;
//	pWarriors[totalWarrirNum] = new Warrior(this, totalWarrirNum, kindNo);
//	warriorNum[kindNo]++;
//	pWarriors[totalWarrirNum]->PrintResult(nTime);
//	totalWarrirNum++;
//	return 1;
//}
//string Headquarter::GetColor() {
//	if (color == 0) {//0是红方
//		return"red";
//	}
//	return "blue";
//}
//string Warrior::weapons[3] = { "sword","bomb","arrow" };
//int Warrior::initialLifeValue[WARRIOR_NUM];//在全局声明一下
//int Headquarter::makingSeq[2][WARRIOR_NUM] = { {2,3,4,1,0},{3,0,1,2,4} };
//string Warrior::names[WARRIOR_NUM] = { "dragon","ninja","iceman","lion","wolf" };
//int main() {
//	int t, m;
//	Headquarter RedHead, BlueHead;
//	scanf("%d", &t);
//	int nCaseNo = 1;
//	while (t--) {
//		printf("Case:%d\n", nCaseNo++);
//		scanf("%d", &m);
//		for (int i = 0; i < WARRIOR_NUM; i++) {
//			scanf("%d", &Warrior::initialLifeValue[i]);
//		}
//		RedHead.Init(0, m);
//		BlueHead.Init(1, m);
//		int nTime = 0;
//		while (true) {
//			int tmp1 = RedHead.Produce(nTime);
//			int tmp2 = BlueHead.Produce(nTime);
//			if (tmp1 == 0 && tmp2 == 0) {
//				break;
//			}
//			nTime++;
//		}
//	}return 0;
//}