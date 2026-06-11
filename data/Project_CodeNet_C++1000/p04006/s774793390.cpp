#include<bits/stdc++.h>
using namespace std;
#define RI register int
typedef long long LL;
int n;LL X,ans,a[2005],mi[2005][2005];
int main()
{
	scanf("%d%lld",&n,&X);
	for(RI i=1;i<=n;++i) scanf("%lld",&a[i]);
	for(RI i=1;i<=n;++i) {
		mi[i][i]=a[i];
		for(RI j=i+1;j<=n;++j) mi[i][j]=min(mi[i][j-1],a[j]);
	}
	for(RI i=0;i<n;++i) {
		LL kl=1LL*i*X;
		for(RI j=1;j<=n;++j) {
			int t=j-i;
			if(t>=1) kl+=mi[t][j];
			else kl+=min(mi[1][j],mi[t+n][n]);
		}
		if(i==0||kl<ans) ans=kl;
	}
	printf("%lld\n",ans);
	return 0;
}