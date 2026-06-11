#include<bits/stdc++.h>
#define ALL(c) (c).begin(),(c).end()
#define EACH(i,c) for(auto i=(c).begin();i!=(c).end();++i)
using namespace std;
#define int long long

const int MX = (int)2e+5;
const int MOD = (int)1e+9 + 7;
 
int powmod(int n, int k) {
	int res = 1;
	while(k > 0) {
		if(k & 1) res = (res * n) % MOD;
		n = (n * n) % MOD;
		k /= 2;
	}
	return res;
}
int invmod(int n) {
	return powmod(n, MOD - 2);
}
 
int fact[MX], invfact[MX];
 
int comb(int n, int m) {
	if(n < m) return 0;
	return (fact[n] * invfact[m] % MOD) * invfact[n - m] % MOD;
}

signed main(){
	fact[0] = invfact[0] = 1;
	for(int i = 1; i < MX; ++i) {
		fact[i] = (fact[i-1] * i) % MOD;
		invfact[i] = invmod(fact[i]);
	}
	int n;
	cin >> n;
	n++;
	vector<int> a(n);
	map<int, int> mp;
	int l = -1, r = -1;
	for(int i = 0; i < n; ++i) {
		cin >> a[i];
		if(mp.find(a[i]) != mp.end()) {
			l = mp[a[i]];
			r = i;
		} else {
			mp[a[i]] = i;
		}
	}
	if(l < 0 || r < 0) {
		return 1;
	}
	cout << n - 1 << endl;
	for(int i = 2; i <= n; ++i) {
		int res = 0;
		// without l,r
		if(i <= n - 2) {
			res = (res + comb(n - 2, i)) % MOD;
			// cerr << "<" <<  n - 2 << "," << i << endl;
		}
		// both of l and r
		res = (res + comb(n - 2, i - 2)) % MOD;
		// cerr << "<" << n - 1 << "," <<  i - 1 << endl;
		// either l or r
		if (i <= n - 1) {
			res = (res + comb(n - 2, i - 1) * 2) % MOD;
			res = (res - comb(l + (n - r - 1), i - 1) + MOD) % MOD;
			// cerr << "<" << n - 2 << "," <<  i - 1 << "," << l + n - r - 1 << "," << i - 1 << endl;
		}
		cout << res << endl;
	}
	return 0;
}
