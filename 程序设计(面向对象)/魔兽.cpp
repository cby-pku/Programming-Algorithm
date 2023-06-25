#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
bool GameOver = false; int maxTime;
string Warrior_Name[5] = { "dragon","ninja","iceman","lion","wolf" };
string Weapon_Name[5] = { "sword","bomb","arrow" };
int Red_Order[5] = { 2,3,4,1,0 };
int Fear; int City_Num;
int Blue_Order[5] = { 3,0,1,2,4 };
int Warrior_Life[5] = { 0 };//初始生命值=生产消耗的生命元数
int Warrior_Force[5] = { 0 };//武士攻击力
int Arrow_Force;//初始输入R，作为弓箭的攻击力
int City_Hp[30] = { 0 };//存储城市的血量
string City_Flag[30] = { "NULL"};//储存城市旗帜
int tmpHash[2][30] = { {0} };
void Time(int T) {//打印时间
	printf("%03d:%02d ", T / 60, T % 60);
	return;
}
int BlueHeadHasRed = 0;
int RedHeadHasBlue = 0;

class Weapon {
public:
	int Weapon_Type;//武器的类型
	int Arrow_Used = 3;//箭的使用次数
	
	int Weapon_Force;//武器攻击值

	Weapon(int weapon_type, int warrior_type):Weapon_Type(weapon_type) {
		switch (weapon_type)
		{
		case 0:Weapon_Force=int(Warrior_Force[warrior_type] * 2 / 10);
			break;
		case 1:
			Weapon_Force = 0x7f7f7f7f;//炸弹给予单独判断
			break;
		case 2:
			Weapon_Force = Arrow_Force;
			break;
		}
	}
	void Sword_MoSun() {
		if (Weapon_Type == 0) {
			Weapon_Force = int(Weapon_Force * 8 / 10);

		}
	}
	void Report() {//报告武器情况
		switch (Weapon_Type)
		{
		case 0:
			printf("sword(%d)", Weapon_Force);
			break;
		case 1:
			cout << "bomb";
			break;
		case 2:
			printf("arrow(%d)", Arrow_Used);
			break;
		}
	}

	bool Weapon_Useless() {
		return (Arrow_Used == 0) || (Weapon_Force == 0);
	}
};

class Warrior{
public:
	int Type; int ID;//武士的类型和id
	int Hp, Pos;
	int iceman_force = Warrior_Force[2];//便于后期iceman_force变更的计算
	vector<Weapon> weapon;
	bool has_Marched = false;
	Warrior(int type, int id, int hp_) :Type(type), ID(id), Hp(hp_) {};
	int Sword() {
		for (int i = 0; i < weapon.size(); i++) {
			if (weapon[i].Weapon_Type == 0)return i;
		}
		return -1;
	}
	int Bomb() {
		for (int i = 0; i < weapon.size(); i++) {
			if (weapon[i].Weapon_Type == 1)return i;
		}
		return -1;
	}
	int Arrow() {
		for (int i = 0; i < weapon.size(); i++) {
			if (weapon[i].Weapon_Type == 2)return i;
		}
		return -1;
	}
	//定义供派生类使用的虚函数
	virtual void Print_Morale() {};
	virtual void Print_Loyalty() {};
	virtual bool Run_Away(int T, string flag) {
		return false;
	};
	virtual void Iceman_Plus() {};
	virtual void Dragon_Yell(int T,string flag,int City) {};
	virtual void Dragon_Win() {};
	virtual void Dragon_Loss() {};
	virtual void Lion_Not_Win() {};
	virtual void Lion_Is_Taken_HP(Warrior*p,int PreHp) {};//获取之前的hp值
	virtual void Wolf_Take_Weapon(Warrior*p) {};

	virtual void Hurted(int Force) {
		Hp -= Force;
	}
	friend void RshotB(Warrior*red, Warrior*blue , int T) {//红射蓝
		if (red->Pos == blue->Pos - 1) {
			for (int i = 0; i < red->weapon.size(); i++) {
				if (red->weapon[i].Weapon_Type == 2) {
					red->weapon[i].Arrow_Used--;
					blue->Hurted(red->weapon[i].Weapon_Force);
					if (red->weapon[i].Weapon_Useless()) {
						red->weapon.erase(red->weapon.begin() + i);
					}
					if (blue->Hp <= 0) {
						Time(T);
						printf("red %s %d shot and killed blue %s %d\n", Warrior_Name[red->Type].c_str(), red->ID, Warrior_Name[blue->Type].c_str(), blue->ID);
						return;
					}
					Time(T);
					printf("red %s %d shot\n", Warrior_Name[red->Type].c_str(), red->ID);
				}
			}
		}
	}
	friend void BshotR(Warrior*red, Warrior*blue, int T) {
		if (red->Pos == blue->Pos - 1) {
			for (int i = 0; i < blue->weapon.size(); i++) {
				if (blue->weapon[i].Weapon_Type == 2) {
					blue->weapon[i].Arrow_Used--;
					red->Hurted(blue->weapon[i].Weapon_Force);
					if (blue->weapon[i].Weapon_Useless()) {
						blue->weapon.erase(blue->weapon.begin() + i);
					}
					if (red->Hp <= 0) {
						Time(T);
						printf("blue %s %d shot and killed red %s %d\n", Warrior_Name[blue->Type].c_str(), blue->ID, Warrior_Name[red->Type].c_str(), red->ID);
						return;
					}
					Time(T);
					printf("blue %s %d shot\n", Warrior_Name[blue->Type].c_str(), blue->ID);
				}
			}
		}
	}
	int Myforce() {//获取我方的攻击力，同时得到iceman这个特殊情况
		if (Type != 2) {
			return Warrior_Force[Type];
		}
		else {
			return iceman_force;
		}

	}
	//定义sword的攻击，因为有耗损，所以单独检查
	virtual void Sword_Attack(Warrior*p, int city, string my_flag, string enemy_flag, int T, bool isPrint) {
		if (p->Hp <= 0)return;//p是敌人
		
		if (isPrint) {
			Time(T);
			printf("%s %s %d attacked %s %s %d in city %d with %d elements and force %d\n",
				my_flag.c_str(), Warrior_Name[Type].c_str(), ID, enemy_flag.c_str(), Warrior_Name[p->Type].c_str(),
				p->ID, city, Hp, Myforce());
		}
		int tmp = Sword();
		if (tmp != -1) {
			p->Hurted(Myforce() + weapon[tmp].Weapon_Force);
			if (tmp != -1) {
				weapon[tmp].Sword_MoSun();
				if (weapon[tmp].Weapon_Useless()) {
					weapon.erase(weapon.begin() + tmp);
				}
			}
		}
		else {
			p->Hurted(Myforce());
		}
		

		//如果敌方挂了
		if (p->Hp <= 0) {
			if (isPrint) {
				Time(T);
				printf("%s %s %d was killed in city %d\n",
					enemy_flag.c_str(), Warrior_Name[p->Type].c_str(), p->ID, city);
			}
			return;
		}
		//及时return，否则就会秽土转生反击我方（×）
		p->FightBack(this, city, enemy_flag, my_flag, T, isPrint);
		//如果我方挂了
		
		if (Hp <= 0) {
			if (isPrint) {
				Time(T);
				printf("%s %s %d was killed in city %d\n",
					my_flag.c_str(), Warrior_Name[Type].c_str(), ID, city);
			}
			return;
		}
	}
	virtual void FightBack(Warrior*p, int city, string my_col, string enemy_col, int T, bool isPrint) {
		//老实人ninja怎么会反击呢
		if (Type == 1)return;
		int tmp = Sword();
		if (tmp != -1) {
			p->Hurted(int(Myforce() / 2) + weapon[tmp].Weapon_Force);
		}
		else
			p->Hurted(int(Myforce() / 2));
		if (isPrint) {
			Time(T);
			printf("%s %s %d fought back against %s %s %d in city %d\n",
				my_col.c_str(), Warrior_Name[Type].c_str(), ID,
				enemy_col.c_str(), Warrior_Name[p->Type].c_str(), p->ID,city);
		}
		if (tmp != -1) {
			weapon[tmp].Sword_MoSun();
			if (weapon[tmp].Weapon_Useless()) {
				weapon.erase(weapon.begin() + tmp);
			}
		}
	}
	//汇报武器
	void ReportWeapon(int T, string flag) {
		Time(T);
		printf("%s %s %d has ",
			flag.c_str(), Warrior_Name[Type].c_str(), ID);
		if (weapon.empty()) {
			cout << "no weapon\n";
			return;
		}
		switch (weapon.size())
		{
		case 1:
		{
			weapon[0].Report(), cout << endl;
			break;
		}
		case 2:
		{
			//输出type大的，倒着汇报
			if (weapon[0].Weapon_Type > weapon[1].Weapon_Type) {
				weapon[0].Report(), cout << ",", weapon[1].Report(), cout << endl;
			}
			else {
				weapon[1].Report(), cout << ",", weapon[0].Report(), cout << endl;
			}
			break;
		}
		case 3:
		{
			for (int i = 2; i >= 0; i--) {
				for (int j = 0; j < 3; j++) {
					if (weapon[j].Weapon_Type == i) {
						weapon[j].Report();
						if (i != 0)cout << ",";
						else cout << endl;
					}
				}
			}
			break;
		}
		}
		return;
	}
	//打扫战场：yell、生命元获取、升旗、忠诚度、缴获武器、夺取生命元
	void Clean(Warrior*p, int city, int attack_first, int ismywin, string my_flag, string enemy_flag,
		int T, int &tmp_Hp_plus, int myPreHp) {
		//如果赢了，龙士气+0.8
		if (ismywin == 1) {
			this->Dragon_Win();
		}
		else {
			this->Dragon_Loss();//未能获胜减小0.2，士气增加发生在欢呼之前
		}
		if (ismywin != -1 && attack_first == 1)
			this->Dragon_Yell(T, my_flag, city);
		if (ismywin == 1) {
			tmp_Hp_plus += City_Hp[city];
			Time(T);
			printf("%s %s %d earned %d elements for his headquarter\n", my_flag.c_str(),
				Warrior_Name[Type].c_str(), ID, City_Hp[city]);
			City_Hp[city] = 0;
		}

		if (ismywin == 1 && City_Flag[city] != my_flag) {
			tmpHash[my_flag == "blue"][city]++;
			if (tmpHash[my_flag == "blue"][city] == 2) {
				City_Flag[city] = my_flag;
				tmpHash[my_flag == "blue"][city] = 0;
				//实现升旗
				Time(T);
				printf("%s flag raised in city %d\n", my_flag.c_str(), city);
			}
		}
		else {
			tmpHash[my_flag == "blue"][city] = 0;
		}
		if (ismywin != 1) {
			Lion_Not_Win();//降低忠诚度
		}
		if (ismywin == -1) {
			Lion_Is_Taken_HP(p, myPreHp);//输了还要献出生命元
		}
		if (ismywin == 1) {
			Wolf_Take_Weapon(p);
		}
	}

};
class Dragon :public Warrior {
	double dragon_morale;
public:
	Dragon(int id, int leftHp) :Warrior(0, id, Warrior_Life[0]) {
		weapon.push_back(Weapon(id % 3, 0));
		if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0) {
			weapon.clear();
		}
		dragon_morale = leftHp * 1.0 / Warrior_Life[0];
	}
	virtual void Print_Morale() {
		printf("Its morale is %.2lf\n", dragon_morale);
	};
	virtual void Dragon_Yell(int T, string flag, int city) {
		if (dragon_morale > 0.8) {
			Time(T);
			printf("%s dragon %d yelled in city %d\n", flag.c_str(), ID, city);
		}
	};
	virtual void Dragon_Win() {
		dragon_morale += 0.2;
	};
	virtual void Dragon_Loss() {
		dragon_morale -= 0.2;
	};

};
class Ninja :public Warrior {
public:
	Ninja(int id, int leftHp) :Warrior(1, id, Warrior_Life[1]) {
		weapon.push_back(Weapon(id % 3, 1));//判断降生时sword武器的自动销毁
		if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0) {
			weapon.clear();
		}
		weapon.push_back(Weapon((id + 1) % 3, 1));
		if (weapon.size() == 2) {
			if (weapon[1].Weapon_Type == 0 && weapon[1].Weapon_Force == 0)
				weapon.erase(weapon.begin() + 1);
		}
		if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0)
			weapon.erase(weapon.begin());//两件武器，什么耐久没了，清理什么
	}
};
class Iceman :public Warrior {
	bool OnePace = false;
public:
	Iceman(int id, int leftHp) :Warrior(2, id, Warrior_Life[2]) {
		weapon.push_back(Weapon(id % 3, 2));
		if (weapon[0].Weapon_Type == 0 && weapon[0].Weapon_Force == 0) {
			weapon.clear();
		}
	}
	virtual void Iceman_Plus() {
		if (OnePace) {
			OnePace = false;
			Hp -= 9;
			if (Hp <= 0) {
				Hp = 1;
			}
			iceman_force += 20;
		}
		else
			OnePace = true;
	};
};
class Lion :public Warrior {
public:
	int loyalty;
	Lion(int id, int leftHp) :Warrior(3, id, Warrior_Life[3]) {
		loyalty = leftHp;
	}
	virtual void Print_Loyalty() {
		printf("Its loyalty is %d\n", loyalty);
	};
	virtual void Lion_Not_Win() {
		loyalty -= Fear;
	};
	virtual void Lion_Is_Taken_HP(Warrior*p, int PreHp) {
		p->Hp += PreHp;
	};//获取之前的hp值
	virtual bool Run_Away(int T, string flag) {//狮子逃走
		if (loyalty <= 0) {
			Time(T);
			printf("%s lion %d ran away\n", flag.c_str(), ID);
			return true;
		}
		return false;
	};

};
class Wolf :public Warrior {
public:
	Wolf(int id, int leftHp) :Warrior(4, id, Warrior_Life[4]) {

	};
	virtual void Wolf_Take_Weapon(Warrior*p) {
		if (Sword() == -1) {
			if (p->Sword() != -1)
				weapon.push_back(p->weapon[p->Sword()]);
		}
		if (Bomb() == -1) {
			if (p->Bomb() != -1) {
				weapon.push_back(p->weapon[p->Bomb()]);
			}
		}
		if (Arrow() == -1) {
			if (p->Arrow() != -1) {
				weapon.push_back(p->weapon[p->Arrow()]);
			}
		}
	};
};


class Head {
public:
	int Head_Hp;//生命元
	bool is_Stopped = false;
	int Make_Order[5];//生产顺序
	int Total_Warrior_Num[6] = { 0 };//0,1,2,3,4,总数(指示id）
	string flag;//旗帜颜色
	int next_warrior = 0;//下一个生产武士
	vector<Warrior*>warrior;//存储武士类

	Head(int hp, int *order, string flag_) {
		Head_Hp=hp; flag = flag_;
		for (int i = 0; i <= 4; i++)
			Make_Order[i] = order[i];
	}
	//制造武士
	void Make_Warrior(int T) {
		if (Head_Hp >= Warrior_Life[Make_Order[next_warrior]]) {
			int tmp = Make_Order[next_warrior];//要生产的warrior_id
			Total_Warrior_Num[5]++;
			Total_Warrior_Num[tmp]++;
			Head_Hp -= Warrior_Life[tmp];
			
			Time(T);
			printf("%s %s %d born\n", flag.c_str(), Warrior_Name[tmp].c_str(), Total_Warrior_Num[5]);
			switch (tmp) {
			//补充武士的新增！！！
			case 0: {
				warrior.push_back(new Dragon(Total_Warrior_Num[5], Head_Hp));
				break;
			}
			case 1: {
				warrior.push_back(new Ninja(Total_Warrior_Num[5], Head_Hp));
				break;
			}
			case 2: {
				warrior.push_back(new Iceman(Total_Warrior_Num[5], Head_Hp));
				break;
			}
			case 3: {
				warrior.push_back(new Lion(Total_Warrior_Num[5], Head_Hp));
				break;
			}
			case 4: {
				warrior.push_back(new Wolf(Total_Warrior_Num[5], Head_Hp));
				break;
			}
			}
			//单独对蓝色阵营的location=cityNum'+1！！！
			if (flag == "blue")
				warrior.back()->Pos = City_Num + 1;
			//补充对龙和狮子报告士气和忠诚度的判断！！！
			warrior.back()->Print_Morale();
			warrior.back()->Print_Loyalty();
			next_warrior++;
			next_warrior %= 5;

		}
	}

	void Report(int T) {
		Time(T);
		printf("%d elements in %s headquarter\n", Head_Hp, flag.c_str());
		return;
	}
	//补充前进函数
	void March(int T, int pos) {
		if (flag == "red") {//这里可以改一下直接读flag
			for (int i = 0; i < warrior.size(); i++) {
				if (warrior[i]->Pos == pos - 1) {
					if (warrior[i]->has_Marched == false) {
						warrior[i]->Pos++;
						warrior[i]->has_Marched = true;
						warrior[i]->Iceman_Plus();
						Time(T);
						if (pos == City_Num + 1) {
							printf("red %s %d reached blue headquarter with %d elements and force %d\n",
								Warrior_Name[warrior[i]->Type].c_str(), warrior[i]->ID, warrior[i]->Hp, warrior[i]->Myforce());
							BlueHeadHasRed++;
							if (BlueHeadHasRed == 2) {
								Time(T);
								printf("blue headquarter was taken\n");
								GameOver = true;
							}
							return;
						}
						printf("red %s %d marched to city %d with %d elements and force %d\n",
							Warrior_Name[warrior[i]->Type].c_str(), warrior[i]->ID, pos,warrior[i]->Hp, warrior[i]->Myforce());


					}

				}
			}
		}
		else {
			for (int i = 0; i < warrior.size(); i++) {
				if (warrior[i]->Pos == pos + 1) {
					
						warrior[i]->Pos--;
						
						warrior[i]->Iceman_Plus();
						Time(T);
						if (pos == 0) {
							printf("blue %s %d reached red headquarter with %d elements and force %d\n",
								Warrior_Name[warrior[i]->Type].c_str(), warrior[i]->ID, warrior[i]->Hp, warrior[i]->Myforce());
							RedHeadHasBlue++;
							if (RedHeadHasBlue == 2) {
								Time(T);
								printf("red headquarter was taken\n");
								GameOver = true;
							}
							return;
						}
						printf("blue %s %d marched to city %d with %d elements and force %d\n",
							Warrior_Name[warrior[i]->Type].c_str(), warrior[i]->ID, pos,warrior[i]->Hp, warrior[i]->Myforce());
					}
				}
			
		}
	}

	//补充司令部获取生命元函数！！
	void Produce_Hp(int n, int i, int T, string flag) {
		if (n == 0) {
			return;
		}
		Head_Hp += n;
		Time(T);
		printf("%s %s %d earned %d elements for his headquarter\n", flag.c_str(),
			Warrior_Name[warrior[i]->Type].c_str(), warrior[i]->ID, n);
	}
};
void Init() {
	BlueHeadHasRed = 0;
	RedHeadHasBlue = 0;
	GameOver = false;
	memset(tmpHash, 0, sizeof(tmpHash));
	for (int i = 0; i < 30; i++) {
		City_Flag[i] = "NULL";
	}
	memset(City_Hp, 0, sizeof(City_Hp));
}
void Fight() {
	int Head_Hp;
	cin >> Head_Hp >> City_Num >> Arrow_Force >> Fear >> maxTime;
	for (int j = 0; j <= 4; j++) {
		cin >> Warrior_Life[j];
	}
	for (int j = 0; j <= 4; j++) {
		cin >> Warrior_Force[j];
	}

	Head RED(Head_Hp, Red_Order, "red");
	Head BLUE(Head_Hp, Blue_Order, "blue");
	for (int T = 0; T <= maxTime; T++) {
		int ti = T % 60;//这样才能循环到38min
		
		switch (ti) {
		case 0: {
			RED.Make_Warrior(T);
			BLUE.Make_Warrior(T);
			break;
		}
		case 5:
		{
			for (int i = 0; i <= City_Num + 1; i++) {
				for (int j = 0; j < RED.warrior.size(); j++) {
					if (i == City_Num + 1)continue;
					if (RED.warrior[j]->Pos == i) {
						if (RED.warrior[j]->Run_Away(T, "red"))
							RED.warrior.erase(RED.warrior.begin() + j);
					}
				}
				for (int j = 0; j < BLUE.warrior.size(); j++) {
					if (i == 0)continue;//在敌方司令部
					if (BLUE.warrior[j]->Pos == i) {
						if (BLUE.warrior[j]->Run_Away(T, "blue"))
							BLUE.warrior.erase(BLUE.warrior.begin() + j);
					}
				}
			}
			break;
		}
		case 10: {
			for (int i = 0; i <= City_Num + 1; i++) {
				RED.March(T, i);
				BLUE.March(T, i);
			}
			for (int i = 0; i < RED.warrior.size(); i++) {
				RED.warrior[i]->has_Marched = false;
			}
			if (GameOver)return;//这个逻辑可能要改一下
			break;
		}
		case 20:
		{
			for (int i = 1; i <= City_Num; i++) {
				City_Hp[i] += 10;

			}
			break;
		}
		case 30: {
			for (int i = 1; i <= City_Num; i++) {
				bool red_found = false;
				bool blue_found = false;
				int j1;
				for (j1 = 0; j1 < RED.warrior.size(); j1++) {
					if (RED.warrior[j1]->Pos == i) {
						red_found = true; break;
					}
				}

				if (red_found) {
					for (int k = 0; k < BLUE.warrior.size(); k++) {
						if (BLUE.warrior[k]->Pos == i) {
							blue_found = true;
							break;
						}
					}
					if (!blue_found) {
						RED.Produce_Hp(City_Hp[i], j1, T, "red");
						City_Hp[i] = 0;
					}
				}
				else {
					int j2;
					for (j2 = 0; j2 < BLUE.warrior.size(); j2++) {
						if (BLUE.warrior[j2]->Pos == i) {
							blue_found = true;
							break;
						}
					}
					if (blue_found) {
						BLUE.Produce_Hp(City_Hp[i], j2, T, "blue");
						City_Hp[i] = 0;
					}
				}
			}
			break;
		}
		case 35:
		{
			for (int i = 1; i <= City_Num; i++) {
				for (int j = 0; j < RED.warrior.size(); j++) {
					if (RED.warrior[j]->Pos == i)
						for (int k = 0; k < BLUE.warrior.size(); k++) {
							RshotB(RED.warrior[j], BLUE.warrior[k], T);
						}
				}
				for (int j = 0; j < BLUE.warrior.size(); j++) {
					if (BLUE.warrior[j]->Pos == i) {
						for (int k = 0; k < RED.warrior.size(); k++) {
							BshotR(RED.warrior[k], BLUE.warrior[j], T);
						}
					}
				}
			}
			break;
		}
		case 38:
		{
			for (int i = 1; i <= City_Num; i++) {
				for (int j = 0; j < RED.warrior.size(); j++) {
					for (int k = 0; k < BLUE.warrior.size(); k++) {
						if (RED.warrior[j]->Pos == i && RED.warrior[j]->Pos == BLUE.warrior[k]->Pos) {
							Warrior tmpr = *RED.warrior[j], tmpb = *BLUE.warrior[k];
							if (RED.warrior[j]->Hp > 0 && BLUE.warrior[k]->Hp > 0) {
								if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1)))
									tmpr.Sword_Attack(&tmpb, i, "red", "blue", T, false);
								else if (City_Flag[i] == "blue" || (City_Flag[i] == "NULL" && !(i & 1))) {
									tmpb.Sword_Attack(&tmpr, i, "blue", "red", T, false);
								}
								if ((tmpr.Hp > 0 && tmpb.Hp <= 0) && (tmpb.Bomb() != -1)) {
									//同归于尽
									RED.warrior.erase(RED.warrior.begin() + j);
									BLUE.warrior.erase(BLUE.warrior.begin() + k);
									j = min((int)RED.warrior.size() - 1, j);
									k = min((int)BLUE.warrior.size() - 1, k);
									Time(T);
									printf("blue %s %d used a bomb and killed red %s %d\n", Warrior_Name[tmpb.Type].c_str(),
										tmpb.ID, Warrior_Name[tmpr.Type].c_str(), tmpr.ID);
								}
								else if ((tmpb.Hp > 0 && tmpr.Hp <= 0) && (tmpr.Bomb() != -1)) {
									RED.warrior.erase(RED.warrior.begin() + j);
									BLUE.warrior.erase(BLUE.warrior.begin() + k);
									j = min((int)RED.warrior.size() - 1, j);
									k = min((int)BLUE.warrior.size() - 1, k);
									Time(T);
									printf("red %s %d used a bomb and killed blue %s %d\n", Warrior_Name[tmpr.Type].c_str(),
										tmpr.ID, Warrior_Name[tmpb.Type].c_str(), tmpb.ID);
								}
								j = min((int)RED.warrior.size() - 1, j);
								k = min((int)BLUE.warrior.size() - 1, k);
								j = max(0, j);
								k = max(0, k);
								if (RED.warrior.size() == 0)break;
							}
						}
					}
				}
			}
			break;
		}
		case 40: {
			int tmp_R_hp_plus = 0, tmp_B_hp_plus = 0;
			bool RED_win[30] = { false }; bool BLUE_win[30] = { false };
			for (int i = 1; i <= City_Num; i++) {
				for (int j = 0; j < RED.warrior.size(); j++) {
					for (int k = 0; k < BLUE.warrior.size(); k++) {
						if (RED.warrior[j]->Pos == i && RED.warrior[j]->Pos == BLUE.warrior[k]->Pos) {
							int winflag = 0;
							int attack_first = 0;
							int tmp_R_hp = RED.warrior[j]->Hp; int tmp_B_hp = BLUE.warrior[k]->Hp;
							tmp_R_hp = max(0, tmp_R_hp); tmp_B_hp = max(0, tmp_B_hp);
							if (RED.warrior[j]->Hp <= 0 && BLUE.warrior[k]->Hp <= 0) {
								RED.warrior.erase(RED.warrior.begin() + j);
								BLUE.warrior.erase(BLUE.warrior.begin() + k);
								break;
							}
							else if (RED.warrior[j]->Hp <= 0 && BLUE.warrior[k]->Hp > 0) {
								winflag = -1;
							}
							else if (RED.warrior[j]->Hp > 0 && BLUE.warrior[k]->Hp <= 0) {
								winflag = 1;
							}
							else if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1))) {
								RED.warrior[j]->Sword_Attack(BLUE.warrior[k], i, "red", "blue", T, true);
							}
							else if (City_Flag[i] == "blue" || (City_Flag[i] == "NULL" && !(i & 1))) {
								BLUE.warrior[k]->Sword_Attack(RED.warrior[j], i, "blue", "red", T, true);
							}
							if (City_Flag[i] == "red" || (City_Flag[i] == "NULL" && (i & 1)))
								attack_first = 1;
							else
								attack_first = -1;
							if (RED.warrior[j]->Hp > 0 && BLUE.warrior[k]->Hp <= 0) {
								winflag = 1; RED_win[i] = true;
							}
							else if (RED.warrior[j]->Hp <= 0 && BLUE.warrior[k]->Hp > 0)
							{
								winflag = -1; BLUE_win[i] = true;
							}
							RED.warrior[j]->Clean(BLUE.warrior[k], i, attack_first, winflag, "red", "blue", T, tmp_R_hp_plus, tmp_R_hp);
							BLUE.warrior[k]->Clean(RED.warrior[j], i, -attack_first, -winflag, "blue", "red", T, tmp_B_hp_plus, tmp_B_hp);
							if (RED.warrior[j]->Hp > 0 && BLUE.warrior[k]->Hp <= 0) {//蓝死
								BLUE.warrior.erase(BLUE.warrior.begin() + k);
							}
							else if (RED.warrior[j]->Hp <= 0 && BLUE.warrior[k]->Hp > 0)
							{
								RED.warrior.erase(RED.warrior.begin() + j);
							}
							j = min((int)RED.warrior.size() - 1, j);
							k = min((int)BLUE.warrior.size() - 1, k);
							j = max(0, j);
							k = max(0, k);
							if (RED.warrior.size() == 0)break;
						}

					}
				}
			}
			for (int i = 1; i <= City_Num && RED.Head_Hp >= 8; i++) {
				if (RED_win[i]) {
					for (int j = 0; j < RED.warrior.size(); j++) {
						if (RED.warrior[j]->Pos == i) {
							RED.Head_Hp -= 8;
							RED.warrior[j]->Hp += 8;
						}
					}
				}
			}
			for (int i = City_Num; i >= 1 && BLUE.Head_Hp >= 8; i--) {
				if (BLUE_win[i]) {
					for (int j = 0; j < BLUE.warrior.size(); j++) {
						if (BLUE.warrior[j]->Pos == i) {
							BLUE.Head_Hp -= 8;
							BLUE.warrior[j]->Hp += 8;
						}
					}
				}
			}
			RED.Head_Hp += tmp_R_hp_plus;
			BLUE.Head_Hp += tmp_B_hp_plus;
			for (int j = 0; j < RED.warrior.size(); j++) {
				if (RED.warrior[j]->Hp <= 0) {
					RED.warrior.erase(RED.warrior.begin() + j),
						j = min((int)RED.warrior.size() - 1, j);
				}
			}
			for (int j = 0; j < BLUE.warrior.size(); j++) {
				if (BLUE.warrior[j]->Hp <= 0) {
					BLUE.warrior.erase(BLUE.warrior.begin() + j),
						j = min((int)BLUE.warrior.size() - 1, j);
				}
			}
			break;
		}
		case 50: {
			RED.Report(T);
			BLUE.Report(T);
			break;
		}
		case 55: {
			for (int i = 1; i <= City_Num + 1; i++) {
				for (int j = 0; j < RED.warrior.size(); j++) {
					if (RED.warrior[j]->Pos == i) {
						RED.warrior[j]->ReportWeapon(T, "red");
					}
				}
			}
			for (int i = 0; i <= City_Num; i++) {
				for (int j = 0; j < BLUE.warrior.size(); j++) {
					if (BLUE.warrior[j]->Pos == i) {
						BLUE.warrior[j]->ReportWeapon(T, "blue");
					}
				}
			}
			break;
		}
		}
	}
	return;
}

int main() {
	int cnt;
	cin >> cnt;
	for (int i = 1; i <= cnt; i++) {
		cout << "Case " << i << ":" << endl;
		Init();
		Fight();
	}
	return 0;
}