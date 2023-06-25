//////////////////2760：数字三角形
//////////////////递推：赋值最后一行，从下往上填
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
////////////////	cout << dp[1][1];//bly是一个很强的学姐，如果说一个女生有自己的目标，并为之奋斗，那么她最后一定可以达成自己的目标
////////////////
////////////////}
//////////////////指针优化一下
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
////////////////			maxSum[j] = max(maxSum[j], maxSum[j + 1]) + D[i][j];//这样的写法看起来像是同行遍历覆盖，但是如果意识到maxSum是已经加上D[i][j]之后的maxsum了
////////////////			//，那就会知道其中的逻辑了
////////////////		}
////////////////	}
////////////////	cout << maxSum[1];//bly是一个很强的学姐，如果说一个女生有自己的目标，并为之奋斗，那么她最后一定可以达成自己的目标
////////////////
////////////////}
//////////////
////////////////LIS：2757
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
//////////////	cout << *max_element(maxLen+1, maxLen + n + 1);//输出最大元素，调用cstring库和algorithm库
//////////////}
//////////////1458：最长公共子序列
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
////////////滑雪：1088:记忆化搜索
//////////#include<iostream>
//////////#include<algorithm>
//////////#include<stdio.h>
//////////#include<cmath>
//////////using namespace std;
//////////const int maxn = 100;
//////////int R; int C;
//////////int dp[maxn][maxn];//初始化为1，最终的答案数组
//////////int height[maxn][maxn];//高度数组
//////////const int cx[] = { -1,1,0,0 };
//////////const int cy[] = { 0,0,-1,1 };
//////////int find(int x, int y) {
//////////	if (dp[x][y]!=1) {//否则默认为0了，这个在初始化的时候要考虑到
//////////		return dp[x][y];
//////////	}
//////////	for (int i = 0; i < 4; i++) {
//////////		int xx = x + cx[i]; int yy = y + cy[i];
//////////		if (xx > 0 && xx <= R && yy > 0 && yy <= C) {
//////////			if (height[xx][yy] < height[x][y]) {
//////////				dp[x][y] = max(dp[x][y], find(xx,yy) + 1);//细节是find（xx,yy)而非dp[xx][yy]
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
//////////神奇的口袋
//////////递归解法
////////#include<iostream>
////////#include<algorithm>
////////#include<stdio.h>
////////#include<cmath>
////////using namespace std;
////////int a[30]; int N;
////////int ways(int w, int k) {
////////	if (w == 0)return 1;
////////	if (k <= 0)return 0;
////////	return ways(w - a[k], k - 1) + ways(w, k - 1);//最好加上一个记忆化搜索
////////}
////////int main() {
////////	cin >> N;
////////	for (int i = 1; i <= N; i++) {
////////		cin >> a[i];
////////	}
////////	cout << ways(40, N); return 0;
////////}
////////动规解法
//////#include<iostream>
//////using namespace std;
//////int a[30]; int N;
//////int Ways[50][30];//从前j件物品凑出体积i，是一种覆盖制（David silver)
//////int main() {
//////	cin >> N;
//////	memset(Ways, 0, sizeof(Ways));
//////	for (int i = 1; i <= N; i++) {
//////		cin >> a[i]; Ways[0][i] = 1;//没有方法也是一种方法？
//////	}
//////	Ways[0][0] = 1;//基本初始化边界条件
//////	for (int w = 1; w <= 40; w++) {
//////		for (int k = 1; k <= N; k++) {
//////			Ways[w][k] = Ways[w][k - 1];
//////			if (w - a[k] >= 0) {
//////				Ways[w][k] += Ways[w - a[k]][k - 1];//先理解状态是什么，才能搞懂程序是怎么写的
//////			}
//////		}
//////	}
//////	cout << Ways[40][N]; return 0;
//////}
//////灌溉操场
////#include<iostream>
////#include<cstring>
////#include<queue>
////using namespace std;
////const int INFINITE = 1 << 31;
////const int MAXL = 1000010;
////const int MAXN = 1010;
////int F[MAXL];//F[L]为答案
////int cowThere[MAXL];//为1，表示该点有奶牛
////int N, L, A, B;
////struct Fx {
////	int x; int f;
////	bool operator<(const Fx&a)const { return f > a.f; }//重构比大小
////	Fx(int xx=0,int ff=0):x(xx),f(ff){}//构造函数
////};//在优先队列中，f小的优先
////priority_queue<Fx>qFx;
////int main() {
////	cin >> N >> L;
////	cin >> A >> B;
////	A <<= 1; B <<= 1;//A,B定义变为覆盖的直径，乘2了
////	memset(cowThere, 0, sizeof(cowThere));
////	for (int i = 0; i < N; i++) {
////		int s, e;
////		cin >> s >> e;
////		++cowThere[s + 1];//从s+1起进入一个奶牛区
////		//这个覆盖区不应该把s到e所有的都覆盖了吗
////		--cowThere[e];//从e起退出一个奶牛区，这是由于开区间导致的
////
////	}
////	int inCow = 0;//当前点位于多少牛活动范围内
////	for (int i = 0; i <= L; i++) {
////		F[i] = INFINITE;
////		inCow += cowThere[i];//因为有奶牛区域可能重合不一定有没有
////		cowThere[i] = inCow > 0;
////	}
////	for (int i = A; i <= B; i += 2) {
////		if (!cowThere[i]) {
////			F[i] = 1;
////			if (i <= B + 2 - A)//求F[i]保证队列里的点x，x《=i-A;
////			{
////				qFx.push(Fx(i, 1));//这相当于边界条件，之所以是1，意指把方案数都设置为1
////			}
////		}
////	}
////	for (int i = B + 2; i <= L; i += 2) {//当X大于2B时
////		if (!cowThere[i]) {
////			Fx fx;
////			while (!qFx.empty()) {
////				fx = qFx.top();
////				if (fx.x < i - B)//太靠左了没有帮助
////					qFx.pop();//删除顶端序列,顺便执行了删除操作
////				else
////					break;
////			}
////			//如果是队列空了，说明没找到，则直接还是记为无穷大
////			if (!qFx.empty()) {//判断是由于队列空了，还是找到合适的值跳出的
////				F[i] = fx.f + 1;
////			}
////			if (F[i - A + 2] != INFINITE) {//队列中增加下一个可达到的点
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
////方盒游戏
//#include<iostream>
//#include<cstring>
//#include<algorithm>
//#include<cmath>
//using namespace std;
//const int M = 210;
//struct Segment {//segment就是大块
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
//			continue;//找到同色的
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
