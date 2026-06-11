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

void dfs(int v, int p = -1) {
	for (int u : to[v]) {
		if (u == p) continue;
		ans[u] += ans[v];
		dfs(u, v);
	}
}

int main() {

	ll n, k;
	cin >> n;

	vector<ll> a(n);
	ll tot = 0;
	rep(i, n) {
		cin >> a[i];
		tot += a[i];
	}

	sort(a.begin(), a.end(), greater<>());

	ll i = 0, ans = 1;

	while (a[i] <= (tot - a[i]) * 2) {
		tot -= a[i];
		ans++;
		i++;
	}

	cout << ans;

	return 0;
}


ll gcd(ll a, ll b) {
	if (a % b == 0)return(b);
	else return(gcd(b, a % b));
}
ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}