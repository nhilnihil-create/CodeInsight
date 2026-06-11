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

	ll N,A,B;
	cin >> N >> A >> B;

	vector<ll> v(N + 1);
	repn(i, N) cin >> v[i];

	sort(++v.begin(), v.end(), greater<ll>());

	ll X = v[A];

	ll s = 0;
	repn(i, A) s += v[i];

	double av = (double)s / (double)A;

	ll a, b;
	repn(i, N) {
		if (v[i] == X) { a = i; break; }
	}

	for (ll i = N; i > 0; i--) {
		if (v[i] == X) { b = i; break;}
	}

	ll com[51][51] = {};
	
	rep(i, 51) { com[i][0] = 1; }

	repn(i, 50)repn(j, 50) { com[i][j] = com[i - 1][j] + com[i - 1][j - 1]; }

	ll ans=0;

	if (a != 1) {
		ans = com[ b- a + 1][ A - a + 1];
	}

	if (a == 1) {
		ll t = min(B, b);
		for(ll i=A; i<=t; i++) ans += com[b][i];

	}

	cout << fixed << setprecision(10);

	cout << av << endl << ans;


	
	system("PAUSE");
}
