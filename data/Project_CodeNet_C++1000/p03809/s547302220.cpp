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
vector<int> cnt(100010), deg(100010);
bool ans = true;

int dfs(int n, int p) {
	int sum = 0;
	int mx = 0;
	int check = 0;
	for (int i : graph[n]) {
		if (i == p) continue;
		check++;
		int d = dfs(i, n);
		sum += d;
		chmax(mx, d);
	}
	if (check == 0) return cnt[n];
	if (check == 1 && sum != cnt[n] || sum < cnt[n] || sum > 2 * cnt[n] || mx > cnt[n]) ans = false;
	return 2 * cnt[n] - sum;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	rep(i, n) cin >> cnt[i];
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].pb(b);
		graph[b].pb(a);
		deg[a]++; deg[b]++;
	}
	int d = INF; int p = -1;
	rep(i, n) if (deg[i] == 1) p = i;
	if (dfs(p, -1) != cnt[p]) ans = false;
	cout << (ans ? "YES" : "NO") << endl;
}