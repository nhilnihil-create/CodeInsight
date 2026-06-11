// IOI 2021
 
#include <bits/stdc++.h>
using namespace std;

#define sync ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define endl "\n"
#define ends ' '
#define die(x) return cout << x << endl, 0
#define all(v) v.begin(), v.end()
#define sz(x) (int)(x.size())
#define debug(x) cerr << #x << ": " << x << endl
#define debugP(p) cerr << #p << ": {" << p.first << ", " << p.second << '}' << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const ll INF = 1e9, MOD = INF + 7;
 
/////////////////////////////////////////////////////////////////////
 
const int N = 1e5 + 5;

int main() {
 
	sync;

	int n, m, sumX = 0, sumY = 0; cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		sumX = (sumX + 1LL * (2 * i - n + 1) * x % MOD) % MOD;
	}
	for (int i = 0; i < m; i++) {
		int y; cin >> y;
		sumY = (sumY + 1LL * (2 * i - m + 1) * y % MOD) % MOD;
	}
	cout << 1LL * sumX * sumY % MOD << endl;

	return 0;
}
