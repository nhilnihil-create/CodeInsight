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

int main()
{
	int N, MA, MB;
	cin >> N >> MA >> MB;
	vector<int> a(N);
	vector<int> b(N);
	vector<int> c(N);
	for (auto i = 0; i < N; ++i)
	{
		cin >> a[i] >> b[i] >> c[i];
	}

	auto width = 10 * N * 10 * N + 1;
	vector<vector<ll>> dp(N + 1, vector<ll>(width, INT_MAX));
	dp[0][0] = 0;
	for (auto i = 0; i < N; ++i)
	{
		for (auto j = 0; j < width; ++j)
		{
			dp[i + 1][j] = dp[i][j];
			auto offset = a[i] * 10 * N + b[i];
			if (j >= offset)
			{
				dp[i + 1][j] = min(dp[i][j], dp[i][j - offset] + c[i]);
			}
		}
	}

	ll ans = INT_MAX;
	for (auto i = MA * 10 * N + MB; i < width; i += MA * 10 * N + MB)
	{
		ans = min(ans, dp[N][i]);
	}

	if (ans >= INT_MAX)
	{
		ans = -1;
	}
	cout << ans << endl;

	return 0;
}