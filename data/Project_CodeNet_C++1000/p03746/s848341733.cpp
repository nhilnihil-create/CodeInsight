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
	vector<int> ans1, ans2;
	vector<bool> flag(n);
	int pl = a[0];
	flag[a[0]] = true;
	flag[b[0]] = true;
	bool check = true;
	while (check) {
		bool x = false;
		for (int i : graph[pl]) {
			if (!flag[i]) {
				pl = i;
				flag[i] = true;
				ans1.pb(i);
				x = true;
				break;
			}
		}
		if (!x) check = false;
	}
	pl = b[0];
	check = true;
	while (check) {
		bool x = false;
		for (int i : graph[pl]) {
			if (!flag[i]) {
				pl = i;
				flag[i] = true;
				ans2.pb(i);
				x = true;
				break;
			}
		}
		if (!x) check = false;
	}
	vector<int> ans;
	for (int i = ans1.size() - 1; i >= 0; i--) ans.pb(ans1[i]);
	ans.pb(a[0]); ans.pb(b[0]);
	for (int i = 0; i < ans2.size(); i++) ans.pb(ans2[i]);
	cout << ans.size() << endl;
	for (int i : ans) cout << i + 1 << ' ';
	cout << endl;
}