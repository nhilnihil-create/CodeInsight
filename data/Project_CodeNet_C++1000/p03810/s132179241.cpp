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
	if (sum % 2 == 0 && n % 2 == 0) cout << "Second" << endl;
	else if (sum % 2 == 0 && n % 2 == 1) cout << "First" << endl;
	else if (sum % 2 == 1 && n % 2 == 0) cout << "First" << endl;
	else {
		int cnt = 0; int p = -1;
		rep(i, n) {
			if (a[i] & 1) {
				cnt++; p = i;
			}
		}
		if (cnt > 1 || a[p] == 1) {
			cout << "Second" << endl;
		}
		else {
			int check = 0;
			while (a[p] != 1) {
				a[p]--; int g = a[0];
				rep(i, n) g = gcd(g, a[i]);
				rep(i, n) a[i] /= g;
				check ^= 1;
				if (a[p] % 2 == 0) {
					int cnts = 0; int q = -1;
					rep(i, n) {
						if (a[i] & 1) {
							cnts++; q = i;
						}
					}
					if (cnts > 1 || a[q] == 1) {
						int sums = 0;
						rep(i, n) sums += a[i];
						if (sums % 2 == check) cout << "First" << endl;
						else cout << "Second" << endl;
						return 0;
					}
					else {
						p = q;
					}
				}
			}
			if (check) cout << "First" << endl;
			else cout << "Second" << endl;
		}
	}
}