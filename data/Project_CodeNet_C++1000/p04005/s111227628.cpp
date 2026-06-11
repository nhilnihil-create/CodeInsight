#include <bits/stdc++.h>
#include <numeric>
#include <algorithm>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REP1(i, n) for(int i = 1; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	ll a, b, c; cin >> a >> b >> c;
	ll ans = max({ a,b,c });
	ll ans2 = ans / 2;
	ll ans3 = ans - ans2;
	if (ans == a) {
		cout << ans3 * b * c - ans2 * b * c << endl;
		return 0;
	}
	else if (ans == b) {
		cout << ans3 * a * c - ans2 * a * c << endl;
		return 0;
	}
	else if (ans == c) {
		cout << ans3 * b * a - ans2 * b * a << endl;
		return 0;
	}	
}
