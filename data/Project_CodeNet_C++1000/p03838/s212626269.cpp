#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

ll dist(ll x, ll y) {
	if (x > y) return 0x3f3f3f3f3f3f3f3fll;
	return y - x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);

	ll x, y; cin >> x >> y;
	ll ans = 0x3f3f3f3f3f3f3f3fll;
	ans = min(ans, dist(x, y));
	ans = min(ans, dist(-x, -y) + 2);
	ans = min(ans, dist(-x, y) + 1);
	ans = min(ans, dist(x, -y) + 1);
	
	cout << ans << endl;
}
