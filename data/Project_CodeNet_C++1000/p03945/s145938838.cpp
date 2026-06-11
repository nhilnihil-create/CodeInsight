#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define CST(x) cout << fixed << setprecision(x)
using ll = long long;
const ll MOD = 1000000007;
const int inf = 1e9 + 10;
const ll INF = 4e18 + 10;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int n = s.size();
	int cnt = 0;
	char c = s[0];
	rep(i, n) {
		if (s[i] != c) {
			cnt++;
			c = s[i];
		}
	}
	cout << cnt << endl;
	return 0;
}