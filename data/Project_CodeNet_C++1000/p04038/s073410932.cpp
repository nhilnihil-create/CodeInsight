#include <iostream>
#define MOD 1000000007
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 2005;
int f[MAXN][MAXN],n,k;
inline int ksm(int x,int k)
{
	int ret=1;
	while(k){
		if(k&1)ret=(long long)ret*x%MOD;
		x=(long long)x*x%MOD;
		k>>=1;
	}
	return ret;
}
int fac[MAXN*MAXN],inv[MAXN*MAXN];
inline void init(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;++i)
		fac[i]=(long long)fac[i-1]*i%MOD;
	inv[n]=ksm(fac[n],MOD-2);
	inv[0]=1;
	for(int i=n-1;i;--i)
		inv[i]=(long long)inv[i+1]*(i+1)%MOD;
}
inline int C(int n,int m)
{
	return (long long)fac[m]*inv[m-n]%MOD*inv[n]%MOD;
}
inline void add(int &x,int a)
{
	x+=a;
	if(x>=MOD)x-=MOD;
}
int main()
{
	scanf("%d%d",&n,&k);
	if(k==1){puts("1");return 0;}
	init(n*k);
	f[0][0]=1;
	for(int i=0;i<=n;++i)
		for(int j=i;j<=n;++j){
			if(i>0)add(f[i][j],f[i-1][j]);
			if(i<j)add(f[i][j],(long long)f[i][j-1]*C(k-2,j*(k-1)-1+i)%MOD);
		}
	cout<<(long long)f[n][n]*fac[n]%MOD<<endl;
	return 0;
}
