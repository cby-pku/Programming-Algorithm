////2692���ٱ�����
////ö�ټٱҵ����
////#include<iostream>
////#include<stdio.h>
////#include<cstring>
////using namespace std;
////
////char Left[3][7];//��ƽ��Ӳ��
////char Right[3][7];//��ƽ��Ӳ��
////char result[3][7];//���
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
////bool IsFake(char c, bool light)//true�����ᣬfalse������
////{
////	for (int i = 0; i < 3; i++) {
////		char *pLeft, *pRight;
////		if (light) {//���
////			pLeft = Left[i];
////			pRight = Right[i];
////		}
////		else {//�ص�
////			pLeft = Right[i];
////			pRight = Left[i];
////		}
////		���濪ʼ�Ƚϣ��������ģ�rightָ��Ӧ�û��У�������صģ������ָ��Ҫ�У��൱���жϱ�׼��Ϊ��ߣ�u��û�У�e��
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
//////2977:��������
////#include<iostream>
////using namespace std;
////int main() {
////	int p, e, i, d;
////	while (cin >> p >> e >> i >> d) 
////	{
////		int k;
////		for (k = d + 1; (k - p) % 23; k++);
////		for (; (k - e) % 28; k += 23);//����ڶ�������������0�Ž���ѭ��
////		for (; (k - i) % 33; k += 23 * 28);
////		cout << k - d; break;
////	}
////}
//
//2811:Ϩ������
#include<iostream>
#include<string>
#include<cstring>
#include<memory>
using namespace std;
char oriLights[5];//��¼��ʼ״̬
char lights[5];//��¼�仯�еĵƵ�״̬
char result[5];//��¼���

int GetBit(char c, int i) {
	return (c >> i) & 1;//��iλ��1���в���
}

void SetBit(char&c, int i, int v) {//����c�ĵ�iλΪv
	if (v) {
		c |= (1 << i);
	}
	else {
		c &= ~(1 << i);
	}
}
void FlipBit(char&c, int i) {
	c ^= (1 << i);//��ת��iλ����1���ת����0��򲻱�
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
	for (int n = 0; n < 64; ++n) {//ÿһ��n����ȡ������ƵĲ�ͬλ
		int switchs = n;
		memcpy(lights, oriLights, sizeof(oriLights));
		for (int i = 0; i < 5; i++) {
			//�����i�е����
			result[i] = switchs;//��i���Ѿ�ȷ���ˣ��ٻ���ʱi++���Ѿ�
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
				//��Ҫ����i+1�У�ֻҪȡ������
			}
			if (i < 4)
			{
				lights[i + 1] ^= switchs;
			}
			switchs = lights[i];//��һ�µ�ǰ�Ƶ�״̬,lights�����ư�Ҳ�������������������أ�
			//��i�еĵ�״̬��ʲô����i+1�п���״̬�ͻ���ʲô����Ϊֻ���������ܰ�iȫϨ��
		}
		if (lights[4] == 0) {
			t++;
			OutputResult(t, result);
			break;
		}
	}
}
