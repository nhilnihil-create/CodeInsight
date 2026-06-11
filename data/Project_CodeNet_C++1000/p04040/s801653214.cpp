#include <iostream>
#include <string>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <iomanip>


using namespace std;

#define REP(i, n) for(ll i = 0;i < n;i++)
#define REPR(i, n) for(ll i = n;i >= 0;i--)
#define FOR(i, m, n) for(ll i = m;i < n;i++)
#define FORR(i, m, n) for(ll i = m;i >= n;i--)
#define REPO(i, n) for(ll i = 1;i <= n;i++)
#define ll long long
#define INF 1999999999
#define MINF -1999999999
#define INF64 1999999999999999999
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007




ll h, w, a, b, f[310000], ans = 0;

ll kn(ll aa, ll bb) {
	aa %= MOD;
	ll res = 1;
	while (bb > 0) {
		if (bb % 2 == 1)res *= aa;
		aa *= aa;
		bb /= 2;
		aa %= MOD;
		res %= MOD;
	}
	return res;
}

ll com(ll aa, ll bb) {
	return f[aa] * kn(f[aa - bb] * f[bb], MOD - 2) % MOD;
}

int main() {
	f[0] = 1;
	REPO(i, 300000)f[i] = f[i - 1] * i % MOD;
	cin >> h >> w >> a >> b;
	FOR(i, b + 1, w + 1) {
		ans += com(i + h - a - 2, h - a - 1) * com(a - 1 + w - i, a - 1);
		ans %= MOD;
	}
	cout << ans % MOD << endl;
}
