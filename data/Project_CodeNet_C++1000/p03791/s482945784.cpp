#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n, a[100005], cs, ans = 1;

int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++) {
		if(2*cs+1 <= a[i]) cs++;
		else ans = (ans * (cs+1)) % mod;
	}
	for(;cs;cs--) ans = (ans * cs) % mod;
	printf("%lld\n",ans);
}
