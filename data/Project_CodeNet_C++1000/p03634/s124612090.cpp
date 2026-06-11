#pragma region template
#include "bits/stdc++.h"
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD = 1e9 + 7, MAX = 1e18, larg = 1e5, INF = -1e9;
long long A, B, C, D, E, F, G, H, I, J, K, L, N, M, O, P, Q, R, S, T, U, V, W, x, y, z;
long long max_value = INF, max_index = -1;
long long min_value = MAX, min_index = -1;
typedef long long ll;
typedef pair<ll, ll> Pa;


ll dp[100001];
vector<Pa> to[100001];
Pa questions[100000];
int main() {
	cin >> N;
	rep(i, N+1) {
		dp[i] = MAX;
	}
	rep(i, N - 1) {
		cin >> A >> B >> C;
		to[A].push_back(Pa(B, C));
		to[B].push_back(Pa(A, C));
	}
	cin >> Q >> K;
	rep(i, Q) {
		cin >> A >> B;
		questions[i] = Pa(A, B);
	}

	dp[K] = 0;
	queue<int> que;
	que.push(K);
	while (!que.empty()) {
		int curr = que.front(); que.pop();
		rep(i, to[curr].size()) {
			if (dp[to[curr][i].first] == MAX) {
				que.push(to[curr][i].first);
				dp[to[curr][i].first] = dp[curr] + to[curr][i].second;
			}
		}
	}

	rep(i, Q) {
		cout << dp[questions[i].first] + dp[questions[i].second] << endl;
	}
}