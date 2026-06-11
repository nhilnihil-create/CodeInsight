#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 5010
#define mod 1000000007
using namespace std;
ll ksm(ll a,ll b=mod-2)
{
	if(b==1) return a;
	if(b==0) return 1;
	ll q=ksm(a,b>>1);
	if(b&1) return q*q%mod*a%mod;
	return q*q%mod;
}
ll f[N][N];
char str[N];
int main()
{
	int n,m;
	scanf("%d%s",&n,str);
	m=strlen(str);
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		if(f[i][j]) (f[i+1][j+1]+=2*f[i][j])%=mod,(f[i+1][max(j-1,0)]+=f[i][j])%=mod;
	printf("%lld\n",f[n][m]*ksm(ksm(2,m))%mod);
	return 0;
}
