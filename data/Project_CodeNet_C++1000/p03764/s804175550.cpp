#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

ll mod = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m;
	cin >> n >> m;
	vector<int> x(n);
	int xcnt = 0;
	int c = mod - n + 1;
	rep(i, n) {
		cin >> x[i];
		if (x[i] < 0) x[i] += mod;
		xcnt += c * x[i]; xcnt %= mod;
		c += 2; c %= mod;
	}
	vector<int> y(m);
	int ycnt = 0;
	c = mod - m + 1;
	rep(i, m) {
		cin >> y[i];
		if (y[i] < 0) y[i] += mod;
		ycnt += c * y[i]; ycnt %= mod;
		c += 2; c %= mod;
	}
	cout << xcnt * ycnt%mod << endl;
}