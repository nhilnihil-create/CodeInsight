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
	string S, T;
	cin >> S >> T;

	ll N = S.size();
	ll M = T.size();

	vector<ll> sumS(N + 1,0);
	repn(i, N) sumS[i] += sumS[i - 1] + S[i - 1] - 'A' + 1;

	vector<ll> sumT(M + 1, 0);
	repn(i, M) sumT[i] += sumT[i - 1] + T[i - 1] - 'A' + 1;

	ll q;
	cin >> q;

	repn(i, q) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;

		if ((sumS[b] - sumS[a - 1]) % 3 == (sumT[d] - sumT[c - 1]) % 3) { cout << "YES"; }
		else { cout << "NO"; }

		cout << endl;
	}

	system("PAUSE");

}



