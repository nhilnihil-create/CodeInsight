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
	int n, k; cin >> n >> k;
	int a[5000];
	rep(i, n) {
		cin >> a[i];
	}
	sort(a, a + n);
	n = lower_bound(a, a + n, k) - a;
	if (n == 0)cout << 0 << endl;
	else if (n == 1)cout << 1 << endl;
	else if (n == 2) {
		if (a[0] + a[1] < k)cout << 2 << endl;
		else cout << 0 << endl;
	}
	else {
		int le = 0; int ri = n;
		while (ri - le > 1) {
			int mid = (ri + le) / 2;
			bitset<5001> exi; exi[0] = 1;
			rep(i, n) {
				if (i == mid)continue;
				exi |= exi << a[i];
			}
			int chk;
			per(j, k) {
				if (exi[j]) {
					chk = j; break;
				}
			}
			if (chk + a[mid] >= k)ri = mid;
			else le = mid;
		}
		if (le == 0) {
			bitset<5001>exi; exi[0] = 1;
			Rep(i, 1, n) {
				exi |= exi << a[i];
			}
			int chk;
			per(j, k) {
				if (exi[j]) {
					chk = j; break;
				}
			}
			if (chk + a[0] >= k)cout << 0 << endl;
			else cout << 1 << endl;
		}
		else {
			cout << le + 1 << endl;
		}
	}
	return 0;
}