#include <bits/stdc++.h>
#define LL long long
#define MOD 1000000007
using namespace std;
int N,K;
LL fac[5000010],inv[5000010],ifac[5000010],d[2010][2010];
int main()
{
	cin>>N>>K;
	if(K==1)
	{
		cout<<1<<endl;
		return 0;
	}
	fac[0]=inv[0]=ifac[0]=fac[1]=inv[1]=ifac[1]=1;
	for(int i=2;i<=5000000;i++)
	{
		fac[i]=(fac[i-1]*i)%MOD;
		inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
		ifac[i]=(ifac[i-1]*inv[i])%MOD;
	}
	d[0][1]=1;
	for(int i=2;i<=N;i++)
	{
		d[0][i]=d[0][i-1]*(fac[i*(K-1)-1]*ifac[K-2]%MOD*ifac[(i-1)*(K-1)]%MOD)%MOD;
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=i;j<=N;j++)
		{
			d[i][j]=(d[i-1][j]+d[i][j-1]*(fac[i+j*(K-1)-1]*ifac[K-2]%MOD*ifac[i+(j-1)*(K-1)]%MOD))%MOD;
// 			cout<<i<<' '<<j<<' '<<d[i][j]<<endl;
		}
	}
	cout<<(d[N][N]*fac[N])%MOD<<endl;
	return 0;
}