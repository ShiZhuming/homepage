#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*题目 - 字符串最大跨距	
来源	元培-From Whf
描述
有三个字符串S,S1,S2，其中，S长度不超过300,S1和S2的长度不超过10，想检测S1和S2是否同时在S
中出现，且S1位于S2的左边，并在S中互不交叉（即，S1的右边界点在S2的左边界点的左侧）。计算
满足上述条件的最大跨距（即，最大间隔距离：最右边的S2的起始点与最左边的S1的终止点之间的字
符数目）。如果没有满足条件的偶对S1，S2存在，则输出 -1 

例如，S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"，其中，S1在S中出现了2次，S2也在
S中出现了2次，最大跨距则为：18
关于输入
三个串：S, S2, S3，其间以逗号间隔（注意，S, S2, S3中均不含逗号）；
关于输出
S1和S2在S最大跨距；若在S中没有满足条件的S1和S2，则输出-1
例子输入
abcd123ab888efghij45ef67kl,ab,ef
例子输出
18
*/

char S[305];

bool comparee(int start, char a[])
{
	for (int i = 0; i < strlen(a); i++) {
		if (S[start + i] != a[i])return false;
	}
	return true;
}

int main()
{
	char s1[12], s2[12];
	cin.getline(S, 303, ',');
	cin.getline(s1, 12, ',');
	cin.getline(s2, 12, '\n');
	int maxx = -1, minn = 301;
	bool flag1 = 0; bool flag2 = 0;
	for (int i = 0; i < strlen(S); i++) {
		if (comparee(i, s1)&&!flag1) {
			maxx = i + strlen(s1);  flag1 = 1;
		}
		if (comparee(i, s2)&&!flag2) {
			minn = i; 
		}
		if (maxx > minn) {
			cout << "-1" << endl; return 0;
		}
	}
	if(maxx==-1&&minn==301){ cout << "-1" << endl; return 0; }
	cout << minn - maxx << endl;
	system("pause");
	return 0;
}

//最大跨距不是最小跨距