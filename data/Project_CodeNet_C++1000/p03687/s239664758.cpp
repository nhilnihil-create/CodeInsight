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
	string s;
	cin >> s;

	ll N = s.size();

	ll ans = INF;

	rep(i, N) {
		vector<ll> a;

		rep(j, N) {
			if (s[j] == s[i]) { a.push_back(j); }
		}

		ll dis = max(a[0], N - a[a.size()-1] - 1);
		rep(j, a.size() - 1) {
			dis = max(dis, a[j + 1] - a[j] -1);
		}

		ans = min(ans, dis);
	}

	cout << ans;

	system("PAUSE");
}
