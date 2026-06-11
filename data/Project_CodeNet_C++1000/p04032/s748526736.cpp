#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
const int INF = 1e9 + 100;
const lli INF64 = (1LL << 61) + 100;
const lli MOD = 1000*1000*1000+7;
lli bpow(lli a, lli b) {
	if(b == 0) return 1;
	if(b == 1) return a % MOD;
	lli r = bpow(a, b >> 1);
	r = (r * r) % MOD;
	return (r * (((b&1)?a:1) % MOD)) % MOD;
}
lli multInverse(lli a) {
	return bpow(a, MOD - 2);
}
lli modMult(lli a, lli b) {
	return (a * b) % MOD;
}
lli modSub(lli a, lli b) {
	a += MOD;
	lli r = a - b;
	if(r >= MOD) return r - MOD;
	return r;
}
lli modAdd(lli a, lli b) {
	lli r = a + b;
	if(r >= MOD) return r - MOD;
	return r;
}
signed main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//	freopen("input.txt", "r", stdin);
	//	freopen("output.txt", "w", stdout);
	string s;
	cin >> s;
	int n = s.length();
	s = "#" + s;
	for(int i = 1; i <= n; i++) {
		if(s[i-1] == s[i]) {
			cout << (i-1) << " " << i << "\n";
			return 0;
		}	
		if(i > 1 && s[i-2] == s[i]) {
			cout << (i-2) << " " << i << "\n";
			return 0;
		}
	}
	cout << "-1 -1\n";
	return 0;
}