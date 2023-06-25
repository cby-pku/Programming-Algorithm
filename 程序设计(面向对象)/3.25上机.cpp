//////Hero类
////#include <iostream>
////using namespace std;
////class Hero {
////public:
////	// 在此处补充你的代码
////	virtual void defense() {
////		cout << "Hero::defense()" << endl;
////	}
////	void attack() {
////		cout << "Hero::attack()" << endl;
////	}
////
////};
////class Priest : public Hero {
////public:
////	virtual void attack() { cout << "Priest::attack()" << endl; }
////	virtual void defense() { cout << "Priest::defense()" << endl; }
////};
////
////int main() {
////	Priest anduin;
////	Hero h;
////	h.defense();
////	Hero *player = &anduin;
////	player->attack();
////	player->defense();
////	anduin.attack();
////	anduin.defense();
////	return 0;
////}
////统计动物数量
//#include <iostream>
//using namespace std;
//// 在此处补充你的代码
//class Animal {
//public:
//	static int number;
//	Animal() {
//		number++;
//	}
//	virtual ~Animal() {//加virtual才能调用cat的析构函数
//		number--;
//	}
//};
//class Dog:public Animal {
//public:
//	static int number;
//	Dog() {
//		number++;
//		//Animal::number
//	}
//	~Dog() {
//		number--;
//	}
//};
//class Cat :public Animal {
//public:
//	static int number;
//	Cat() {
//		number++;
//	}
//	~Cat() {
//		number--;
//	}
//};
//int Animal::number = 0, Cat::number = 0, Dog::number = 0;
////静态成员变量需要在外赋值
//void print() {
//	cout << Animal::number << " animals in the zoo, " << Dog::number << " of them are dogs, " << Cat::number << " of them are cats" << endl;
//}
//
//int main() {
//	print();
//	Dog d1, d2;
//	Cat c1;
//	print();
//	Dog* d3 = new Dog();
//	Animal* c2 = new Cat;
//	Cat* c3 = new Cat;
//	print();
//	delete c3;
//	delete c2;
//	delete d3;
//	print();
//}