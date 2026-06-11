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

ll mod = 1000000007;

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	string s, t;
	cin >> s >> t;
	int n = s.size(); int m = t.size();
	vector<int> scnt(n + 1); 
	vector<int> tcnt(m + 1);
	for (int i = 0; i < n; i++) {
		if (s[i] == 'A') scnt[i + 1] = scnt[i] + 1;
		else scnt[i + 1] = scnt[i];
	}
	for (int i = 0; i < m; i++) {
		if (t[i] == 'A') tcnt[i + 1] = tcnt[i] + 1;
		else tcnt[i + 1] = tcnt[i];
	}
	int q; cin >> q;
	rep(_, q) {
		int ls, rs, lt, rt;
		cin >> ls >> rs >> lt >> rt;
		int as = scnt[rs] - scnt[ls - 1];
		int bs = rs - ls + 1 - as;
		int at = tcnt[rt] - tcnt[lt - 1];
		int bt = rt - lt + 1 - at;
		if ((as + bt) % 3 == (at + bs) % 3) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
}