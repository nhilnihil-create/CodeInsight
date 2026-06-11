#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <bitset>
#include <set>
const int maxlongint=2147483647;
const long long mo=1e9+7;	
const int N=2005;
using namespace std;
int n,k;
long long f[N][N],jc[N*N],ny[N*N],ans;
long long poww(long long x,int y)
{
	long long s=1;
	for(;y;y>>=1,x=x*x%mo)
		if(y&1) s=s*x%mo;
	return s;
}
long long C(int m,int n)
{
	if(n>m) return 0;
	return jc[m]*ny[n]%mo*ny[m-n]%mo;
}
int main()
{
	//freopen("agc002f.in","r",stdin);
	//freopen("agc002f.out","w",stdout);
	scanf("%d%d",&n,&k);
	if(k<=1)
	{
		printf("1\n");
		return 0;
	}
	jc[0]=ny[0]=1;
	for(int i=1;i<=n*k;i++) jc[i]=jc[i-1]*i%mo,ny[i]=poww(jc[i],mo-2);
	f[0][0]=1;
	for(int i=1;i<=n;i++)
		for(int j=i;j>=0;j--)
			f[i][j]=(f[i][j]+f[i-1][j-1]*C(k*i-j-1,k-2)%mo+f[i][j+1])%mo;
	printf("%lld",f[n][0]*jc[n]%mo);
}