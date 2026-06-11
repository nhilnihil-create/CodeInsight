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

	ll H, W, N;
	cin >> H >> W >> N;

	vector < vector<ll>> ans(H, vector<ll>(W));

	ll s = 0;

	repn(i, N) {
		ll a;
		cin >> a;

		repn(j, a) {
			ll h = s / W;
			ll w;
			if (h % 2 == 0) { w = s % W; }
			else { w = W - 1 - s % W; }
			ans[h][w] = i;
			s++;
		}
	}

	rep(h, H) {
		rep(w, W) {
			cout << ans[h][w]<<" ";
		}
		cout << endl;
	}

	system("PAUSE");

}



