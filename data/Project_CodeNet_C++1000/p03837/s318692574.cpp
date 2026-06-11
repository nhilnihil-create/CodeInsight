#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <math.h>
#include <deque>
#include <queue>
#include <map>
#include <iterator>
#include <set>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Pll = pair<ll, ll>;
#define debug(var)  do{std::cout << #var << " : ";view(var);}while(0)
template<typename T> void view(T e) { std::cout << e << std::endl; }
template<typename T> void view(const std::vector<T>& v) { for (const auto& e : v) { std::cout << e << " "; } std::cout << std::endl; }
template<typename T> void view(const std::vector<std::vector<T> >& vv) { for (const auto& v : vv) { view(v); } }
template<class T>bool chmax(T& a, const T& b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

const int mxN = 103;
const int mxM = 1009;
const int INF = 1e9;
int a[mxM], b[mxM], c[mxM];
int dist[mxN][mxN];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i] >> c[i];
		a[i]--, b[i]--;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
		dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int ans = m;
	for (int i = 0; i < m; i++) {
		bool ok = false;
		for (int j = 0; j < n; j++) {
			if (dist[j][a[i]] + c[i] == dist[j][b[i]]) ok = true;
		}
		if (ok) ans--;
	}

	cout << ans << endl;
}