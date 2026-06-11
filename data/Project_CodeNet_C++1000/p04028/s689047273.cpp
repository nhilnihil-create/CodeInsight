#include<bits/stdc++.h>
#define N (5009)
#define MOD (1000000007)
using namespace std;

int n,m,f[N][N];
char s[N];

int Qpow(int a,int b)
{
	int ans=1;
	while (b)
	{
		if (b&1) ans=1ll*ans*a%MOD;
		a=1ll*a*a%MOD; b>>=1;
	}
	return ans;
}

int main()
{
	cin>>n>>s;
	m=strlen(s);
	f[0][0]=1;
	for (int i=0; i<=n; ++i)
		for (int j=0; j<=i; ++j)
		{
			(f[i+1][j+1]+=f[i][j]*2%MOD)%=MOD;
			(f[i+1][max(j-1,0)]+=f[i][j])%=MOD;
		}
	cout<<1ll*f[n][m]*Qpow(Qpow(2,m),MOD-2)%MOD;;
}