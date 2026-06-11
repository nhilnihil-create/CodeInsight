/* it was worth becoming a chemist */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ld;
typedef unsigned int uni;
typedef unsigned long long unll;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef pair<long long, int> pli;
typedef pair<int, long long> pil;
typedef vector<int> vi;
typedef vector<long long> vll;

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)x.size()
#define NAME "puts"
#define F first
#define S second

const ll INF = 1e18;
const int inf = 1e9;
const int mod = 1e9 + 7;
const db EPS = (db) 1e-9;
const db pi = acos(-1.0);
const int MAXN = 1e5 + 5;

ll f(ll n, ll x) {
	if (n % x == 0) {
		return 2 * n - x;
	}
	else {
		return (n / x) * (2 * x) + f(x, n % x);
	}
}

ll n, x;

int main() {

    cin >> n >> x;
	cout << f(n - x, x) + n;

	return 0;
}
