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


signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	//modcalc();

	int n;
	cin >> n;
	int sum = 0;
	vector<int> a(n);
	rep(i, n) {
		cin >> a[i];
		sum += a[i];
	}
	int use = n * (n + 1) / 2;
	if (sum%use) {
		cout << "NO" << endl;
		return 0;
	}
	sum /= use;
	int s = 0;
	int cnt = 0;
	rep(i, n) {
		int x = a[i] + sum;
		int y = a[(i + 1) % n];
		if ((x - y) % n || x < y) {
			cout << "NO" << endl;
			return 0;
		}
		cnt = (x - y) / n;
		s += cnt;
	}
	cout << (sum == s ? "YES" : "NO") << endl;
}