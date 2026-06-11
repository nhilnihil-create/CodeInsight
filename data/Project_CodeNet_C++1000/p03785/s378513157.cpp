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
	ll n, c, k;
	cin >> n >> c >> k;
	vector<ll> t(n);
	rep(i,n) cin >> t[i];
	int ans = 0;
	sort(ALL(t));
	for(int i = 0; i < n;) {
		ll limT = t[i] + k;
		ll cnt = 0;
		while (i < n && cnt < c && t[i] <= limT) {
			i++;
			cnt++;
		}
		ans++;
	}
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}