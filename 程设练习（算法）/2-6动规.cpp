//////////////////2760������������
//////////////////���ƣ���ֵ���һ�У�����������
////////////////#include<algorithm>
////////////////#include<iostream>
////////////////using namespace std;
////////////////const int man = 101;
////////////////int D[man][man]; int n;
////////////////int dp[man][man];
////////////////int main() {
////////////////	cin >> n;
////////////////	for (int i = 1; i <= n; i++) {
////////////////		for (int j = 1; j <= i; j++) {
////////////////			cin >> D[i][j];
////////////////		}
////////////////	}
////////////////	for (int i = 1; i <= n; i++) {
////////////////		dp[n][i] = D[n][i];
////////////////	}
////////////////	for (int i = n - 1; i >= 1; i--) {
////////////////		for (int j = 1; j <= i; j++) {
////////////////			dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + D[i][j];
////////////////		}
////////////////	}
////////////////	cout << dp[1][1];//bly��һ����ǿ��ѧ�㣬���˵һ��Ů�����Լ���Ŀ�꣬��Ϊ֮�ܶ�����ô�����һ�����Դ���Լ���Ŀ��
////////////////
////////////////}
//////////////////ָ���Ż�һ��
////////////////#include<algorithm>
////////////////#include<iostream>
////////////////using namespace std;
////////////////const int man = 101;
////////////////int D[man][man]; int n;
////////////////int *maxSum;
////////////////int main() {
////////////////	cin >> n;
////////////////	for (int i = 1; i <= n; i++) {
////////////////		for (int j = 1; j <= i; j++) {
////////////////			cin >> D[i][j];
////////////////		}
////////////////	}
////////////////	maxSum = D[n];
////////////////	for (int i = n - 1; i >= 1; i--) {
////////////////		for (int j = 1; j <= i; j++) {
////////////////			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];//������д������������ͬ�б������ǣ����������ʶ��maxSum���Ѿ�����D[i][j]֮���maxsum��
////////////////			//���Ǿͻ�֪�����е��߼���
////////////////		}
////////////////	}
////////////////	cout << maxSum[1];//bly��һ����ǿ��ѧ�㣬���˵һ��Ů�����Լ���Ŀ�꣬��Ϊ֮�ܶ�����ô�����һ�����Դ���Լ���Ŀ��
////////////////
////////////////}
//////////////
////////////////LIS��2757
//////////////#include<iostream>
//////////////#include<cstring>
//////////////#include<algorithm>
//////////////#include<stdio.h>
//////////////using namespace std;
//////////////const int MAXN = 1010;
//////////////int a[MAXN]; int maxLen[MAXN];
//////////////int main() {
//////////////	int n;
//////////////	cin >> n;
//////////////	for (int i = 1; i <= n; i++)
//////////////	{
//////////////		cin >> a[i]; maxLen[i] = 1;
//////////////	}
//////////////	for (int i = 2; i <= n; i++) {
//////////////		for (int j = 1; j < i; j++) {
//////////////			if (a[i] > a[j])
//////////////				maxLen[i] = maxLen[j] + 1;
//////////////		}
//////////////	}
//////////////	cout << *max_element(maxLen+1, maxLen + n + 1);//������Ԫ�أ�����cstring���algorithm��
//////////////}
//////////////1458�������������
////////////#include<iostream>
////////////#include<algorithm>
////////////#include<cmath>
////////////#include<stdio.h>
////////////#include<string>
////////////#include<cstring>
////////////using namespace std;
////////////const int maxn = 100;
////////////int maxlen[maxn][maxn];
////////////string s1, s2;
////////////int main() {
////////////	cin >> s1 >> s2;
////////////	int l1 = s1.length();
////////////	int l2 = s2.length();
////////////	for (int i = 1; i <= l1; i++) {
////////////		maxlen[i][0] = 0;
////////////	}
////////////	for (int i = 1; i <= l2; i++) {
////////////		maxlen[0][i] = 0;
////////////	}
////////////	for (int i = 1; i <= l1; i++) {
////////////		for (int j = 1; j <= l2; j++) {
////////////			if (s1[i - 1] == s2[j - 1]) {
////////////				maxlen[i][j] = maxlen[i - 1][j - 1] + 1;
////////////			}
////////////			else {
////////////				maxlen[i][j] = max(maxlen[i - 1][j], maxlen[i][j - 1]);
////////////			}
////////////		}
////////////	}
////////////	cout << maxlen[l1][l2];
////////////	return 0;
////////////
////////////}
////////////HELP JIMMY:2978
//////////
////////////��ѩ��1088:���仯����
//////////#include<iostream>
//////////#include<algorithm>
//////////#include<stdio.h>
//////////#include<cmath>
//////////using namespace std;
//////////const int maxn = 100;
//////////int R; int C;
//////////int dp[maxn][maxn];//��ʼ��Ϊ1�����յĴ�����
//////////int height[maxn][maxn];//�߶�����
//////////const int cx[] = { -1,1,0,0 };
//////////const int cy[] = { 0,0,-1,1 };
//////////int find(int x, int y) {
//////////	if (dp[x][y]!=1) {//����Ĭ��Ϊ0�ˣ�����ڳ�ʼ����ʱ��Ҫ���ǵ�
//////////		return dp[x][y];
//////////	}
//////////	for (int i = 0; i < 4; i++) {
//////////		int xx = x + cx[i]; int yy = y + cy[i];
//////////		if (xx > 0 && xx <= R && yy > 0 && yy <= C) {
//////////			if (height[xx][yy] < height[x][y]) {
//////////				dp[x][y] = max(dp[x][y], find(xx,yy) + 1);//ϸ����find��xx,yy)����dp[xx][yy]
//////////			}
//////////		}
//////////	}
//////////	return dp[x][y];
//////////}
//////////int main() {
//////////	cin >> R >> C;
//////////	for (int i = 1; i <= R; i++) {
//////////		for (int j = 1; j <= C; j++) {
//////////			cin >> height[i][j];
//////////			dp[i][j] = 1;
//////////		}
//////////	}
//////////	int ans = 1;
//////////	for (int i = 1; i <= R; i++) {
//////////		for (int j = 1; j <= C; j++) {
//////////			ans = max(ans, find(i, j));
//////////		}
//////////	}
//////////	cout << ans;
//////////}
//////////����Ŀڴ�
//////////�ݹ�ⷨ
////////#include<iostream>
////////#include<algorithm>
////////#include<stdio.h>
////////#include<cmath>
////////using namespace std;
////////int a[30]; int N;
////////int ways(int w, int k) {
////////	if (w == 0)return 1;
////////	if (k <= 0)return 0;
////////	return ways(w - a[k], k - 1) + ways(w, k - 1);//��ü���һ�����仯����
////////}
////////int main() {
////////	cin >> N;
////////	for (int i = 1; i <= N; i++) {
////////		cin >> a[i];
////////	}
////////	cout << ways(40, N); return 0;
////////}
////////����ⷨ
//////#include<iostream>
//////using namespace std;
//////int a[30]; int N;
//////int Ways[50][30];//��ǰj����Ʒ�ճ����i����һ�ָ����ƣ�David silver)
//////int main() {
//////	cin >> N;
//////	memset(Ways, 0, sizeof(Ways));
//////	for (int i = 1; i <= N; i++) {
//////		cin >> a[i]; Ways[0][i] = 1;//û�з���Ҳ��һ�ַ�����
//////	}
//////	Ways[0][0] = 1;//������ʼ���߽�����
//////	for (int w = 1; w <= 40; w++) {
//////		for (int k = 1; k <= N; k++) {
//////			Ways[w][k] = Ways[w][k - 1];
//////			if (w - a[k] >= 0) {
//////				Ways[w][k] += Ways[w - a[k]][k - 1];//�����״̬��ʲô�����ܸ㶮��������ôд��
//////			}
//////		}
//////	}
//////	cout << Ways[40][N]; return 0;
//////}
//////��Ȳٳ�
////#include<iostream>
////#include<cstring>
////#include<queue>
////using namespace std;
////const int INFINITE = 1 << 31;
////const int MAXL = 1000010;
////const int MAXN = 1010;
////int F[MAXL];//F[L]Ϊ��
////int cowThere[MAXL];//Ϊ1����ʾ�õ�����ţ
////int N, L, A, B;
////struct Fx {
////	int x; int f;
////	bool operator<(const Fx&a)const { return f > a.f; }//�ع��ȴ�С
////	Fx(int xx=0,int ff=0):x(xx),f(ff){}//���캯��
////};//�����ȶ����У�fС������
////priority_queue<Fx>qFx;
////int main() {
////	cin >> N >> L;
////	cin >> A >> B;
////	A <<= 1; B <<= 1;//A,B�����Ϊ���ǵ�ֱ������2��
////	memset(cowThere, 0, sizeof(cowThere));
////	for (int i = 0; i < N; i++) {
////		int s, e;
////		cin >> s >> e;
////		++cowThere[s + 1];//��s+1�����һ����ţ��
////		//�����������Ӧ�ð�s��e���еĶ���������
////		--cowThere[e];//��e���˳�һ����ţ�����������ڿ����䵼�µ�
////
////	}
////	int inCow = 0;//��ǰ��λ�ڶ���ţ���Χ��
////	for (int i = 0; i <= L; i++) {
////		F[i] = INFINITE;
////		inCow += cowThere[i];//��Ϊ����ţ��������غϲ�һ����û��
////		cowThere[i] = inCow > 0;
////	}
////	for (int i = A; i <= B; i += 2) {
////		if (!cowThere[i]) {
////			F[i] = 1;
////			if (i <= B + 2 - A)//��F[i]��֤������ĵ�x��x��=i-A;
////			{
////				qFx.push(Fx(i, 1));//���൱�ڱ߽�������֮������1����ָ�ѷ�����������Ϊ1
////			}
////		}
////	}
////	for (int i = B + 2; i <= L; i += 2) {//��X����2Bʱ
////		if (!cowThere[i]) {
////			Fx fx;
////			while (!qFx.empty()) {
////				fx = qFx.top();
////				if (fx.x < i - B)//̫������û�а���
////					qFx.pop();//ɾ����������,˳��ִ����ɾ������
////				else
////					break;
////			}
////			//����Ƕ��п��ˣ�˵��û�ҵ�����ֱ�ӻ��Ǽ�Ϊ�����
////			if (!qFx.empty()) {//�ж������ڶ��п��ˣ������ҵ����ʵ�ֵ������
////				F[i] = fx.f + 1;
////			}
////			if (F[i - A + 2] != INFINITE) {//������������һ���ɴﵽ�ĵ�
////				qFx.push(Fx(i - A + 2, F[i - A + 2]));
////			}
////		}
////	}
////	if (F[L] == INFINITE) {
////		cout << -1 << endl;
////	}
////	else {
////		cout << F[L] << endl;
////	}return 0;
////}
////
////������Ϸ
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int M = 210;
//struct Segment {//segment���Ǵ��
//	int color;
//	int len;
//};
//Segment segments[M];
//int score[M][M][M];
//int ClickBox(int i, int j, int len) {
//	if (score[i][j][len] != -1)
//		return score[i][j][len];
//	int result = (segments[j].len + len)*(segments[j].len + len);
//	if (i == j)
//		return result;
//	result += ClickBox(i, j - 1, 0);
//	for (int k = i; k <= j - 1; k++) {
//		if (segments[k].color != segments[j].color)
//			continue;//�ҵ�ͬɫ��
//		int r = ClickBox(k + 1, j - 1, 0);
//		r += ClickBox(i, k, segments[j].len + len);
//		result = max(result, r);
//	}
//	score[i][j][len] = result;
//	return result;
//}
//int main() {
//	int T;
//	cin >> T;
//	for (int t = 1; t <= T; t++) {
//		int n;
//		memset(score, 0xff, sizeof(score));
//		cin >> n;
//		int lastC = 0;
//		int segNum = -1;
//		for (int i = 0; i < n; i++) {
//			int c;
//			cin >> c;
//			if (c != lastC) {
//				segNum++;
//				segments[segNum].len = 1;
//				segments[segNum].color = c;
//				lastC = c;
//			}
//			else segments[segNum].len++;
//		}
//		cout << "Case" << t << ":" << ClickBox(0, segNum, 0) << endl;
//	}return 0;
//}
