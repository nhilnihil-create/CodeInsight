#include <iostream>
#include <string>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cstring>
#define int long long
#define uint unsigned long long
#define CONTAINS(v,n) (find((v).begin(), (v).end(), (n)) != (v).end())
#define SORT(v) sort((v).begin(), (v).end())
#define RSORT(v) sort((v).rbegin(), (v).rend())
#define ARY_SORT(a, size) sort((a), (a)+(size))
#define MAX(a,b) (((a) > (b)) ? (a) : (b))
#define MIN(a,b) (((a) < (b)) ? (a) : (b))
using namespace std;

int INIT = 1000000000000000L; //10^5 * 10^9 * 10

int N;
int A[100000];
char op[100000];

int dp[100000][3];

int func(int n, int o) //括弧がo個開いている時、n番目以降を使ってつくれる最大の数
{
	if (dp[n][o] < INIT)
	{
		return dp[n][o];
	}

	int res;
	if (n == N - 1)
	{
		if (o % 2 == 0)
		{
			res = A[n];
		}
		else
		{
			res = -A[n];
		}
	}
	else
	{
		if (op[n + 1] == '+')
		{
			if (o == 0)
			{
				res = A[n] + func(n + 1, o);
			}
			else if (o == 1)
			{
				int d1 = -A[n] + func(n + 1, o);
				int d2 = -A[n] + func(n + 1, o - 1);
				res = MAX(d1, d2);
			}
			else if (o == 2)
			{
				int d1 = A[n] + func(n + 1, o);
				int d2 = A[n] + func(n + 1, o - 1);
				int d3 = A[n] + func(n + 1, o - 2);
				res = MAX(d1, MAX(d2, d3));
			}
		}
		else
		{
			if (o == 0)
			{
				res = A[n] + func(n + 1, o + 1);
			}
			else if (o == 1)
			{
				int d1 = -A[n] + func(n + 1, o + 1);
				int d2 = -A[n] + func(n + 1, o);
				res = MAX(d1, d2);
			}
			else if (o == 2)
			{
				int d1 = A[n] + func(n + 1, o);
				int d2 = A[n] + func(n + 1, o - 1);
				res = MAX(d1, d2);
			}
		}
	}

	dp[n][o] = res;
	return res;
}

signed main()
{
	cin >> N;
	op[0] = '+';
	for (int i = 0; i < N; i++)
	{
		if (i > 0)
		{
			cin >> op[i];
		}
		cin >> A[i];

		for (int j = 0; j < 3; j++) dp[i][j] = INIT;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = 0; j < 3; j++)
		{
			func(i, j);
		}
	}
	cout << func(0, 0) << endl;
}