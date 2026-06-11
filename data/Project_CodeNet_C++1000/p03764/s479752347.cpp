#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<ll, pair<ll, ll>> PP;

const ll MOD = 1e9 + 7;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define fr first
#define sc second


int main() {
	ll n, m, x[100010], y[100010], rx[100010] = { 0 }, ry[100010] = { 0 }, ans = 0, yy = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) {
		cin >> x[i];
		rx[i] = rx[i - 1] + x[i];
	}
	for (int i = 1;i <= m;i++) {
		cin >> y[i];
		ry[i] = ry[i - 1] + y[i];
	}
	for (int i = 1;i <= m - 1;i++) {
		yy = (yy + (ry[m] - ry[i] - ry[m - i]) + MOD * 1000000) % MOD;
	}
	//cout << yy << endl;
	for (int i = 1;i <= n - 1;i++) {
		ans = ans + (((rx[n] - rx[i] - rx[n - i] + MOD * 1000000)) % MOD*yy) % MOD;
		ans %= MOD;
	}
	cout << ans%MOD << endl;
	return 0;
}