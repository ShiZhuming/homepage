#include<iostream>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<stdlib.h>
#include<stdio.h>

using namespace std;

/*��Ŀ - ������ĳ˷�	
��Դ	2017ҽѧ���������-��ĩ����-����
����
������������S��һ��Ŀ����T���ж��Ƿ���Դ�S����ѡһ���ǿ��Ӽ����Ӽ��е�����˵ĳ˻�ΪT��
��������
����Ϊ���С� 
��һ��ΪĿ����T��S�е�Ԫ�ظ���N���Կո������ 
�ڶ���ΪS�е�N��Ԫ�أ��Կո������ 
���� N <= 16��
�������
������ԣ������YES���������NO��
��������
Sample Input 1:

12 5

1 2 3 4 5



Sample Input 2:

33 5

4 2 8 7 5

�������
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

//û�п���0�������return��continue�û���