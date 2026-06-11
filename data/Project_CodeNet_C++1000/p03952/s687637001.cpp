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
	ll N, x;
	cin >> N >> x;

	if (x == 1 || x == 2 * N - 1) { cout << "No"; }

	else {
		cout << "Yes"<<endl;

		if (N == 2) {
			repn(i, 2 * N - 1) {
				cout << i << endl;
			}
		}

		else if (x < 2 * N - 2) {
			vector<ll> a(2 * N - 4);
			repn(i, 2 * N - 5) {
				if (i < x - 1) { a[i] = i; }
				else { a[i] = i + 4; }
			}

			repn(i, N - 3) { cout << a[i] << endl; }
			cout << x + 1 << endl;
			cout << x - 1 << endl;
			cout << x << endl;
			cout << x + 2 << endl;
			repn(i, N - 2) { cout << a[N-3+i] << endl; }
		}

		else {
			repn(i, N - 3) { cout << i << endl; }
			cout << 2 * N - 3 << endl;
			cout << 2 * N - 1 << endl;
			cout << 2 * N - 2 << endl;
			cout << 2 * N - 4 << endl;
			repn(i, N - 2) { cout << N - 3 + i << endl; }
		}
	}

	system("PAUSE");
}
