#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<ll> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;

#define rep(a,n) for(ll a = 0;a < n;a++)
#define repi(a,b,n) for(ll a = b;a < n;a++)

#include <bits/stdc++.h>
using namespace std;

static const ll INF = 1e15;

static const ll mod= 1e9 + 7;

vector<vector<ll>> dp;

int dfs(ll x, ll y) {
	if (x > y) { return dfs(y, x); }
	if (dp[x][y] >= 0) {
		return dp[x][y];
	}
	for (int i = 2; i <= x; i+=2) {
		int lose = dfs(x - i, y + i / 2);
		if (!lose) {
			dp[x][y] = 1;
			return 1;
		}
	}
	for (int i = 2; i <= y; i += 2) {
		int lose = dfs(x + i /2, y -  i);
		if (!lose) {
			dp[x][y] = 1;
			return 1;
		}
	}
	dp[x][y] = 0;
	return 0;
}

int main() {
	ll x, y;
	cin >> x >> y;

	ll u = max(x, y);
	ll l = min(x, y);
	if (abs(u - l) <= 1) {
		cout << "Brown" << endl;
	}
	else {
		cout << "Alice" << endl;
	}

	//dp.assign(100, vector<ll>(100, -1));
	//for (int i = 0; i < 30; i++) {
	//	for (int j = 0; j < 30; j++) {
	//		cout << dfs(i, j) << ",";
	//	}
	//	cout << endl;
	//}


	return 0;
}
	