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
#define MOD (ll)1000000007
#define P pair<ll, ll>

ll n, a, b, s[110000];
bool solve(ll index) { //条件判定
	ll cnt = 0;
	REP(i, n) {
		ll now = max(0ll, s[i] - b * index);
		cnt += (now + a - b - 1) / (a - b);
	}
	if (cnt <= index)return true;
	else return false;
}

ll nibutan() { //めぐる式

	ll ng = -1; //最大値ならs.size()
	ll ok = (ll)1e9 + 1000; // 最大値なら0

	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;

		if (solve(mid)) ok = mid;
		else ng = mid;
	}
	return ok; //満たさない最大ならng
}

int main() {
	cin >> n >> a >> b;
	REP(i, n) {
		cin >> s[i];
	}
	cout << nibutan() << endl;
}	
