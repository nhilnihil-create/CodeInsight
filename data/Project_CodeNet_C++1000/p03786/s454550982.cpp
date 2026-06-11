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

ll N;

vector<ll> A(N + 1);

ll ch(ll i) {
	ll s = 0;
	repn(j, i) s += A[j];

	for (ll j = i + 1; j <= N; j++) {
		if (s * 2 < A[j]) { return false; }
		s += A[j];
	}

	return true;
}



int main() {

	cin >> N;
	A.assign(N + 1, 0);
	repn(i, N) cin >> A[i];
	sort(++A.begin(), A.end());

	ll le = 0;
	ll ri = N + 1;

	while (ri - le > 1) {
		ll m = (le + ri) / 2;
		if (ch(m)) { ri = m; }
		else { le = m; }
	}

	cout << N - le;
	

	system("PAUSE");
}
