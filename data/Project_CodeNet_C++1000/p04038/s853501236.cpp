#include<iostream>
using namespace std;
const int N=2100,mod=1e9+7;
int n,k,jc[N*N],inv[N*N],f[N][N];
int ksm(int x,int k)
{
	int s=1;for(;k;k>>=1,x=1ll*x*x%mod)
				if(k&1) s=1ll*s*x%mod;return s;
}
void add(int &x,int y) {x+=y;if(x>=mod) x-=mod;}
int mul(int x,int y) {return 1ll*x*y%mod;}
int C(int n,int k) {return n<k?0:mul(mul(jc[n],inv[k]),inv[n-k]);}
int main()
{
	cin>>n>>k;jc[0]=inv[0]=1;
	if(k==1) return puts("1"),0;
	for(int i=1;i<=n*k;i++)
		jc[i]=mul(jc[i-1],i),inv[i]=ksm(jc[i],mod-2);
	f[0][0]=1;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
		{
			if(!f[i][j]) continue;
			add(f[i+1][j],f[i][j]);
			if(i>=j+1) add(f[i][j+1],mul(mul(f[i][j],n-j),C(n*k-j*k+j-i-1,k-2)));
		}
	cout<<f[n][n]<<endl;return 0;
}