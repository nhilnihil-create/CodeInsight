#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 1e9+7;

int x[100004], y[100004];
int sx[100004], sy[100004];
signed main(){
	int n, m, xx, yy;
	scanf("%lld%lld", &n, &m);
	for(int i = 1;i <= n;i++)scanf("%lld", &x[i]);
	for(int i = 1;i <= m;i++)scanf("%lld", &y[i]);
	xx = x[1], yy = y[1];
	if(xx < 0)for(int i = 1;i <= n;i++)x[i] = (x[i]-xx)%mod;
	if(yy < 0)for(int i = 1;i <= m;i++)y[i] = (y[i]-yy)%mod;
	
	for(int i = 1;i <= n;i++)sx[i] = (sx[i-1]+x[i])%mod;
	for(int i = 1;i <= m;i++)sy[i] = (sy[i-1]+y[i])%mod;
	
	int s = 0, b = 0;
	for(int i = 1;i < m;i++){
		int t = (2*mod+(sy[m]-sy[i])-((m-i)*y[i])%mod)%mod;
		b = (b+t)%mod;
	}
	for(int i = 1;i < n;i++){
		int a = (2*mod+(sx[n]-sx[i])-((n-i)*x[i])%mod)%mod;
		s = (s+a*b)%mod;
	}
	printf("%lld\n", s);
	return 0;
}
