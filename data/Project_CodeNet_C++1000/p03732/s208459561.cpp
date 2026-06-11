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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e3 + 10;
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n, m;
	cin >> n >> m;
	int o = 0;
	for (int i = 1; i <= n; i++)
	{
		int w, v;
		cin >> w >> v;
		if (o == 0) o = w;
		w -= o;
		for (int j = i; j >= 1; j--)
		{
			for (int k = w; k <= 300; k++)
			{
				dp[j][k] = max(dp[j][k], dp[j - 1][k - w] + v);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 300 && 1LL * o * i + j <= m; j++)
			ans = max(ans, dp[i][j]);
	}
	cout << ans << endl;
	return 0;
}