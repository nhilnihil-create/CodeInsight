#include <iostream>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <functional>
#include <string>
#include <stack>
#include <set>
#include <sstream>
#include <iomanip>
#include <limits>
#include <cstring>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;
typedef pair<double, double >pd;
typedef pair<string, string> sP;
typedef pair<ll, P> PP;
typedef pair<P, P> PPP;

const ll MOD = 1e9 + 7;
const ll MOD2 = 998244353;
const ll INF = 1 << 30;
const ll INF2 = 9e18;
const double INF3 = 9e14;
const double eps = 1e-10;
const double PI = acos(-1);
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };

#define ALL(x) (x).begin(),(x).end()
#define ALLR(x) (x).rbegin(),(x).rend()
#define pb push_back
#define eb emplace_back
#define fr first
#define sc second

ll n, m, x[100010], y[100010], rx[100010], ry[100010], ans, yy;

int main() {
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
		yy = (yy + (ry[m] - ry[i] - ry[m - i]) + MOD * (ll)1e7) % MOD;
	}
	for (int i = 1;i <= n - 1;i++) {
		ans = ans + (((rx[n] - rx[i] - rx[n - i] + MOD * (ll)1e7)) % MOD*yy) % MOD;
		ans %= MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
