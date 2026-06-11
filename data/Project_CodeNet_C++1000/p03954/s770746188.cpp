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

int p, n;

int modpow(int a, int b) {
	int ans = 1;
	while (b) {
		if (b & 1) ans *= a; ans %= p;
		a = a * a%p;
		b >>= 1;
	}
	return ans;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	int m = 2 * n - 1;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	int ok = -1, ng = 200010;
	while (ng - ok > 1) {
		int mid = (ok + ng) / 2;
		bool check = false;
		vector<int> l, r;
		for (int i = n - 1; i >= 0; i--) {
			if (a[i] >= mid) l.pb(1);
			else l.pb(0);
		}
		for (int i = n - 1; i < m; i++) {
			if (a[i] >= mid) r.pb(1);
			else r.pb(0);
		}
		bool flag = false;
		for (int i = 0; i < n - 1; i++) {
			if (l[i] == l[i + 1] || r[i] == r[i + 1]) {
				if (l[i]) check = true;
				else check = false;
				flag = true;
				break;
			}
		}
		if (!flag) {
			if (l[0] && n % 2 == 1 || !l[0] && n % 2 == 0) check = true;
		}
		if (check) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}