//#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

#define rep(i,n) for(ll (i)=0;(i)<(ll)(n);(i)++)
#define all(x) (x).begin(),(x).end()
#define MOD 1000000007LL
#define INF (1LL<<60LL)
#define int long long
typedef long long ll;

using namespace std;



signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ll n; cin >> n;
	vector<ll> v(n);
	rep(i, n)cin >> v[i];
	sort(all(v));
	ll k = 0;
	rep(i, n - 1) {
		if (v[i] == v[i + 1]) k++;
	}
	if (k % 2 == 1)k++;
	cout << n - k << endl;
}