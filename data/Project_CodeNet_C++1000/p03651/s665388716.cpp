#define _USE_MATH_DEFINES
#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>
#include <map>
#include <list>
#include <iomanip>
#include <queue>
#include <cmath>
#include <numeric>
#define repl(i, l, r) for (ll i = l; i < r; i++)
#define rep(i, n) repl(i, 0, n)

using namespace std;
using ll = long long;
typedef pair<ll, ll> p;
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }
const long long mod = 1e9 + 7;
ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

vector<int> to[200005];
vector<int> ans;
ll gcd(ll a, ll b);

int main() {
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	bool ans = false;

	rep(i, n) {
		cin >> a[i];
		if (a[i] == k) ans = true;
	}

	sort(a.begin(), a.end());
	ll x;

	if (a[n - 1] > k) {
		x = a[0];
		rep(i, n - 1) {
			x = gcd(x, a[i + 1]);
			if (x == 1) {
				ans = true;
				break;
			}
		}
		if (k % x == 0) ans = true;
	}

	if (ans) cout << "POSSIBLE";
	else cout << "IMPOSSIBLE";

	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}