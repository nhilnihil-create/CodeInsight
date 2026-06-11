#include<bits/stdc++.h>
using namespace std;
const int maxn=2000*2000,p=1e9+7;
int fac[maxn+9],ifac[maxn+9];
inline int poww(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1ll*a*ans%p;b>>=1;
		a=1ll*a*a%p;
	}return ans;
}
int C(int n,int m){
	if(n<m)return 0;
	return 1ll*fac[n]*ifac[m]%p*ifac[n-m]%p;
} 
void init(){
	int inv2=p-(p/2);
	fac[0]=1;for(int i=1;i<=maxn;++i)fac[i]=1ll*fac[i-1]*i%p;
	ifac[maxn]=poww(fac[maxn],p-2);for(int i=maxn-1;i>=0;--i)ifac[i]=1ll*(i+1)*ifac[i+1]%p;
}
int n,k,f[2020][2020];
int main(){
	init();
	cin>>n>>k;
	if(k==1){cout<<1;return 0;}
	for(int i=1;i<=n;++i)f[i][0]=1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=i;++j){
			f[i][j]=f[i-1][j];
			f[i][j]=(f[i][j]+1ll*f[i][j-1]*(n-j+1)%p*C(n*k-i-(j-1)*(k-1)-1,k-2)%p)%p;
		}
	cout<<f[n][n];
}