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

vector<int> perm_comp(vector<int> a, vector<int> b) {
	int n = b.size();
	vector<int> res(n);
	rep(i, n) res[i] = a[b[i]];
	return res;
}

vector<int> perm_pow(vector<int> base, int k) {
	int n = base.size();
	vector<int> ans(n);
	rep(i, n) ans[i] = i;
	while (k) {
		if (k & 1) ans = perm_comp(ans, base);
		base = perm_comp(base, base);
		k >>= 1;
	}
	return ans;
}


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	vector<int> x(n);
	rep(i, n) cin >> x[i];
	int m, k;
	cin >> m >> k;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	vector<int> d(n - 1);
	rep(i, n - 1) d[i] = x[i + 1] - x[i];
	vector<int> ans(n - 1);
	rep(i, n - 1) ans[i] = i;
	rep(i, m) swap(ans[a[i] - 2], ans[a[i] - 1]);
	ans = perm_pow(ans, k);
	int res = x[0];
	cout << res << endl;
	rep(i, n - 1) {
		res += d[ans[i]];
		cout << res << endl;
	}
}