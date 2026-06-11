#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define M 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N, Ma, Mb; cin >> N >> Ma >> Mb;
	vector<pair<pair<int, int>, int>> med(N);
	vector<vector<vector<ll>>> dp(N + 1, vector < vector<ll>>(401, vector<ll>(401, 1e15)));
	for (int i = 0; i < N; i++) {
		cin >> med[i].first.first >> med[i].first.second >> med[i].second;
		dp[i + 1][med[i].first.first][med[i].first.second] = med[i].second;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= 400; j++) {
			for (int k = 0; k <= 400; k++) {
				dp[i + 1][j][k] = min(dp[i + 1][j][k], dp[i][j][k]);
				if (j + med[i].first.first <= 400 && k + med[i].first.second <= 400)
					dp[i + 1][j + med[i].first.first][k + med[i].first.second] = 
					min(dp[i + 1][j + med[i].first.first][k + med[i].first.second], dp[i][j][k] + med[i].second);
				//cout << "i=" << i << "j=" << j << "k=" << k << endl;
			}
		}
	}

	ll ans = 1e15;
	for (int j = 1; j <= 400; j++) {
		for (int k = 1; k <= 400; k++) {
			if (j * Mb == k * Ma) {
				
				ans = min(ans, dp[N][j][k]);
				//cout << "j=" << j << " k=" << k << " ans=" << ans << endl;
			}
		}
	}

	if (ans == 1e15)cout << -1 << endl;
	else cout << ans << endl;
}