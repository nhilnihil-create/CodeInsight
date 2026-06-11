#include<bits/stdc++.h>
#define mo 1000000007
using namespace std;
int f[2000100],sum[2000100];
int getsum(int l,int r)
{
	if ((l>r)||(r<0)) return 0;
	l=max(l,0);
	if (l==0) return sum[r];
	return (sum[r]-sum[l-1]+mo)%mo;
}
int main()
{
	int n;scanf("%d",&n);
	f[0]=1;sum[0]=1;int ans=(long long)(n-1)*(n-1)%mo;
	for (int i=1;i<=2*n-1;i++)
	{
		f[i]=(f[i-1]+getsum(max(0,i-(n+1)),min(i-3,n-2)))%mo;
		if (i<n-1) ans=(ans+(long long)f[i]*(n-1)%mo*(n-1))%mo;
		if (i==n-1) ans=(ans+(long long)f[i]*(n-1))%mo;
		sum[i]=(sum[i-1]+f[i])%mo;
	}
	ans=(ans+f[2*n-1])%mo;
	printf("%d\n",ans);
}