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
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#define all(a) a.begin(),a.end()
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define pb push_back
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef long double ld;
typedef complex<ld> com;
constexpr int inf = 1000000000;
constexpr ll INF = 1000000000000000000;
constexpr ld EPS = 1e-12;
constexpr ld PI = 3.141592653589793238;
template<class T, class U> inline bool chmax(T &a, const U &b) { if (a < b) { a = b; return true; } return false; }
template<class T, class U> inline bool chmin(T &a, const U &b) { if (a > b) { a = b; return true; } return false; }

struct edge {
	int from, to, cost;
};

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	int n, m;
	cin >> n >> m;
	vector<edge> graph;
	rep(i, m) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		graph.pb({ a,b,-c });
	}
	vector<ll> dis(n, INF);
	vector<bool> loop(n);
	dis[0] = 0;
	rep(i, n) {
		for (edge e : graph) {
			if (chmin(dis[e.to], dis[e.from] + e.cost) && i == n - 1) loop[e.to] = true;
		}
	}
	queue<int> que1, que2;
	vector<bool> vis1(n), vis2(n);
	que1.push(0); que2.push(n - 1);
	vis1[0] = true; vis2[n - 1] = true;
	while (!que1.empty()) {
		int q = que1.front(); que1.pop();
		for (edge e : graph) {
			if (e.from == q && !vis1[e.to]) {
				vis1[e.to] = true;
				que1.push(e.to);
			}
		}
	}
	while (!que2.empty()) {
		int q = que2.front(); que2.pop();
		for (edge e : graph) {
			if (e.to == q && !vis2[e.from]) {
				vis2[e.from] = true;
				que1.push(e.from);
			}
		}
	}
	rep(i, n) {
		if (loop[i] && vis1[i] && vis2[i]) {
			cout << "inf\n";
			return 0;
		}
	}
	cout << -dis[n - 1] << '\n';
}