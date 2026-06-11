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
	ll to;
	ll d;
};


///////////////////////////

ll dv(ll h, ll w) {
	if (h % 2 == 0 || w % 2 == 0) { return 0; }
	else { return min(h, w); }
}

int main() {

	ll H, W;
	cin >> H >> W;

	ll ans = INF;

	rep(i, H + 1) {
		ll a = W * (H-i);

		ll x = dv(i, W);

		ll b = (i*W + x) / 2;
		ll c = b - x;

		ll t = max(abs(a - b), max(abs(b - c), abs(c - a)));
		ans = min(t, ans);

	}
	
	rep(i, W + 1) {
		ll a = (W - i) * H;

		ll x = dv(H, i);

		ll b = (i*H + x) / 2;
		ll c = b - x;

		ll t = max(abs(a - b), max(abs(b - c), abs(c - a)));
		ans = min(t, ans);

	}

	cout << ans;

	
	system("PAUSE");
}
