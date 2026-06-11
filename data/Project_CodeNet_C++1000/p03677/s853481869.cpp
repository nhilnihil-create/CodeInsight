#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,Ans,a[100005],b,h[100005],ans,sum[200005],tot[100005];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n-1;i++)
	{
		int l=a[i],r=a[i+1];
		if(l>r) r+=m;
		ans+=r-l;
		l+=2;
		//printf("l=%d r=%d\n",l,r);
		if(l>r) continue;
		sum[l]++,sum[r+1]-=r-l+2,sum[r+2]+=r-l+1;
	}
	for(int i=1;i<=m+m;i++) sum[i]+=sum[i-1];
	//for(int i=1;i<=m+m;i++) printf("sum(%d)=%d\n",i,sum[i]);
	for(int i=1;i<=m+m;i++) sum[i]+=sum[i-1];
	//for(int i=1;i<=m+m;i++) printf("sum(%d)=%d\n",i,sum[i]);
	for(int i=1;i<=m;i++) tot[i]=sum[i]+sum[i+m];
	Ans=ans;
	//for(int i=1;i<=m;i++) printf("tot(%d)=%d\n",i,tot[i]);
	for(int i=1;i<=m;i++) Ans=min(Ans,ans-tot[i]);
	printf("%lld\n",Ans);
	return 0;
}