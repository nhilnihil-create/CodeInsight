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


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, m;
	cin >> n >> m;
	vector<int> a(m), b(m);
	vector<vector<int>> graph(n, vector<int>());
	rep(i, m) {
		cin >> a[i] >> b[i];
		a[i]--; b[i]--;
		graph[a[i]].pb(b[i]);
		graph[b[i]].pb(a[i]);
	}
	int q;
	cin >> q;
	vector<int> v(q), d(q), c(q);
	rep(i, q) cin >> v[i] >> d[i] >> c[i];
	vector<int> ans(n);
	vector<int> cnt(n, -1);
	queue<P> que;
	for (int i = q - 1; i >= 0; i--) {
		vector<bool> flag(n);
		que.push(P(v[i] - 1, 0));
		while (!que.empty()) {
			P p = que.front(); que.pop();
			if (!chmax(cnt[p.first], d[i] - p.second)) continue;
			flag[p.first] = true;
			if(!ans[p.first]) ans[p.first] = c[i];
			if (p.second == d[i]) continue;
			for (int i : graph[p.first]) {
				if (!flag[i]) que.push(P(i, p.second + 1));
			}
		}
	}
	for (int i : ans) cout << i << endl;
}