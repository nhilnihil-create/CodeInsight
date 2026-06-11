#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <functional>
#include <cmath>
#include <set>
#include <queue>
#include <deque>
#include <vector>
#include <climits>
#include <sstream>
#include <iomanip>
#include <map>
#include <stack>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;

struct Combination2
{
	vector<vector<ll>> dp;

	Combination2(int n) : dp(n + 1, vector<ll>(n + 1))
	{
		for (auto i = 0; i <= n; ++i)
		{
			dp[i][0] = 1;
			dp[i][i] = 1;
		}

		for (auto i = 1; i <= n; ++i)
		{
			for (auto j = 1; j <= n; ++j)
			{
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			}
		}
	}

	ll calcCombination(int n, int k)
	{
		return dp[n][k];
	}
};


int main()
{
	int N, A, B;
	cin >> N >> A >> B;
	vector<ll> v(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end(), greater<ll>());

	auto sum = 0ll;
	auto numLastV = 0;
	auto lastV = 0ll;
	auto numNeed = 0;
	for (auto i = 0; i < N; ++i)
	{
		if (i < A)
		{
			sum += v[i];
			if (v[i] == lastV)
			{
				++numLastV;
				++numNeed;
			}
			else
			{
				numLastV = 1;
				numNeed = 1;
				lastV = v[i];
			}
		}
		else if (v[i] == lastV)
		{
			++numLastV;
		}
	}

	auto avg = (double)sum / A;
	auto comb = 1ll;
	if(numLastV > numNeed)
	{
		Combination2 c(numLastV);
		if (lastV == v[0])
		{
			comb = 0;
			for (auto i = A; i <= min(B, numLastV); ++i)
			{
				comb += c.calcCombination(numLastV, i);
			}
		}
		else
		{
			comb = c.calcCombination(numLastV, numNeed);
		}
	}

	cout << fixed << setprecision(10) << avg << endl;
	cout << comb << endl;

	return 0;
}