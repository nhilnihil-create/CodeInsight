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

	vector<ll> A(N + 1);
	repn(i, N) cin >> A[i];

	ll S = 0;
	repn(i, N) S += A[i];

	string ans = "YES";

	if (S % (N*(N + 1) / 2) != 0) { ans= "NO"; }

	else {
		ll M = S / (N*(N + 1) / 2);

		vector<ll> dif(N + 1);
		repn(i, N - 1) { dif[i] = A[i + 1] - A[i]; }
		dif[N] = A[1] - A[N];

		repn(i, N) {
			if (dif[i]>M||(dif[i] - M) % N != 0) { ans= "NO"; }
		}
	}

	cout << ans;

	system("PAUSE");
}
