#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2002,mo=1e9+7;
int fac[maxn*maxn],n,k,m,inv[maxn*maxn],f[maxn][maxn];
int qpow(int a,int b)
{
	int ans=1;
	for(;b;b>>=1,a=a*a%mo)
		if(b&1)ans=ans*a%mo;
	return ans;
}
int calc(int x,int y)
{
	if(!y)return 1;
//	cout<<x<<" "<<inv[y]<<" "<<inv[x-y]<<endl;
	return fac[x]*inv[y]%mo*inv[x-y]%mo;
}
signed main()
{
	cin>>n>>k;
	if(k==1){puts("1");return 0;}
	fac[0]=1;
	for(int i=1;i<=2000*2000;i++)fac[i]=i*fac[i-1]%mo,inv[i]=qpow(fac[i],mo-2);
	inv[2000*2000]=qpow(fac[2000*2000],mo-2); 
	for(int i=2000*2000-1;i>=0;i--)inv[i]=(inv[i+1]*(i+1))%mo;
	f[0][0]=1;
	for(int i=1;i<=n;i++)
	for(int j=0;j<=i;j++)
	{
		f[i][j]=f[i-1][j];
		if(j)f[i][j]+=f[i][j-1]*calc(n*k-i-(j-1)*(k-1)-1,k-2)%mo*(n-j+1)%mo,f[i][j]%=mo;
	//	cout<<i<<" "<<j<<" "<<f[i][j]<<endl;
	}
	cout<<f[n][n];
}
