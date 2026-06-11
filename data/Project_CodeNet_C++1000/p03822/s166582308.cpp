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
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P> PP;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

vector<vector<int>> tree(100010, vector<int>());

int ans(int n, int p) {
	vector<int> vec;
	for (int i : tree[n]) {
		if (i == p) continue;
		vec.push_back(ans(i, n));
	}
	sort(all(vec));
	int res = 0;
	for (int i : vec) {
		res = max(i, res) + 1;
	}
	return res;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		a[i]--;
		tree[a[i]].pb(i);
	}
	cout << ans(0, -1) << endl;
}