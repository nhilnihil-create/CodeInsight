#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <cmath>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cstdio>
#include <set>
#include <map>
#include <bitset>
#include <stack>
#include <cctype>
using namespace std;
long long dp[55][3000];
int x[55];
int main() {
	int n, a;
	cin >> n >> a;
	for (int i = 1; i <= n; i++) {
		cin >> x[i];
	}
	dp[0][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 50; k >= 0; k--) {
			for (int j = 2600; j >= 0; j--) {
				dp[k + 1][j + x[i]] += dp[k][j];
			}
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += dp[i][i * a];
	}
	cout << ans << endl;
	return 0;
}
