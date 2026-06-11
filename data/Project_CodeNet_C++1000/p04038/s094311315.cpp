#include<bits/stdc++.h>
using namespace std;
int n,k,mx,f[2010][2010],a1[4000010],a2[4000010],b[4000010];
void add(int &x,int y)
{
	x+=y;
	x%=1000000007;
}
int js(int n,int m)
{
	return 1ll*a1[n]*a2[m]%1000000007*a2[n-m]%1000000007;
}
int main()
{
	cin>>n>>k;
	mx=n*k;
	if(k==1)
	{
		cout<<1;
		return 0;
	}
	a1[0]=a2[0]=b[0]=b[1]=1;
	for(int i=1;i<=n*k;i++)
	{
		a1[i]=1ll*a1[i-1]*i%1000000007;
	}
	for(int i=2;i<=n*k;i++)
	{
		b[i]=1ll*b[1000000007%i]*(1000000007-1000000007/i)%1000000007;
	}
	for(int i=1;i<=n*k;i++)
	{
		a2[i]=1ll*a2[i-1]*b[i]%1000000007;
	}
	f[0][0]=1;
	for(int i=1;i<=n;++i)
	{
		for(int j=0;j<=i;++j)
		{
			add(f[i][j],f[i-1][j]);
			if(j!=0)
			{
				add(f[i][j],1ll*f[i][j-1]*(n-j+1)%1000000007*js((n-i)+(n-j+1)*(k-1)-1,k-2)%1000000007);
			}
		}
	}
	cout<<f[n][n];
    return 0;
}
