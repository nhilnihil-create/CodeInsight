#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,popcnt")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 1<<17, mod = 1e9 + 7, i2 = (mod+1)/2;
ll solve(vector<int> a) {
	ll sm = 0, t;
	sort(all(a));
	for(int i = 0; i < a.size(); i++) {
		if(a[i] < 0) a[i] = (mod + a[i]%mod)%mod;
		sm = (sm + (a.size()-i)*1ll*a[i] + (i+1)*1ll*(mod-a[i]))%mod;
	}
	return sm;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;
	cout << solve(a)*solve(b)%mod;
	return 0;
}
