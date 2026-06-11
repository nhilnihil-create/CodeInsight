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
	int n, m;
	cin >> n >> m;
	vector<int> x(m), y(m);
	rep(i,m) {
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
	}
	vector<bool> is(n);
	vector<int> v(n, 1);
	is[0] = true;
	rep(i,m) {
		int a = x[i];
		int b = y[i];
		v[a]--, v[b]++;
		if (is[a]) is[b] = true;
		if (!v[a]) is[a] = false;
	}
	int ans = 0;
	rep(i,n) if (is[i]) ans++;
	cout << ans << endl;
}

int main() {
	solve();
	return 0;
}