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
#include <complex>
#include <time.h>
#define int long long
#define endl '\n'
#define INF 1000000000000000000
#define EPS 1e-10
#define PI 3.141592653589793238
#define all(a) a.begin(),a.end()
#define rep(i, n) for (int i = 0; i < (n); i++)
#define pb push_back
#define double long double
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<P, ll> PP;
typedef complex<double> com;
template<class T, class S> bool chmax(T &a, const S &b) { if (a < b) { a = b; return 1; } return 0; }
template<class T, class S> bool chmin(T &a, const S &b) { if (a > b) { a = b; return 1; } return 0; }
ll gcd(ll n, ll m) { return (m ? gcd(m, n%m) : n); }
ll lcm(ll n, ll m) { return n / gcd(n, m)*m; }

vector<vector<int>> graph(2010, vector<int>());

void dfs(int n, int p, int d, vector<int> &dis) {
	dis[n] = d;
	for (int i : graph[n]) {
		if (i == p) continue;
		dfs(i, n, d + 1, dis);
	}
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n, k;
	cin >> n >> k;
	vector<int> x(n - 1), y(n - 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
		x[i] = a; y[i] = b;
	}
	int ans = 0;
	if (k % 2 == 0) {
		k /= 2;
		rep(i, n) {
			int cnt = 0;
			vector<int> dis(n);
			dfs(i, -1, 0, dis);
			rep(j, n) {
				if (dis[j] <= k) cnt++;
			}
			chmax(ans, cnt);
		}
	}
	else {
		k /= 2;
		rep(i, n - 1) {
			int cnt = 0;
			vector<int> dis(n);
			dfs(x[i], y[i], 0, dis);
			dfs(y[i], x[i], 0, dis);
			rep(j, n) {
				if (dis[j] <= k) cnt++;
			}
			chmax(ans, cnt);
		}
	}
	cout << n - ans << endl;
}