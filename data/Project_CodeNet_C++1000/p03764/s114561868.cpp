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
const ll MOD = (1e+9)+7;
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
int main() {
	int n, m; cin >> n >> m;
	ll hsum = 0; ll wsum = 0;
	ll x[100000], y[100000];
	rep(i, n) {
		cin >> x[i];
	}
	rep(i, m) {
		cin >> y[i];
	}
	rep(i, n - 1) {
		hsum = (hsum + (((ll)(i + 1))*((ll)(n - 1 - i)) % MOD)*(x[i + 1] - x[i]) % MOD) % MOD;
	}
	rep(i, m - 1) {
		wsum = (wsum + (((ll)(i + 1))*((ll)(m - 1 - i)) % MOD)*(y[i + 1] - y[i]) % MOD) % MOD;
	}
	cout << hsum * wsum%MOD << endl;
	return 0;
}