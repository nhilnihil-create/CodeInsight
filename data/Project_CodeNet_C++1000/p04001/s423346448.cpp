#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define faster ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define read freopen("in.txt", "r", stdin)
#define write freopen("out.txt", "w", stdout)
#define mem(x, n) memset(x, n, sizeof(x))
#define all(x) x.begin(), x.end()
#define endl "\n"

ll TotSum = 0;

void solve(string s, ll tot) {
	if (s.empty()) {
		TotSum += tot;
		return;
	}

	for (ll i = 1; i <= s.size(); i++) {
		solve(s.substr(i), tot + stoll(s.substr(0, i)));
	}
}

int main() {
	faster;

	string s;
	cin >> s;

	solve(s, 0);

	cout << TotSum << endl;

	return 0;
}