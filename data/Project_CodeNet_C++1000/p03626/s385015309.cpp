#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 2e5 + 10;
int n;
LL dp[N][3][3];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	string s1, s2;
	int n;
	cin >> n;
	cin >> s1 >> s2;
	int cur = 0;
	if (s1[0] == s2[0])
	{
		for (int i = 0; i < 3; i++) dp[0][i][i] = 1;
		cur = 1;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (i == j) continue;
				dp[1][i][j] = 1;
			}
		}
		cur = 2;
	}
	for (int i = cur; i < n; i++)
	{
		if (s1[i] == s2[i])
		{
			for (int j = 0; j < 3; j++)
			{
				for (int o1 = 0; o1 < 3; o1++)
				{
					for (int o2 = 0; o2 < 3; o2++)
					{
						if (o1 == j) continue;
						if (o2 == j) continue;
						auto &tmp = dp[i][j][j] += dp[i - 1][o1][o2];
						if (tmp >= INF) tmp -= INF;
					}
				}
			}
		}
		else
		{
			i++;
			for (int j = 0; j < 3; j++)
			{
				for (int k = 0; k < 3; k++)
				{
					if (j == k) continue;
					for (int o1 = 0; o1 < 3; o1++)
					{
						if (o1 == j) continue;
						for (int o2 = 0; o2 < 3; o2++)
						{
							if (o2 == k) continue;
							auto &tmp = dp[i][j][k] += dp[i - 2][o1][o2];
							if (tmp >= INF) tmp -= INF;
						}
					}
				}
			}
		}
	}
	LL ans = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			ans += dp[n - 1][i][j];
		}
	}
	cout << ans % INF << endl;

	return 0;
}