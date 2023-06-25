////八数码问题，单向广搜
//#include<iostream>
//#include<bitset>
//#include<cstring>
//using namespace std;
//int goalStatus;//目标状态
//bitset<362880>Flags;//节点是否可扩展的标记
//const int MAXS = 400000;
//char result[MAXS];//结果储存
//struct Node {
//	int status;//状态，即排列的编号
//	int father;//父节点指针
//	char move;//从父节点到本节点的移动方式u/d/r/l
//	Node(int s,int f,char m):
//		status(s),father(f),move(m){}
//	Node(){}
//};
//
//Node myQueue[MAXS];//状态队列，状态总数362880
//int qHead;
//int qTail;
////队头指针和队尾指针
//
//char sz4Moves[] = "udrl";//四种动作
//unsigned int factorial[21];
////存放0-20阶乘 21的阶乘unsigned存不下
////给定排列，求序号
//unsigned int GetPermutationNumForInt(int *perInt, int len) {
//	//积累这种方法，其实可以用于其他题目
//	//len不能超过21，perInt存放着0--(len-1)一个排列
//	unsigned int num = 0;
//	bool used[21];
//	memset(used, 0, sizeof(bool)*len);
//	for (int i = 0; i < len; ++i) {
//		unsigned int n = 0;
//		for (int j = 0; j < perInt[i]; ++j) {
//			if (!used[j])++n;
//
//		}
//		//看一下factorial,factorial的每一位都存放着对应的阶乘啊，所以说符合算法的
//		num += n * factorial[len - i - 1];
//		used[perInt[i]] = true;
//	}
//	return num;
//}
//template<class T>
//unsigned int GetPerumutationNum(T s1, T s2, int len) {
//	//[s1,s1+len)里面放着第0号序列
//	//[s2,s2+len)里面放着要求序号的排列
//	//两者必须一样长,len不能超过21
//	//排列的每个元素都不一样，要返回排列的编号
//	//看来输入的是一个string
//	int perInt[21];//要转换成[0,len-1]的整数的排列
//	for (int i = 0; i < len; ++i) {
//		for (int j = 0; j < len; ++j) {
//			if (*(s2 + i) == *(s1 + j)) {
//				perInt[i] = j;
//				break;
//			}
//		}
//	}
//	unsigned int num = GetPermutationNumForInt(perInt, len);
//	return num;
//}
//template<class T>
//void GetPermutationByNum(T s1, T s2, int len, unsigned int No) {
//	//根据排列编号，生成排列
//	//[s1,s1+len)里放着第0号排列，排列的每个元素都不一样
//	int perInt[21];
//	bool used[21];
//	memset(used, 0, sizeof(bool)*len);
//	for (int i = 0; i < len; ++i) {
//		unsigned int tmp; int n = 0; int j;
//		for (j = 0; j < len; ++j) {
//			if (!used[j]) {
//				if (factorial[len - i - 1] >= No + 1)break;
//				else No -= factorial[len - i - 1];
//			}
//		}
//		perInt[i] = j;
//		used[j] = true;
//	}
//	for (int i = 0; i < len; ++i) {
//		*(s2 + i) = *(s1 + perInt[i]);
//	}
//}
////字符串的形态形态，转换为整数形式的形态
//int StrStatusToIntStatus(const char * strStatus) {
//	return GetPerumutationNum("012345678", strStatus, 9);
//}
////整数形式的状态，转换为字符串形式的状态
//void IntStatusToStrStatus(int n, char* strStatus) {
//	GetPermutationByNum((char*)"012345678", strStatus, 9, n);
//}
//int NewStatus(int nStatus, char cMove) {
//	//求从nStatus经过cMove移动得到的新状态，若移动不可行，返回-1
//	char szTmp[20];
//	int nZeroPos;
//	IntStatusToStrStatus(nStatus, szTmp);
//	for (int i = 0; i < 9; ++i) {
//		if (szTmp[i] == '0'){
//			nZeroPos=i;//其实也是记录了空格所在的位置
//			break;
//		}
//	}
//	switch (cMove) {
//	case 'u':if (nZeroPos - 3 < 0)return -1;//空格在第一行
//			 else {
//		szTmp[nZeroPos] = szTmp[nZeroPos - 3];
//		szTmp[nZeroPos - 3] = '0';
//	}break;
//	case 'd':
//		if (nZeroPos + 3 > 8)return -1;//空格在第三行
//		else {
//			szTmp[nZeroPos] = szTmp[nZeroPos + 3];
//			szTmp[nZeroPos + 3] = '0';
//		}break;
//
//	case 'l':if (nZeroPos % 3 == 0)return -1;
//			 else {
//		szTmp[nZeroPos] = szTmp[nZeroPos - 1];
//		szTmp[nZeroPos - 1] = '0';
//
//	}break;
//	case 'r':if (nZeroPos % 3 == 2)return -1;
//			 else {
//		szTmp[nZeroPos] = szTmp[nZeroPos + 1];
//		szTmp[nZeroPos + 1] = '0';
//	}
//			break;
//	}
//	return StrStatusToIntStatus(szTmp);
//}
//bool Bfs(int nStatus) {//寻找从初始状态nStatus到目标状态的路径
//	int nNewStatus; Flags.reset();//清除所有扩展标记
//	qHead = 0; qTail = 1;
//	myQueue[qHead] = Node(nStatus, -1, 0);
//	while (qHead != qTail) {//队列非空
//		nStatus = myQueue[qHead].status;
//		if (nStatus == goalStatus) {
//			return true;
//		}
//		for (int i = 0; i < 4; i++) {
//			nNewStatus = NewStatus(nStatus, sz4Moves[i]);
//			if (nNewStatus == -1)continue;
//			if (Flags[nNewStatus])continue;//扩展标记已经存在，则不入队
//			Flags.set(nNewStatus, true)
//				;
//			//新节点入列
//			myQueue[qTail++] = Node(nNewStatus, qHead, sz4Moves[i]);
//
//		}
//		qHead++;
//	}
//	return false;
//}
//int main() {
//	factorial[0] = factorial[1] = 1;
//	for (int i=2; i < 21; ++i) {
//		factorial[i] = i * factorial[i - 1];
//	}
//	goalStatus = StrStatusToIntStatus("123456780");
//	char szLine[50];
//	char szLine2[20];
//	while (cin.getline(szLine, 48)) {
//		int i, j;
//		//将输入的原始字符串变为数字字符串
//		for ( i = 0, j = 0; szLine[i]; i++) {
//			if (szLine[i] != ' ') {
//				if (szLine[i] == 'x')szLine2[j++] = '0';
//				else szLine2[j++] = szLine[i];
//			}
//		}
//		szLine2[j] = 0;//字符串形式初始状态
//		int sumGoal = 0;//从此往后用奇偶性判断是否有解
//		for (int i = 0; i < 8; ++i)
//			sumGoal += i - 1;
//		int sumOri = 0;
//		for (int i = 0; i < 9; ++i) {
//			if (szLine2[i] == '0')continue;
//			for (int j = 0; j < i; ++j) {
//				if (szLine2[j] < szLine2[i] && szLine2[i] != '0')
//					sumOri++;
//			}
//		}
//		if (sumOri % 2 != sumGoal % 2) {
//			cout << "unsolvable" << endl;
//			continue;
//		}
//		//上面用奇偶性判断是否有解
//		if (Bfs(StrStatusToIntStatus(szLine2))) {
//			int nMoves = 0;
//			int nPos = qHead;
//			do {
//				//通过father找到成功的状态序列，并输出相应的步骤
//				result[nMoves++] = myQueue[nPos].move;
//				nPos = myQueue[nPos].father;
//			} while (nPos);
//			for (int i = nMoves - 1; i >= 0; i--) {
//				cout << result[i];
//			}
//		}
//		else
//			cout << "unsolvable" << endl;
//		
//	}
//}