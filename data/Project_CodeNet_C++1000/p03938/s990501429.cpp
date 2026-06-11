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
	ll N;
	cin >> N;

	vector<ll> p(N + 1,0);
	repn(i, N) {
		ll x;
		cin >> x;
		p[x] = i;
	}

	vector<ll> a(N + 1), b(N + 1);
	a[1] = b[1] = 1;

	for(ll i=2; i<=N; i++) {
		a[i]=a[i-1]+1;
		b[i]=b[i-1]-1;

		if (p[i-1] < p[i]) {
			a[i] += p[i] - p[i-1];
		}

		else {
			b[i] += p[i] - p[i-1];
		}
	}

	repn(i, N) cout << a[i] << " ";
	cout << endl;
	repn(i, N) cout << b[i] - b[N] + 1 << " ";

	system("PAUSE");
}
