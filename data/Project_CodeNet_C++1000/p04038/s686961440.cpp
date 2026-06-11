#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
inline int add(int a,int b)
{a+=b;return a>=MOD?a-MOD:a;}
inline int mul(int a,int b)
{return 1LL*a*b%MOD;}
int ksm(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=mul(a,a))
		if(b&1)ans=mul(ans,a);
	return ans;
}
const int Q=2005;
int fac[Q*Q],ifac[Q*Q];
int F(int n,int m)
{return mul(fac[n+m-1],mul(ifac[m-1],ifac[n]));}
void Init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=mul(fac[i-1],i);
	ifac[n]=ksm(fac[n],MOD-2);
	for(int i=n;i;--i)
		ifac[i-1]=mul(ifac[i],i);
}
int f[Q][Q];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k==1)return 0&puts("1");
	Init(n*k);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;--j)
			f[i][j]=add(f[i][j+1],j==0?0:mul(f[i-1][j-1],mul(n-i+1,F(k-2,(i-1)*k-(j-1)+1))));
	printf("%d\n",f[n][0]);
	return 0;
}