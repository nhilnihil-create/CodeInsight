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

const int mxN = 203;
ll dis[mxN][mxN];
const ll INF = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, m, r;
	cin >> n >> m >> r;
	vector<ll> R(r);
	for (int i = 0; i < r; i++) {
		cin >> R[i];
		R[i]--;
	}

	sort(R.begin(), R.end());

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) dis[i][j] = 0;
			else dis[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		ll a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		dis[a][b] = c;
		dis[b][a] = c;
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}

	ll ans = INF;

	do {
		ll tmp = 0;
		for (int i = 0; i < r - 1; i++) {
			tmp += dis[R[i]][R[i + 1]];
		}
		chmin(ans, tmp);
	} while (next_permutation(R.begin(), R.end()));

	cout << ans << endl;
}