#include<bits/stdc++.h>
#define ll long long
#define inf(x) (ll)(1e##x)
using namespace std;
const int mod = 1e9+7;
int n,k,f[2010][2010];
ll inv[4001000],fac[4001000],ifac[4001000];
ll C(int n,int m){return fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
void upd(int &a,ll b){a=(a+b)%mod;}
int main(){
	cin>>n>>k;
	if(k==1){cout<<1<<'\n';return 0;}
	f[0][0]=1;
	inv[1]=1;
	for(int i=2;i<=4000000;i++) inv[i]=inv[mod%i]*-(mod/i)%mod;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=4000000;i++) fac[i]=fac[i-1]*i%mod,ifac[i]=ifac[i-1]*inv[i]%mod;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++){
			upd(f[i+1][j],f[i][j]);
			if(i>j) upd(f[i][j+1],f[i][j]*C((n-i)+(n-j)*(k-1)-1,k-2));
		}
	ll ans=f[n][n]*fac[n]%mod;
	cout<<(ans+mod)%mod<<'\n';
	return 0;
}