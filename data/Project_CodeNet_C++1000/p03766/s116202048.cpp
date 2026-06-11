#include <bits/stdc++.h>
using namespace std;

long long n, mod = 1e9+7, ans;
long long s, a[1000010];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n;
	if(n == 1){
		cout << 1 << "\n";
		return 0;
	}
	a[0] = a[1] = a[2] = s = 1;
	for(int i=3; i<n; ++i){
		a[i] = a[i-1] + s;
		a[i] %= mod;
		s += a[i-2];
		s %= mod;
	}
	for(int i=1; i<n; ++i){
		long long t = a[i] * (n-1) % mod;
		if(i < n-1){
			t *= n-1;
			t %= mod;
		}
		ans += t;
		ans %= mod;
//		cout << i << " " << ans << "\n";
	}
	for(int i=0; i<=n-2; ++i){
		ans += (n-1) * a[i] % mod;
		ans %= mod;
	}
	ans += (1 + (n-1) * (n-1)) % mod;
	ans %= mod;
	cout << ans << "\n";
}