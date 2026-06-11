#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll mod = 1e9 + 7;

ll S1[1010101], S2[1010101];
ll n, ans;

int main()
{
	ll i, x;
	
	scanf("%lld", &n);
	
	ans = 1;
	
	for(i=0; i<n; i++){
		if(i >= 3) x = ((i - 2) * S1[i - 3] - S2[i - 3] + mod + 1) % mod;
		else x = 1;
		
		if(i < n) ans = (ans + x * (n - 1)) % mod;
		if(i < n - 1) ans = (ans + x * (n - 1) % mod * (n - 1)) % mod;
		
		S1[i] = (S1[i - 1] + x) % mod;
		S2[i] = (S2[i - 1] + x * i) % mod;
	}
	
	printf("%lld\n", ans);
	
	return 0;
}