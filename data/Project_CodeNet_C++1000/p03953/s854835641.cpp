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
const ll MOD = 924844033;
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
ll d[100000];
ll mov[61][100000];
int main() {
	int n; cin >> n;
	ll x[100000];
	rep(i, n) {
		cin >> x[i];
	}
	rep(i, n - 1) {
		d[i] = x[i + 1] - x[i];
	}
	int m;ll k; cin >> m >> k;
	int a[100000];
	rep(j, n - 1) {
		mov[0][j] = j;
		mov[1][j] = j;
	}
	rep(i, m) {
		cin >> a[i]; a[i] -= 2; swap(mov[1][a[i]], mov[1][a[i] + 1]);
	}
	Rep(i, 2, 61) {
		rep(j, n-1) {
			mov[i][j] = mov[i - 1][mov[i - 1][j]];
		}
	}
	int cnt = 0;
	while (k) {
		cnt++;
		if (k % (ll)2) {
			ll nex[100000];
			rep(j, n - 1) {
				nex[j] = d[mov[cnt][j]];
			}
			rep(j, n - 1) {
				d[j] = nex[j];
			}
		}
		k /= (ll)2;
	}
	ll sum = x[0];
	cout << sum << endl;
	rep(i, n-1) {
		sum += d[i];
		cout << sum << endl;
	}
	return 0;
}