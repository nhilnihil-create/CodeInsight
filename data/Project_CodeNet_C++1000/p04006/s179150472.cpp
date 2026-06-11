#include <bits/stdc++.h>
long long ans;
int a[2005],x,n,f[2005][2005];
using std::min;
signed main(){
	scanf("%d%d",&n,&x);
	for (int i=0;i<n;i++) scanf("%d",&a[i]);
	memset(f,0x3f,sizeof(f));
	for (int i=0;i<n;i++){
		f[i][0]=a[i];
		for (int j=1;j<=n;j++) 
			f[i][j]=std::min(f[i][j-1],a[(i-j+n)%n]);
	}
	ans=10000000000000000;
	for (int i=0;i<n;i++){
		long long sum=0;
		for (int j=0;j<n;j++) sum=sum+f[j][i];
		ans=min(ans,sum+1ll*i*x);
	}
	printf("%lld\n",ans);
}