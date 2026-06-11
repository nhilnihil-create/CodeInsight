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
	return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
	return a / gcd(a, b) * b;
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

	vector<ll> p(N + 1);

	repn(i, N) {
		ll a;
		cin >> a;
		p[a] = i;
	}

	set<ll> st,ts;
	st.insert(N + 1);
	st.insert(0);

	ts.insert(-N - 1);
	ts.insert(0);

	ll ans = 0;
	repn(i, N) {
		auto itr = st.upper_bound(p[i]);
		ll x = *itr;

		itr = ts.upper_bound(-p[i]);
		ll y = -*itr;

		//cout << p[i] << x << y << endl;

		ans += (x - p[i]) * (p[i]-y)*i;
		st.insert(p[i]);
		ts.insert(-p[i]);
	}
	cout << ans;

	system("PAUSE");
}
