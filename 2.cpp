#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*题目 - 集合里的乘法	
来源	2017医学部计算概论-期末考试-王佩
描述
给定整数集合S和一个目标数T，判断是否可以从S中挑选一个非空子集，子集中的数相乘的乘积为T。
关于输入
输入为两行。 
第一行为目标数T和S中的元素个数N，以空格隔开。 
第二行为S中的N个元素，以空格隔开。 
其中 N <= 16。
关于输出
如果可以，则输出YES，否则输出NO。
例子输入
Sample Input 1:

12 5

1 2 3 4 5



Sample Input 2:

33 5

4 2 8 7 5

例子输出
Sample Output 1:

YES



Sample Output 2:

NO
*/

int result = 1;
int T;
int N;
int S[18];
bool flag = 0;

void tryy(int start)
{
	if (flag)return;
	for (int i = start; i < N; i++) {
		if (flag)return;
		if (S[i] == 0)continue;
		//cout << result << " ";
		result *= S[i];
		//cout << S[i]<<" "<<result << endl;
		if (result > T) {
			result /= S[i]; continue;
		}
		else if (result == T) {
			cout << "YES" << endl; 
			flag = 1;
			return;
		}
		else {
			tryy(i + 1);
		}
		result /= S[i];
	}
}

int main()
{
	cin >> T;
	cin >> N;
	for (int i = 0; i < N; i++)cin >> S[i];
	flag = 0;
	tryy(0);
	if (!flag)cout << "NO" << endl;
	system("pause");
	return 0;
}

//没有考虑0的情况，return和continue用混了