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
typedef pair<ll, P> PP;
typedef complex<double> com;
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
	vector<int> a(m);
	int cnt = 0;
	rep(i, m) {
		cin >> a[i];
		if (a[i] & 1) cnt++;
	}
	if (cnt == 0) {
		rep(i, m) cout << a[i] << ' ';
		cout << endl;
		cout << m + 1 << endl;
		cout << 1 << ' ';
		rep(i, m) {
			if (i == m - 1) cout << a[i] - 1 << ' ';
			else cout << a[i] << ' ';
		}
		cout << endl;
	}
	else if (cnt == 1) {
		vector<int> b;
		rep(i, m) if (a[i] & 1) b.pb(a[i]);
		rep(i, m) if (!(a[i] & 1)) b.pb(a[i]);
		rep(i, m) cout << b[i] << ' ';
		cout << endl;
		vector<int> ans;
		if (b[0] > 1) ans.pb(b[0] - 1);
		for (int i = 1; i < m; i++) ans.pb(b[i]);
		ans.pb(1);
		cout << ans.size() << endl;
		for (int i : ans) cout << i << ' ';
		cout << endl;
	}
	else if (cnt == 2) {
		vector<int> b;
		int idx = -1;
		rep(i, m) {
			if (a[i] & 1) {
				b.pb(a[i]); idx = i + 1; break;
			}
		}
		rep(i, m) if (!(a[i] & 1)) b.pb(a[i]);
		for (int i = idx; i < m; i++) if (a[i] & 1) b.pb(a[i]);
		rep(i, m) cout << b[i] << ' ';
		cout << endl;
		vector<int> ans;
		if (b[0] > 1) ans.pb(b[0] - 1);
		for (int i = 1; i < m - 1; i++) ans.pb(b[i]);
		ans.pb(b[m - 1] + 1);
		cout << ans.size() << endl;
		for (int i : ans) cout << i << ' ';
		cout << endl;
	}
	else cout << "Impossible" << endl;
}