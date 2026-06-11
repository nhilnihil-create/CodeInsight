#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <stack>
#include <string>
#include <vector>

#define REP(i, n) for(int i = 0; i < n; ++i)
using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

// dp[i][m]:i番目の数まで考えたとき余りがmとなる選び方の数
LLONG dp[51][2];

int main()
{
	int N, P; cin >> N >> P;
	// DPで解く:O(N)
	dp[0][0] = 1;
	REP(i, N) 
	{
		int ai; cin >> ai;
		if (ai % 2 == 0)
		{
			dp[i + 1][0] = dp[i][0] * 2;
			dp[i + 1][1] = dp[i][1] * 2;
		}
		else
		{
			dp[i + 1][0] = dp[i + 1][1] = dp[i][0] + dp[i][1];
		}
	}
	cout << dp[N][P] << endl;
}
