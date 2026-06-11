#include <bits/stdc++.h>

#define M_PI       3.14159265358979323846   // pi

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> VI;
typedef pair<ll, ll> P;
typedef tuple<ll, ll, ll> t3;

#define rep(a,n) for(int a = 0;a < n;a++)
#define repi(a,b,n) for(int a = b;a < n;a++)

const ull mod = (ull)1e9 + 7;

int main(void)
{
	ll n, ma, mb;
	cin >> n >> ma >> mb;
	vector<t3> vs(n);
	rep(i, n) {
		ll a, b, c;
		cin >> a >> b >> c;
		vs[i] = tie(a, b, c);
	}
	const ll INF = 1e15;
	vector<vector<vector<ll>>> dp(2, vector<vector<ll>>(401, vector<ll>(401, INF)));
	dp[0][0][0] = 0;
	rep(i, n) {
		ll a, b, c;
		tie(a, b, c) = vs[i];
		rep(j, 401) {
			rep(k, 401) {
				dp[1][j][k] = dp[0][j][k];
			}
		}
		rep(j, 401-a) {
			rep(k, 401 -b) {
				dp[1][a + j][b + k] = min(dp[1][a+j][b+k], dp[0][j][k] + c);
			}
		}
		swap(dp[0], dp[1]);
	}
	ll mm = INF;
	for (int j = 1; j < 401;j++) {
		for (int k = 1; k < 401; k++) {
			if (j * mb == k * ma) {
				mm = min(mm, dp[0][j][k]);
			}

		}
	}
	if (mm == INF) {
		cout << -1 << endl;
		return 0;
	}
	cout << mm << endl;
	return 0;
}
