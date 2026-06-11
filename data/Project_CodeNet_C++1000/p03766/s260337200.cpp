#include<bits/stdc++.h>
using namespace std;

int s[1000001],f[1000001],t,n;
const int mod = 1e9+7;
main() {
	cin >> n;
	if (n == 1) {
		cout << 1;
		exit(0);
	}
	f[0] = 1;
	f[1] = n;
	s[0] = 1;
	s[1] = n+1;
	t = 1ll*(n-1)*(n-1)%mod;
	for (int i = 2; i <=n ;i++) {
	    f[i] = (1ll*t + (n - i + 1) + f[i-1] + (i >= 3 ? s[i-3] : 0))%mod;
	    s[i] = s[i-1] + f[i];
	    if (s[i] > mod) s[i] -= mod;
	}
	cout << f[n];
}