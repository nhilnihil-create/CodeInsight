#include <iostream>
#include <string>
#include <cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<iomanip>
#define _USE_MATH_DEFINES
#include <math.h>
#include <functional>
using namespace std;

#define rep(i,x) for(ll i=0;i<x;i++)
#define repn(i,x) for(ll i=1;i<=x;i++)

typedef long long ll;
const ll INF = 1e17;
const ll MOD = 1000000007;
const ll MAX = 1000001;

ll max(ll a, ll b) {
	if (a > b) { return a; }
	return b;
}

ll min(ll a, ll b) {
	if (a > b) { return b; }
	return a;
}

ll gcd(ll a, ll b) {
	if (b == 0) { return a; }
	if (a < b) { return gcd(b, a); }
	return gcd(b, a%b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) *b;
}

struct edge {
	ll ind;
	ll fr;
	ll to;
	ll d;
};


///////////////////////////




int main() {

	ll N;
	cin >> N;
	vector<ll> x(N + 1,0);

	repn(i, N) cin >> x[i];

	ll L;
	cin >> L;

	vector<ll> tr(N + 1);

	repn(i, N) {
		auto itr = upper_bound(x.begin(), x.end(), x[i] + L);
		tr[i] = distance(x.begin(), itr) - 1;
		//cout << tr[i] << endl;
	}

	vector<vector<ll>> dp(N + 1, vector<ll>(30));

	repn(i, N)dp[i][0] = tr[i];

	repn(j, 29)repn(i,N) {
		dp[i][j] = dp[dp[i][j - 1]][j - 1];
		//cout << i << j << dp[i][j]<<endl;
	}

	ll Q;
	cin >> Q;
	repn(i, Q) {
		ll a, b;
		cin >> a >> b;

		if (a > b) { swap(a, b); }

		ll ans = 0;

		for (ll j = 29; j >= 0; j--) {
			if (dp[a][j] < b) {
				//cout << dp[a][j] << endl;
				ans += 1 << j;
				a = dp[a][j];
			}
		}

		cout << ans + 1<<endl;
	}

	system("PAUSE");

}



