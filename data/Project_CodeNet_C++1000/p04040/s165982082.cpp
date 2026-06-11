#include<bits/stdc++.h>
using namespace std;
int h,w,a,b;
const int N=200010;
int fac[N],inv[N];
const int mod=1000000007;
int qp(int x,int k)
{
	int res=1;
	while(k)
	{
		if(k&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		k>>=1;
	}
	return res;
}
void init()
{
	fac[0]=inv[0]=1;
	for(int i=1;i<N;i++)
		fac[i]=1ll*fac[i-1]*i%mod;
	inv[N-1]=qp(fac[N-1],mod-2);
	for(int i=N-2;i>=1;i--)
		inv[i]=1ll*inv[i+1]*(i+1)%mod;
}
int C(int a,int b)
{
	if(a<b)return 0;
	return 1ll*fac[a]*inv[b]%mod*inv[a-b]%mod;
}
int ans;
int main()
{
	init();
	scanf("%d%d%d%d",&h,&w,&a,&b);
	ans=C(h-1+w-1,h-1);
	for(int i=1;i<=min(a,b);i++)
		ans=(ans-1ll*C(h-a+b-1,b-i)*C(w-b+a-1,a-i)%mod+mod)%mod;
	printf("%d\n",ans);
	return 0;
}
