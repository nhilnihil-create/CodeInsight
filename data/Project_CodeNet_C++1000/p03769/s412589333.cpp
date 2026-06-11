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

	int n;
	cin >> n;
	n++;
	vector<bool> s;
	while (n > 2) {
		if (n & 1) {
			s.pb(true);
			n--;
		}
		else {
			s.pb(false);
			n >>= 1;
		}
	}
	vector<int> l, r;
	int cnt = 1;
	r.pb(cnt);
	int k = s.size();
	for (int i = k - 1; i >= 0; i--) {
		cnt++;
		if (s[i]) l.pb(cnt);
		else r.pb(cnt);
	}
	cout << 2 * cnt << endl;
	rep(i, k + 1) cout << i + 1 << ' ';
	if (l.size()) for (int i = l.size() - 1; i >= 0; i--) cout << l[i] << ' ';
	rep(i, r.size()) cout << r[i] << ' ';
	cout << endl;
}