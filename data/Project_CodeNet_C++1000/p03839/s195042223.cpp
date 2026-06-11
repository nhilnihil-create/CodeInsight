#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN=1e5+7;

int n,k;
ll sum[MAXN],sum2[MAXN],a[MAXN],ans;

int main() {
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++) {
		scanf("%lld",&a[i]);
		if(a[i]>0) sum[i]+=a[i];
	}
	for(int i=1;i<=n;i++) {
		sum[i]+=sum[i-1];
		sum2[i]=sum2[i-1]+a[i];
	}
	
	for(int i=k;i<=n;i++)
		ans=max(ans,sum[n]-sum[i]+sum[i-k]+max(0ll,sum2[i]-sum2[i-k]));
	printf("%lld",ans);
}