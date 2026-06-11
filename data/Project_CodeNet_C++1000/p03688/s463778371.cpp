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

	vector<ll> a(N + 1);
	repn(i, N) cin >> a[i];

	sort(++a.begin(), a.end());

	if (a[N] - a[1] > 1) { cout << "No"; }
	else if (a[N] - a[1] == 1) {
		auto itr = upper_bound(++a.begin(), a.end(), a[1]);
		ll L = distance(a.begin(), itr) - 1;
		ll K = a[N];

		if (K > L&&N >= L + 2 * (K - L)) { cout << "Yes"; }
		else { cout << "No"; }
	}

	else {
		if (a[1] == N - 1 || 2 * a[1] <= N) { cout << "Yes"; }
		else { cout << "No"; }
	}


	system("PAUSE");
}
