#include <iostream>
#include <cstdio>
#define int long long
#define N 200002
using namespace std;
const int mod=1000000007;
int a,b,x,y,i,j,f[N],inv[N];
int poww(int a,int b)
{
	int ans=1,base=a;
	while(b){
		if(b&1) ans=ans*base%mod;
		base=base*base%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m)
{
	return f[n]*inv[m]%mod*inv[n-m]%mod;
}
signed main()
{
	cin>>a>>b>>x>>y;
	f[0]=1;
	for(i=1;i<=200000;i++) f[i]=f[i-1]*i%mod;
	inv[200000]=poww(f[200000],mod-2);
	for(i=199999;i>=0;i--) inv[i]=inv[i+1]*(i+1)%mod;
	int ans=C(a+b-2,b-1);
	for(i=a-x+1;i<=a-x+1;i++){
		for(j=1;j<=y;j++) ans=(ans-C(i+j-3,j-1)*C(a+b-i-j,b-j)%mod+mod)%mod;
	}
	cout<<(ans+mod)%mod<<endl;
	return 0;
}
