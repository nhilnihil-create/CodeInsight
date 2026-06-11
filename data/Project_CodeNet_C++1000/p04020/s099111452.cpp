#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int MOD = 1000000007;
const double PI = acos(-1);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};

void solve() {
	int n;
	cin >> n;
	vector<ll> v(n);
	rep(i,n) cin >> v[i];
	ll ans = 0;
	for (int i = 0; i < n; i++) {
		ans += v[i] / 2;
		v[i] %= 2;
		if (i + 1 < n && v[i] != 0) {
			int x = min(v[i], v[i + 1]);
			ans += x;
			v[i] -= x;
			v[i+1] -= x;
		}
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}