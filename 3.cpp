#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*��Ŀ - �ַ��������	
��Դ	Ԫ��-From Whf
����
�������ַ���S,S1,S2�����У�S���Ȳ�����300,S1��S2�ĳ��Ȳ�����10������S1��S2�Ƿ�ͬʱ��S
�г��֣���S1λ��S2����ߣ�����S�л������棨����S1���ұ߽����S2����߽�����ࣩ������
������������������ࣨ������������룺���ұߵ�S2����ʼ��������ߵ�S1����ֹ��֮�����
����Ŀ�������û������������ż��S1��S2���ڣ������ -1 

���磬S = "abcd123ab888efghij45ef67kl", S1="ab", S2="ef"�����У�S1��S�г�����2�Σ�S2Ҳ��
S�г�����2�Σ��������Ϊ��18
��������
��������S, S2, S3������Զ��ż����ע�⣬S, S2, S3�о��������ţ���
�������
S1��S2��S����ࣻ����S��û������������S1��S2�������-1
��������
abcd123ab888efghij45ef67kl,ab,ef
�������
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

//����಻����С���