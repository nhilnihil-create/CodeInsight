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






int main() {

	ll N;
	cin >> N;

	vector<ll> a(3 * N + 1);
	repn(i,3*N)cin >> a[i];

	vector<ll> g(3 * N + 2), l(3 * N + 2);

	priority_queue<ll,vector<ll>,greater<ll>> p;

	g[0] = 0;
	repn(i, N) {
		g[i] = g[i - 1] + a[i];
		p.push(a[i]);
	}

	for (ll i = N + 1; i <= 2 * N; i++) {
		ll x = p.top();
		p.pop();
		p.push(max(a[i], x));
		g[i] = g[i - 1] - x + max(a[i], x);
	}

	priority_queue<ll> q;

	l[3 * N + 1] = 0;
	for (ll i = 3 * N; i > 2 * N; i--) {
		l[i] = l[i + 1] + a[i];
		q.push(a[i]);
	}

	for (ll i = 2 * N; i >= N; i--) {
		ll x = q.top();
		q.pop();
		q.push(min(a[i], x));
		l[i] = l[i + 1] - x + min(x, a[i]);
	}

	ll ans = -INF;

	for (ll i = N; i <= 2 * N; i++) {
		ans = max(ans, g[i] - l[i + 1]);
	}
	
	cout << ans;
	system("PAUSE");
}
