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

ll pw(ll x, ll k) {
	if (k == 0) return 1;
	else return x * pw(x, k - 1);
}

void solve() {
	int n, p;
	cin >> n >> p;
	vector<int> v(n);
	rep(i,n) cin >> v[i];
	int odd = 0;
	int even = 0;
	rep(i,n) {
		if (v[i] % 2 == 0) even++;
		else odd++;
	}
	if (odd == 0) {
		if (p == 1) cout << 0 << endl;
		else cout << pw(2, n) << endl;
	} else {
		cout << pw(2, even) * pw(2, odd - 1) << endl;
	}
}

int main() {
	solve();
	return 0;
}