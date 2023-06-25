////2692：假币问题
////枚举假币的情况
////#include<iostream>
////#include<stdio.h>
////#include<cstring>
////using namespace std;
////
////char Left[3][7];//天平左硬币
////char Right[3][7];//天平右硬币
////char result[3][7];//结果
////
////bool IsFake(char c, bool light);
////
////int main() {
////	int n;
////	cin >> n;
////	while (n--) {
////		for (int i = 0; i < 3; i++) {
////			cin >> Left[i] >> Right[i] >> result[i];
////		}
////		for (char c = 'A'; c <= 'L'; c++) {
////			if (IsFake(c, true)) {
////				cout << c << " is the counterfeit coin and it is light." << endl;
////				break;
////			}
////			else if (IsFake(c, false)) {
////				cout << c << " is the counterfeit coin and it is heavy." << endl;
////				break;
////			}
////		}
////	}
////}
////bool IsFake(char c, bool light)//true代表轻，false代表重
////{
////	for (int i = 0; i < 3; i++) {
////		char *pLeft, *pRight;
////		if (light) {//轻的
////			pLeft = Left[i];
////			pRight = Right[i];
////		}
////		else {//重的
////			pLeft = Right[i];
////			pRight = Left[i];
////		}
////		下面开始比较，如果是轻的，right指针应该会有，如果是重的，那左边指针要有，相当于判断标准改为左边，u里没有，e中
////		switch (result[i][0])
////		{
////		case 'u':
////			if (strchr(pRight, c) == NULL)
////				return false; break;
////		case 'e':
////			if (strchr(pRight, c) || strchr(pLeft, c))
////				return false; break;
////		case 'd':
////			if (strchr(pLeft, c) == NULL)
////				return false; break;
////		default:
////			break;
////		}
////	}
////	return true;
////}
//
//////2977:生理周期
////#include<iostream>
////using namespace std;
////int main() {
////	int p, e, i, d;
////	while (cin >> p >> e >> i >> d) 
////	{
////		int k;
////		for (k = d + 1; (k - p) % 23; k++);
////		for (; (k - e) % 28; k += 23);//满足第二个条件不等于0才进行循环
////		for (; (k - i) % 33; k += 23 * 28);
////		cout << k - d; break;
////	}
////}
//
//2811:熄灯问题
#include<iostream>
#include<string>
#include<cstring>
#include<memory>
using namespace std;
char oriLights[5];//记录初始状态
char lights[5];//记录变化中的灯的状态
char result[5];//记录结果

int GetBit(char c, int i) {
	return (c >> i) & 1;//移i位与1进行操作
}

void SetBit(char&c, int i, int v) {//设置c的第i位为v
	if (v) {
		c |= (1 << i);
	}
	else {
		c &= ~(1 << i);
	}
}
void FlipBit(char&c, int i) {
	c ^= (1 << i);//翻转第i位，与1异或翻转，与0异或不变
}
void OutputResult(int t, char result[]) {
	//cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			cout << GetBit(result[i], j);
			if (j < 5) {
				cout << ' ';
			}
		}
		cout << endl;
	}
}
int t = 0;
int main() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 6; j++) {
			int s;
			cin >> s;
			SetBit(oriLights[i], j, s);
		}
	}
	for (int n = 0; n < 64; ++n) {//每一个n可以取遍二进制的不同位
		int switchs = n;
		memcpy(lights, oriLights, sizeof(oriLights));
		for (int i = 0; i < 5; i++) {
			//处理第i行的情况
			result[i] = switchs;//第i个已经确定了；再回来时i++了已经
			for (int j = 0; j < 6; j++) {
				if (GetBit(switchs, j)) {
					if (j - 1 >= 0) {
						FlipBit(lights[i], j-1);
					}
					FlipBit(lights[i], j);
					if (j + 1 < 6) {
						FlipBit(lights[i], j + 1);
					}
				}
				//还要处理i+1行，只要取异或就行
			}
			if (i < 4)
			{
				lights[i + 1] ^= switchs;
			}
			switchs = lights[i];//存一下当前灯的状态,lights灯亮灯暗也代表了这里摁不摁开关？
			//第i行的灯状态是什么，第i+1行开关状态就会是什么，因为只有这样才能把i全熄灭
		}
		if (lights[4] == 0) {
			t++;
			OutputResult(t, result);
			break;
		}
	}
}
