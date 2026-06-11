#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <bitset>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	long long n, i, j, k, a, ans;
	cin >> n >> a;
	vector<long long> x(n);
	for (i = 0; i < n; i++) cin >> x[i];
	vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(n + 1, vector<long long>(a * n + 1, 0)));
	dp[0][0][0] = 1;
	for (i = 0; i < n; i++) {
		dp[i + 1] = dp[i];
		for (k = 0; k < n; k++) {
			for (j = 0; j < a * n; j++) {
				if (j + x[i] <= a * n) dp[i + 1][k + 1][j + x[i]] += dp[i][k][j];
			}
		}
	}

	ans = 0;
	for (i = 1; i <= n; i++) ans += dp[n][i][a * i];

	cout << ans << "\n";


	return 0;
}

