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

vector<vector<int>> graph(100010, vector<int>());
int n, k, ans;

int dfs(int n) {
	int res = -1;
	for (int i : graph[n]) {
		int d = dfs(i);
		if (d < k - 1 || d == k - 1 && n == 0) chmax(res, d);
		else ans++;
	}
	res++;
	return res;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	cin >> n >> k;
	rep(i, n) {
		int a;
		cin >> a;
		a--;
		if (i == 0 && a != 0) ans++;
		if (i == 0) continue;
		graph[a].pb(i);
	}
	dfs(0);
	cout << ans << endl;
}