#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
const int maxn=5000010;
long long fac[maxn],ifac[maxn],inv[maxn],d[2010][2010];
int n,k;
int main(){
	cin>>n>>k;
	if(k==1){
		cout<<1<<endl;
		return 0;
	}
	fac[0]=inv[0]=ifac[0]=fac[1]=inv[1]=ifac[1]=1;
	for(int i=2;i<=n*k+10;++i){
		fac[i]=(fac[i-1]*i)%mod;
		inv[i]=(mod-mod/i)*inv[mod%i]%mod;
		ifac[i]=(ifac[i-1]*inv[i])%mod;
	}
	d[0][1]=1;
	for(int i=2;i<=n;++i)
		d[0][i]=d[0][i-1]*(fac[i*(k-1)-1]*ifac[k-2]%mod*ifac[(i-1)*(k-1)]%mod)%mod;
	for(int i=1;i<=n;++i){
		for(int j=i;j<=n;++j){
			d[i][j]=(d[i-1][j]+d[i][j-1]*(fac[i+j*(k-1)-1]*ifac[k-2]%mod*ifac[i+(j-1)*(k-1)]%mod)%mod)%mod;
		}
	}
	cout<<d[n][n]*fac[n]%mod<<endl;
	return 0;
}
