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
	ll n, k;
	cin >> n >> k;
	vector<pair<ll, ll>> v(n);
	rep(i,n) cin >> v[i].first >> v[i].second;
	sort(ALL(v));
	ll p = 0;
	rep(i,n) {
		p += v[i].second;
		if (p >= k) {
			cout << v[i].first << endl;
			return;
		}
	}
}

int main() {
	solve();
	return 0;
}