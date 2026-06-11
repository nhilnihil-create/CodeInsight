#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

ll n, dt[1000005], cur;

int main()
{
	scanf("%lld",&n);
	dt[0] = 1;
	dt[1] = n;
	dt[2] = n*n % mod;
	cur = 2*n-1;
	for(ll i=3;i<=n;i++) {
		cur += dt[i-1] - dt[i-2] + dt[i-3] - 1;
		cur = (cur%mod+mod)%mod;
		dt[i] = (cur + (n-1)*(n-1)) % mod;
	}
	printf("%lld\n",dt[n]);
}
