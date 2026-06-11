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
const ll MOD = 998244353;
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
	ll n; cin >> n;
	int chk = 0;
	rep(i, 42) {
		ll k = (ll)1 << i; k--;
		if (k <= n)chk = i;
	}
	n = n - ((ll)1 << chk) + 1;
	vector<int> v;
	rep(i, chk) {
		v.push_back(i + 1);
	}
	rep(i, chk) {
		v.push_back(i + 1);
	}
	int now = chk+1;
	per(i, 42) {
		if (n&((ll)1 << i)) {
			v.insert(v.begin() + i, now); v.push_back(now);
			now++;
		}
	}
	int len = v.size();
	cout << len << endl;
	rep(i, len) {
		if (i > 0)cout << " ";
		cout << v[i];
	}
	cout << endl;
	return 0;
}