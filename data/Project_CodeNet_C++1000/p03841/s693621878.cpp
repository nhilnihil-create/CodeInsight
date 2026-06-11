#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll MOD = (1e+9) + 7;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-11;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
typedef pair<ld, ld> LDP;
typedef pair<P, int> PP;
int out[250000]; int used[250000] = {};
int main() {
	int n;
	cin >> n;
	int le = 0;
	int ri = n * n - 1;
	P x[500];
	rep(i, n) {
		cin >> x[i].first; x[i].second = i + 1; x[i].first--;
	}
	sort(x, x + n);
	rep(i, n) {
		used[x[i].first] = 1;
		out[x[i].first] = x[i].second;
	}
	bool f = true;
	rep(i, n) {
		int cnt = 0;
		while (cnt < x[i].second - 1&&le<n*n) {
			if (used[le]) {
				le++; continue;
			}
			out[le] = x[i].second; used[le] = 1; le++; cnt++;
		}
		if (le > x[i].first) {
			f = false; break;
		}
	}
	per(i, n) {
		int cnt = 0;
		while (cnt < n - x[i].second&&ri >= 0) {
			if (used[ri]) {
				ri--; continue;
			}
			out[ri] = x[i].second; used[ri] = 1; ri--; cnt++;
		}
		if (ri < x[i].first) {
			f = false; break;
		}
	}
	if (!f)cout << "No" << endl;
	else {
		cout << "Yes" << endl;
		rep(i, n*n) {
			if (i > 0)cout << " ";
			cout << out[i];
		}
		cout << endl;
	}
	return 0;
}