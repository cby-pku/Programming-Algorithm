//#include<iostream>
//#include<string>
//#include<sstream>
//#include<iomanip>
//#include<cmath>
//#include<algorithm>
//using namespace std;
//
////全局变量的定义
////static Warrior::names[WARRIOR_NUM]={"dragon","ninja","iceman","lion","wolf"};
//const string weapon[3] = { "sword","bomb","arrow" };
//int BlueOrder[5] = { 4,1,2,3,5 };
//int RedOrder[5] = { 3,4,5,2,1 };
//int initial_life[6];//1-5存放士兵初始生命值
//int AttackForce[6];
//int Hour = 0;
//int LionLoyaltyDecrease;
//bool MainFlag = 1;//司令部还健在
//
////输出小时
//void ShowHour() {
//	cout << setw(3) << setfill('0') << Hour;
//}
//class WeaponList {
//public:
//	int SumWeapon;
//	int WeaponNum[3];//各个武器数目
//	int UsedArrow;//储存用过的弓箭个数
//	WeaponList() :SumWeapon(0), UsedArrow(0) {
//		for (int i = 0; i < 3; i++)
//			WeaponNum[i] = 0;
//	}
//	WeaponList(int w1) :SumWeapon(1), UsedArrow(0) {
//		for (int i = 0; i < 3; i++)
//			WeaponNum[i] = 0;
//		WeaponNum[w1]++;
//	}
//	WeaponList(int w1,int w2) :SumWeapon(2), UsedArrow(0) {
//		for (int i = 0; i < 3; i++)
//			WeaponNum[i] = 0;
//		WeaponNum[w1]++;
//		WeaponNum[w2]++;
//	}
//};
//class Warrior {
//public:
//	string name;
//	string head;
//	int Number;//编号从1开始
//	int Life;
//	int Attack;
//	bool hasMoved;
//	WeaponList weapons;
//	Warrior(string name_, string head_, int no, 
//		int l, int a, int w1, int w2) :name(name_), head(head_),
//		Number(no), Life(l), Attack(a), weapons(w1, w2) {};//使用于有两件武器的ninja
//	Warrior(string name_, string head_, int no, 
//		int l, int a, int w1) :name(name_), head(head_),
//		Number(no), Life(l), Attack(a), weapons(w1) {};//使用于有一件武器的iceman、dragon、lion
//	Warrior(string name_, string head_, int no, 
//		int l, int a) :weapons(),name(name_), head(head_),//武器记得初始化
//		Number(no), Life(l), Attack(a),hasMoved(0){};//使用于没有武器的狼
//	virtual bool Lion_escape() {
//		return 0;
//	}
//	virtual void Lion_move(){}
//};
//class Dragon :public Warrior {
//public:
//	Dragon(string name_, string head_,
//		int no, int l, int a, int w1) :Warrior(name_, head_, no, l, a, w1) {};
//};
//class Iceman :public Warrior {
//public:
//	Iceman(string name_, string head_,
//		int no, int l, int a, int w1) :Warrior(name_, head_, no, l, a, w1) {};
//};
//class Lion :public Warrior {
//public:
//	int Loyalty;
//	Lion(string name_, string head_, 
//		int no, int l, int a, int w1,int n) :Warrior(name_, head_, no, l, a, w1),Loyalty(n) {};
//	bool Lion_escape() {//这应该是覆盖
//		if (Loyalty > 0)return 0;
//		ShowHour();
//		cout << ":05 " << head << " lion " << Number << " ran away" << endl;
//		return 1;
//	}
//	void Lion_move() {
//		Loyalty -= LionLoyaltyDecrease;
//	}
//
//};
//class Ninja :public Warrior {
//public:
//	Ninja(string name_, string head_, int no, int l, int a, int w1, int w2) :Warrior(name_, head_, no, l, a, w1, w2) {};
//};
//class Wolf :public Warrior {
//public:
//	Wolf(string name_, string head_, int no, int l, int a) :Warrior(name_,head_, no, l, a) {};
//};
//struct City {
//	Warrior*redWarrior;
//	Warrior*blueWarrior;
//	Warrior*tmpRed;
//	Warrior*tmpBlue;
//	string city_name;
//	bool isHead;
//};
//class Headquarter {
//public:
//	string HeadName;
//	int LifeTotal;
//	int SumWarrior;
//	int scanner;
//	int scan_order[5];
//	bool pro_abl;
//	Headquarter(string s, int l, int *order) :scanner(-1), LifeTotal(l), pro_abl(1), SumWarrior(0), HeadName(s) {
//		for (int i = 0; i < 5; i++) {
//			scan_order[i] = order[i];
//		}
//	}
//};
//
//void Produce(Warrior* &ptr, Headquarter&headquarter) {//需要重复使用，故传入引用
//	if (!headquarter.pro_abl){
//		cout << "Error!" << endl;
//		return;}
//	headquarter.scanner++;
//	if (headquarter.LifeTotal < initial_life[headquarter.scan_order[headquarter.scanner % 5]]) {
//		//永久停止生产
//		headquarter.pro_abl = 0;
//		return;
//	}
//	int result = headquarter.scan_order[headquarter.scanner % 5];//产生的武士编码，1对应阿巴巴
//	++headquarter.SumWarrior;//即为生产序号
//	headquarter.LifeTotal -= initial_life[result];
//	//用Switch打印，并且产生对应的ptr指针
//	ShowHour();
//	cout << ":00 " << headquarter.HeadName << " ";
//	switch (result)
//	{
//	case 1: {
//		ptr = new Dragon("dragon", headquarter.HeadName, headquarter.SumWarrior, 
//			initial_life[1], AttackForce[1], headquarter.SumWarrior % 3);
//		cout << "dragon " << headquarter.SumWarrior << " born" << endl;
//		break; }
//	case 2:
//	{
//	ptr = new Ninja("ninja", headquarter.HeadName, headquarter.SumWarrior, initial_life[2], AttackForce[2],
//		headquarter.SumWarrior % 3, (headquarter.SumWarrior + 1) % 3);
//	cout << "ninja " << headquarter.SumWarrior << " born" << endl;
//	break;
//	}
//	case 3:
//	{
//		
//		ptr = new Iceman("iceman", headquarter.HeadName, headquarter.SumWarrior, initial_life[3], AttackForce[3],
//			headquarter.SumWarrior % 3);
//		cout << "iceman " << headquarter.SumWarrior << " born" << endl;
//		break;
//	}
//	case 4: {
//		
//		ptr = new Lion("lion", headquarter.HeadName, headquarter.SumWarrior, initial_life[4], AttackForce[4],
//			headquarter.SumWarrior % 3, headquarter.LifeTotal);
//		cout << "lion " << headquarter.SumWarrior << " born" << endl;
//		cout << "Its loyalty is " << headquarter.LifeTotal << endl;
//		break;
//	}
//	case 5: {
//		ptr = new Wolf("wolf", headquarter.HeadName, headquarter.SumWarrior, initial_life[5], AttackForce[5]);
//		cout << "wolf " << headquarter.SumWarrior << " born" << endl;
//		break;
//	}
//	default:
//		break;
//	}
//}
//
//void warrior_move(City*destination, City*left, City*right) {
//	if (left->redWarrior) {
//		if (left->redWarrior->name == "iceman")left->redWarrior->Life -= (left->redWarrior->Life) / 10;
//		if (left->redWarrior->name == "lion")left->redWarrior->Lion_move();
//		ShowHour();
//		if (!(destination->isHead)) {
//			cout << ":10 red " << left->redWarrior->name << " " << left->redWarrior->Number << " marched to city " << destination->city_name;
//			cout << " with " << left->redWarrior->Life << " elements and force " << left->redWarrior->Attack << endl;
//		}
//		else if (destination->isHead) {
//			cout << ":10 red " << left->redWarrior->name << " " << left->redWarrior->Number << " reached blue headquarter ";
//			cout << "with " << left->redWarrior->Life << " elements and force " << left->redWarrior->Attack << endl;
//			ShowHour();
//			cout << ":10 blue headquarter was taken" << endl;
//			MainFlag = 0;
//		}
//		destination->tmpRed = left->redWarrior;
//		left->redWarrior = NULL;
//
//	}
//	if (right->blueWarrior) {
//		if (right->blueWarrior->name == "iceman")right->blueWarrior->Life -= (right->blueWarrior->Life) / 10;
//		if (right->blueWarrior->name == "lion")right->blueWarrior->Lion_move();
//		ShowHour();
//		if (!(destination->isHead)) {
//			cout << ":10 blue " << right->blueWarrior->name << " " << right->blueWarrior->Number << " marched to city " << destination->city_name;
//			cout << " with " << right->blueWarrior->Life << " elements and force " << right->blueWarrior->Attack << endl;
//		}
//		else if (destination->isHead) {
//			cout << ":10 blue " << right->blueWarrior->name << " " << right->blueWarrior->Number << " reached red headquarter ";
//			cout << "with " << right->blueWarrior->Life << " elements and force " <<right->blueWarrior->Attack << endl;
//			ShowHour();
//			cout << ":10 red headquarter was taken" << endl;
//			MainFlag = 0;
//		}
//		destination->tmpBlue = right->blueWarrior;
//		right->blueWarrior = NULL;
//
//	}
//}
//
//void all_warrior_move(City*cityarray, int start, int end) {
//	for (int i = start; i <= end; i++) {
//		warrior_move(&cityarray[i], &cityarray[i - 1], &cityarray[i + 1]);
//	}
//}
//
//void warriorPlace(City*destination) {
//	if (destination->tmpBlue) {
//		destination->blueWarrior = destination->tmpBlue;
//		destination->tmpBlue = NULL;
//	}
//	if (destination->tmpRed) {
//		destination->redWarrior = destination->tmpRed;
//		destination->tmpRed = NULL;//全部城市移动完再移动，否则会相互影响
//	}
//}
//void rob(City*city) {
//	if (city->redWarrior->name == "wolf"&&city->blueWarrior->name == "wolf")return;
//	if (city->blueWarrior->name != "wolf"&&city->redWarrior->name != "wolf")return;
//	if (city->redWarrior->name == "wolf") {
//		if (city->redWarrior->weapons.SumWeapon == 10 || city->blueWarrior->weapons.SumWeapon == 0)return;
//		int i_ = 0;
//		for (i_ = 0; i_ < 3; i_++) {
//			if (city->blueWarrior->weapons.WeaponNum[i_] > 0)break;
//		}
//		int robnum = min(10 - city->redWarrior->weapons.SumWeapon, city->blueWarrior->weapons.WeaponNum[i_]);
//		if (i_ == 2) {
//			if (robnum > city->blueWarrior->weapons.WeaponNum[i_] - city->blueWarrior->weapons.UsedArrow) {
//				int exchange = robnum - city->blueWarrior->weapons.WeaponNum[i_] +city->blueWarrior->weapons.UsedArrow;
//				city->blueWarrior->weapons.UsedArrow -= exchange;
//				city->redWarrior->weapons.UsedArrow += exchange;
//			}
//		}
//		city->redWarrior->weapons.SumWeapon += robnum;
//		city->redWarrior->weapons.WeaponNum[i_] += robnum;
//		city->blueWarrior->weapons.WeaponNum[i_] -= robnum;
//		city->blueWarrior->weapons.SumWeapon -= robnum;
//		ShowHour();
//		cout << ":35 red wolf " << city->redWarrior->Number << " took " << robnum <<" "<< weapon[i_] << " from blue " << city->blueWarrior->name;
//		cout << " " << city->blueWarrior->Number << " in city " << city->city_name << endl;
//	}
//	else if (city->blueWarrior->name == "wolf") {
//		if (city->blueWarrior->weapons.SumWeapon == 10 || city->redWarrior->weapons.SumWeapon == 0)return;
//		int i_ = 0;
//		for (i_ = 0; i_ < 3; i_++) {
//			if (city->redWarrior->weapons.WeaponNum[i_] > 0)break;
//		}
//		int robnum = min(10 - city->blueWarrior->weapons.SumWeapon, city->redWarrior->weapons.WeaponNum[i_]);
//		if (i_ == 2) {
//			if (robnum > city->redWarrior->weapons.WeaponNum[i_] - city->redWarrior->weapons.UsedArrow) {
//				int exchange = robnum - city->redWarrior->weapons.WeaponNum[i_] + city->redWarrior->weapons.UsedArrow;
//				city->redWarrior->weapons.UsedArrow -= exchange;
//				city->blueWarrior->weapons.UsedArrow += exchange;
//			}
//		}
//		city->redWarrior->weapons.SumWeapon -= robnum;
//		city->redWarrior->weapons.WeaponNum[i_] -= robnum;
//		city->blueWarrior->weapons.WeaponNum[i_] += robnum;
//		city->blueWarrior->weapons.SumWeapon += robnum;
//		ShowHour();
//		cout << ":35 blue wolf " << city->blueWarrior->Number << " took " << robnum <<" "<< weapon[i_] << " from red " << city->redWarrior->name;
//		cout << " " << city->redWarrior->Number << " in city " << city->city_name << endl;
//	}
//}
//
//void OneTimeAttack(Warrior* &attacker, Warrior* &another, int weap)//直接传引用然后赋成指针，便于直接删改
//{
//	switch (weap)
//	{
//	case 0: {
//		another->Life -= (attacker->Attack) / 5;
//		break;
//	}
//	case 1:
//	{
//		another->Life -= (attacker->Attack) * 2 / 5;
//		if(attacker->name!="ninja")attacker->Life -= (attacker->Attack) / 5;
//		attacker->weapons.SumWeapon--;
//		attacker->weapons.WeaponNum[1]--;
//		break;
//	}
//	case 2: {
//		another->Life -= (attacker->Attack) * 3 / 10;
//		if (attacker->weapons.UsedArrow > 0) {
//			attacker->weapons.UsedArrow--;
//			attacker->weapons.SumWeapon--;
//			attacker->weapons.WeaponNum[2]--;
//		}
//		else {
//			attacker->weapons.UsedArrow++;
//		}
//	}
//	default:
//		break;
//	}
//}
//
////战后打扫战场捕获武器
//void capture(Warrior*attacker, Warrior*another) {
//	int addw0 = min(10 - attacker->weapons.SumWeapon, another->weapons.WeaponNum[0]);
//	attacker->weapons.SumWeapon += addw0;
//	attacker->weapons.WeaponNum[0] += addw0;
//	int addw1 = min(10 - attacker->weapons.SumWeapon, another->weapons.WeaponNum[1]);
//	attacker->weapons.SumWeapon += addw1;
//	attacker->weapons.WeaponNum[1] += addw1;	
//	int addw2 = min(10 - attacker->weapons.SumWeapon, another->weapons.WeaponNum[2]);
//	attacker->weapons.SumWeapon += addw2;
//	attacker->weapons.WeaponNum[2] += addw2;
//	if (addw2 > another->weapons.WeaponNum[2] - another->weapons.UsedArrow) {
//		attacker->weapons.UsedArrow += addw2 - another->weapons.WeaponNum[2] + another->weapons.UsedArrow;
//	}
//
//}
//
////判断胜负和平局
//bool attackResult(City*city) {
//	if (city->redWarrior->Life <= 0 && city->blueWarrior->Life <= 0) {
//		ShowHour();
//		cout << ":40 both red " << city->redWarrior->name << " " << city->redWarrior->Number << " and blue ";
//		cout << city->blueWarrior->name << " " << city->blueWarrior->Number << " died in city " << city->city_name << endl;
//		delete city->redWarrior;
//		city->redWarrior = NULL;
//		delete city->blueWarrior;//删除指针指向空间的内容
//		city->blueWarrior = NULL;
//		//指针复位空
//		return 1;
//	}
//	if (city->blueWarrior->Life <= 0) {
//		capture(city->redWarrior, city->blueWarrior);
//		ShowHour();
//		cout << ":40 red " << city->redWarrior->name << " " << city->redWarrior->Number << " killed blue " << city->blueWarrior->name;
//		cout << " " << city->blueWarrior->Number << " in city " << city->city_name << " remaining " << city->redWarrior->Life << " elements" << endl;
//		delete city->blueWarrior;
//		city->blueWarrior = NULL;
//		if (city->redWarrior->name == "dragon") {
//			ShowHour();
//			cout << ":40 red dragon " << city->redWarrior->Number << " yelled in city " << city->city_name<<endl;
//		}
//		return 1;
//	}
//	else if (city->redWarrior->Life <= 0) {
//		capture(city->blueWarrior, city->redWarrior);
//		ShowHour();
//		cout << ":40 blue " << city->blueWarrior->name << " " << city->blueWarrior->Number << " killed red " << city->redWarrior->name;
//		cout << " " << city->redWarrior->Number << " in city " << city->city_name << " remaining " << city->blueWarrior->Life << " elements" << endl;
//		delete city->redWarrior;
//		city->redWarrior = NULL;
//		if (city->blueWarrior->name == "dragon") {
//			ShowHour();
//			cout << ":40 blue dragon " << city->blueWarrior->Number << " yelled in city " << city->city_name<<endl;
//		}
//		return 1;
//	}
//	return 0;
//}
//
////battle in the city
//void Battling(City*city, int city_num) {
//	if (!(city->blueWarrior&&city->redWarrior))return;//没有两个战士，则返回
//	bool temp_flag = 0;//判断终止条件
//	int redlife = city->redWarrior->Life, redweap = city->redWarrior->weapons.SumWeapon, redArrow = city->redWarrior->weapons.UsedArrow;
//	int bluelife = city->blueWarrior->Life, blueweap = city->blueWarrior->weapons.SumWeapon, blueArrow = city->blueWarrior->weapons.UsedArrow;
//	int i_red = -1, i_blue = -1;//weapon
//	if (city_num % 2 == 1) {
//		if (city->redWarrior->weapons.SumWeapon) {
//			for (int i = 1; i <= 3; i++) {
//				i_red++;
//				if (city->redWarrior->weapons.WeaponNum[i_red % 3])break;
//			}
//			OneTimeAttack(city->redWarrior, city->blueWarrior, i_red % 3);//用什么武器
//			if (attackResult(city))return;//分出胜负，直接返回
//		}
//	}
//	int tie_counter = 0;
//	while (!temp_flag) {
//		redlife = city->redWarrior->Life, redweap = city->redWarrior->weapons.SumWeapon, redArrow = city->redWarrior->weapons.UsedArrow;
//		bluelife = city->blueWarrior->Life, blueweap = city->blueWarrior->weapons.SumWeapon, blueArrow = city->blueWarrior->weapons.UsedArrow;
//		if (city->blueWarrior->weapons.SumWeapon) {
//			for (int i = 1; i <= 3; i++) {
//				i_blue++;
//				if (city->blueWarrior->weapons.WeaponNum[i_blue % 3])break;
//			}
//			OneTimeAttack(city->blueWarrior, city->redWarrior, i_blue % 3);
//			if (attackResult(city))return;
//		}
//		if (city->redWarrior->weapons.SumWeapon) {
//			for (int i = 1; i <= 3; i++) {
//				i_red++;
//				if (city->redWarrior->weapons.WeaponNum[i_red % 3])break;
//			}
//			OneTimeAttack(city->redWarrior, city->blueWarrior, i_red % 3);//用什么武器
//			if (attackResult(city))return;//分出胜负，直接返回
//		}
//		if (redlife == city->redWarrior->Life&&redweap == city->redWarrior->weapons.SumWeapon&&redArrow == city->redWarrior->weapons.UsedArrow&&
//			bluelife == city->blueWarrior->Life&&blueweap == city->blueWarrior->weapons.SumWeapon&&blueArrow == city->blueWarrior->weapons.UsedArrow) {
//			tie_counter++;
//		}
//		else { tie_counter = 0; }
//		if (tie_counter >= 3) {
//			temp_flag = 1;
//			break;
//		}
//	}
//	if (temp_flag) {
//		ShowHour();
//		cout << ":40 both red " << city->redWarrior->name << " " << city->redWarrior->Number << " and blue ";
//		cout << city->blueWarrior->name << " " << city->blueWarrior->Number << " were alive in city " << city->city_name << endl;
//		if (city->redWarrior->name == "dragon") {
//			ShowHour();
//			cout << ":40 red dragon " << city->redWarrior->Number << " yelled in city " << city->city_name << endl;
//		}
//		if (city->blueWarrior->name == "dragon") {
//			ShowHour();
//			cout << ":40 blue dragon " << city->blueWarrior->Number << " yelled in city " << city->city_name << endl;
//		}
//	}
//}
////headquarter announce
//void headAnnounce(Headquarter &red, Headquarter&blue) {
//	ShowHour();
//	cout << ":50 " << red.LifeTotal << " elements in red headquarter" << endl;
//	ShowHour();
//	cout << ":50 " << blue.LifeTotal << " elements in blue headquarter" << endl;
//}
//
//void warriorAnnounce(City*city) {
//	if (city->redWarrior) {
//		ShowHour();
//		cout << ":55 red " << city->redWarrior->name << " " << city->redWarrior->Number << " has " << city->redWarrior->weapons.WeaponNum[0] << " sword "
//			<< city->redWarrior->weapons.WeaponNum[1] << " bomb " << city->redWarrior->weapons.WeaponNum[2] << " arrow and " << city->redWarrior->Life << " elements" << endl;
//	}
//	if (city->blueWarrior) {
//		ShowHour();
//		cout << ":55 blue " << city->blueWarrior->name << " " << city->blueWarrior->Number << " has " << city->blueWarrior->weapons.WeaponNum[0] << " sword "
//			<< city->blueWarrior->weapons.WeaponNum[1] << " bomb " << city->blueWarrior->weapons.WeaponNum[2] << " arrow and " << city->blueWarrior->Life << " elements" << endl;
//	}
//}
//
//string n_to_s(int n) {
//	string res;
//	stringstream ss;
//	ss << n;
//	ss >> res;
//	return res;
//}
//
//int main() {
//	int testNum;
//	cin >> testNum;
//	for (int cas = 1; cas <= testNum; ++cas) {
//		Hour=0;
//		MainFlag = 1;
//		int totalLife, cityNum, terminal;
//		cin >> totalLife >> cityNum >> LionLoyaltyDecrease >> terminal;
//		for (int i = 1; i <= 5; i++)cin >> initial_life[i];
//		for (int i = 1; i <= 5; i++)cin >> AttackForce[i];
//		Headquarter red("red", totalLife, RedOrder), blue("blue", totalLife, BlueOrder);
//		City*cities = new City[cityNum + 4];
//		for (int i = 0; i < cityNum + 4; i++) {
//			cities[i].redWarrior = NULL;
//			cities[i].blueWarrior = NULL;
//			cities[i].tmpBlue = NULL;
//			cities[i].tmpRed = NULL;
//			cities[i].city_name = n_to_s(i - 1);
//			cities[i].isHead = 0;
//		}
//		cities[1].isHead = 1;
//		cities[cityNum + 2].isHead = 1;
//
//		cout << "Case " << cas << ":" << endl;
//		while ((Hour) * 60 <= terminal) {
//			if (red.pro_abl)Produce(cities[1].redWarrior, red);
//			if (blue.pro_abl)Produce(cities[cityNum + 2].blueWarrior,blue);
//			if ((Hour) * 60 + 5 <= terminal) {//加入条件判断，从而超时的时候全部跳出
//				for (int i = 2; i <= cityNum + 1; ++i) {
//					if (cities[i].redWarrior&&cities[i].redWarrior->Lion_escape()) {
//						delete cities[i].redWarrior;
//						cities[i].redWarrior = NULL;
//					}
//					if (cities[i].blueWarrior&&cities[i].blueWarrior->Lion_escape()) {
//						delete cities[i].blueWarrior;
//						cities[i].blueWarrior = NULL;
//					}
//				}
//			}
//			if ((Hour) * 60 + 10 <= terminal) {
//				all_warrior_move(cities, 1, cityNum + 2);
//				for (int i = 1; i <= cityNum + 2; ++i) {
//					warriorPlace(&cities[i]);
//				}
//				if (!MainFlag)break;//有占领直接跳出，不用循环到最后
//			}
//			if ((Hour) * 60 + 35 <= terminal) {
//				for (int i = 1; i <= cityNum + 2; ++i) {
//					if (cities[i].redWarrior&&cities[i].blueWarrior) {
//						rob(&cities[i]);
//					}
//				}
//			}
//			if ((Hour) * 60 + 40 <= terminal) {
//				for(int i=2;i<=cityNum+1;++i)
//				Battling(&cities[i], i - 1);
//			}
//			if ((Hour) * 60 + 50 <= terminal) {
//				headAnnounce(red, blue);
//			}
//			if ((Hour) * 60 + 55 <= terminal) {
//				for (int i = 1; i <= cityNum + 2; ++i) {
//					warriorAnnounce(&cities[i]);
//				}
//			}
//			Hour++;
//		}
//
//
//	}return 0;
//}