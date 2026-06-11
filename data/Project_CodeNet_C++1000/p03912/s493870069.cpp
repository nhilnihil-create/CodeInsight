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
#define INF (ll)1 << 60
#define MINF (-1 * INF)
#define ALL(n) n.begin(),n.end()
#define MOD 1000000007
#define P pair<ll, ll>


ll n, m, cnt[110000], s1[110000], s2[110000], ans;

void f(ll i, ll mn) {
	ll now = mn;
	now -= min(now, s2[i]);
	s1[i] -= min(now, s1[i]);
	ans += s1[i] / 2;
}
int main() {
	cin >> n >> m;
	REP(i, n) {
		ll a;
		cin >> a;
		cnt[a]++;
	}
	REP(i, 110000) {
		if (cnt[i] % 2 == 1)s2[i % m]++;
		s1[i % m] += cnt[i] - cnt[i] % 2;
	}
	REPO(i, (m - 1) / 2) {
		ll mn = min(s1[i] + s2[i], s1[m - i] + s2[m - i]);
		ans += mn;
		f(i, mn);
		f(m - i, mn);
	}
	ans += (s2[0] + s1[0]) / 2;
	if (m % 2 == 0)ans += (s2[m / 2] + s1[m / 2]) / 2;
	cout << ans << endl;
}