#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int n,k,now,ans;
int a[N],sum[N],sum2[N];
signed main(){
	scanf("%lld%lld",&n,&k);
	for (register int i=1; i<=n; ++i) 
	{
		scanf("%lld",&a[i]);
		sum[i]=sum[i-1]+a[i]; 
		if (a[i]>0) 
		{
			now+=a[i];
			sum2[i]=sum2[i-1]+a[i];
		}
		else sum2[i]=sum2[i-1];
	}
	for (register int i=k; i<=n; ++i) 
	if (sum[i]-sum[i-k]>0) ans=max(ans,now-(sum2[i]-sum2[i-k])+(sum[i]-sum[i-k]));
	else ans=max(ans,now-(sum2[i]-sum2[i-k]));
	printf("%lld\n",ans);
return 0;	
}