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
const ll MOD = 998244353;
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

	ll N, K;
	cin >> N >> K;

	vector<ll> a(N + 1);
	repn(i, N) cin >> a[i];

	vector<ll> wa(N + 2 - K,0);
	vector<ll> abswa(N + 2 - K,0);

	repn(i, K) {
		wa[1] += a[i];
		abswa[1] += max(a[i],0);
	}

	for (ll i = 2; i <= N + 1 - K; i++) {
		wa[i] = wa[i - 1] - a[i - 1] + a[i + K - 1];
		abswa[i] = abswa[i - 1] - max(a[i - 1],0) + max(a[i + K - 1],0);
	}

	ll m = INF;
	repn(i, N + 1 - K) {
		m = min(m, abswa[i]-max(wa[i],0));
	}

	ll ans = -m;
	repn(i, N) ans += max(a[i],0);

	cout << ans;
	
	
	system("PAUSE");
}
