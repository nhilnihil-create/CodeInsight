#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<iomanip>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
#define FOR(i, a, b) for (ll i = (a); i <= (b); i++)
#define REP(i, n) FOR(i, 0, n - 1)
#define NREP(i, n) FOR(i, 1, n)
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const ll dx[4] = { 0, -1, 1, 0 };
const ll dy[4] = { -1, 0, 0, 1 };
const ll INF = 1e9 + 7;
const ll inf = 1LL << 50;
int gcd(int x, int y) {
	if (x < y)swap(x, y);
	if (y == 0)return x;
	return gcd(y, x%y);
}
void mul(ll a, ll b) {
	a = a * b % INF;
}
///////////////////////////////////////

int main() {
	ll N, W; cin >> N >> W;
	vector<ll>V[4];
	ll wi;
	REP(i, N) {
		int	w, v;
		cin >> w >> v;
		if (i == 0) {
			V[0].push_back(v);
			wi = w;
		}
		else {
			V[w - wi].push_back(v);
		}
	}
	REP(i, 4) {
		sort(V[i].begin(), V[i].end(), greater<ll>());
	}
	vector<ll>sum[5];
	REP(i, 5)sum[i].push_back(0);
	for (int i = 0; i < 4; ++i) {
		for (int j = 1; j < V[i].size() + 1; ++j) {
			sum[i].push_back( sum[i][j - 1] + V[i][j - 1]);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= V[0].size(); ++i) {
		for (int j = 0; j <= V[1].size(); ++j) {
			for (int k = 0; k <= V[2].size(); ++k) {
				for (int l = 0; l <= V[3].size(); ++l) {
					if (i*wi + j * (wi + 1) + k * (wi + 2) + l * (wi + 3) > W)continue;
					ans = max(ans, sum[0][i] + sum[1][j] + sum[2][k] + sum[3][l]);
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}