#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*题目 - 点赞狂	
来源	计算概论医学部-王春晖
描述
小明最近发现一个奇怪的现象：每次他发一条微博，总有一帮人点赞，哪怕他发的是诸如“我怎么
这么菜”这种很伤心的话题，依然有一帮小伙伴来点赞......他心里默默的称这些人为“点赞狂”。 

现在，他想统计一下他的好友中有多少是点赞狂。为了尽快得到统计结果，这一天，小明连续发了m
条微博，并记录了所有n个好友的点赞记录，现在请你帮忙统计他的好友中有多少人是点赞狂。 

注：假设某个好友对小明的微博点赞的条数是总条数的一半或一半以上，则称此人称为“点赞狂”。 
关于输入
输入数据第1行是一个整数T，表示有T组测试用例； 

每个测试用例的第1行是两个整数n和m，n是好友数，m是连续发的微博条数； 
接下来是n行，每行代表一个好友的点赞情况，每行m个整数（0或1），0代表没点赞，1代表点赞，
即第 i 行第 j 列表示第 i 个好友对小明发的第 j 条微博是否点赞，如果是0，表示没有点赞，如
果是1则表示有点赞。 

限制条件： 
1 <= T <= 20 
1 <= n <= 200 
1 <= m <= 200
关于输出
输出有T行，按输入顺序，对每组测试用例，输出点赞狂的个数，每组数据输出一行。 
例子输入
1

2 3

1 0 1

0 1 0

例子输出
1*/

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int m, n;
		cin >> n >> m;
		int count = 0;
		for (int j = 0; j < n; j++) {
			bool a;
			int c = 0;
			for (int k = 0; k < m; k++) {
				cin >> a;
				if (a)c++;
			}
			if ((2 * c) >= m)count++;
		}
		cout << count;
	}
	system("pause");
	return 0;
}