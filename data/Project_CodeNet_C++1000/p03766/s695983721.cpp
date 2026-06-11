//#include"pch.h"
#include<iostream>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define N 1000010
ll f[N],cs[N],n;
int main() {
	cin >> n;
	f[0] = 1;
	cs[0] = 1;
	for (int i = 1;i <= n;i++) {
		f[i] = cs[i - 1];
		if (i - 2 >= 0)f[i] -= f[i - 2];
		cs[i] = (cs[i - 1] + f[i]) % mod;
		//cout << f[i] << endl;
	}
	ll ans = f[n]+f[n-1]*(n-1);
	for (ll i = 0;i < n - 1;i++) {
		ans = (ans + f[i] * ((n - 1)*(n - 1)%mod+(i+1)))%mod;
		//cout << (n - 1)*(n - 1) + (n - i - 1) << endl;
	}
	ans %= mod;
	if (ans < 0)ans += mod;
	cout << ans << endl;
	return 0;
}