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
#define fi first
#define se second
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
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> cnt(3 * m);
	int ans = 0;
	rep(i, n - 1) {
		int x = a[i]; int y = a[i + 1];
		x--; y--;
		if (x > y) y += m;
		ans += y - x;
		cnt[x + 2]++; cnt[y + 1] += x - y; cnt[y + 2] += y - x - 1;
	}
	vector<int> sum1(3 * m), sum2(3 * m);
	sum1[0] = cnt[0]; sum2[0] = cnt[0];
	for (int i = 1; i < 3 * m; i++) sum1[i] = sum1[i - 1] + cnt[i];
	for (int i = 1; i < 3 * m; i++) sum2[i] = sum2[i - 1] + sum1[i];
	int res = 0;
	rep(i, m) chmax(res, sum2[i] + sum2[i + m] + sum2[i + 2 * m]);
	//rep(i, 3 * m) cout << sum2[i] << ' '; cout << endl;
	cout << ans - res << endl;
}