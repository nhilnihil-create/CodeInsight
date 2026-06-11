#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 2e3 + 5;
ll sum=1e16+5;
ll a[maxn];
ll b[maxn][maxn];//b[i][j],i表示获得ai的代价,j表示进行j次第二种操作 
int main()
{
	ll n,x;
	scanf("%lld %lld",&n,&x);
	for(ll i = 1;i <= n; i++)scanf("%lld", &a[i]);
	for(ll i = 1;i <= n; i++)
	{
		b[i][0] = a[i];
		for(ll j = 1;j <= n - 1;j++)
		{
			ll pos = i - j;
			if(pos <= 0)pos = n + pos;
			b[i][j] = min(b[i][j - 1],a[pos]);	
		 } 
	}
	for(ll i = 0;i <= n - 1;i++)
	{
		ll ans = 0;
		for(ll j = 1;j <= n;j++)
		{
			ans += b[j][i];
		}
		sum=min(sum,ans + x * i);
		
		
	}
	printf("%lld\n",sum);
	return 0;
 } 