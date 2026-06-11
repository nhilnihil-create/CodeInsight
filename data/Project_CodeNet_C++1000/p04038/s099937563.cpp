#include<bits/stdc++.h>
#define rint register int 
#define ll long long 
using namespace std;
const int mod = 1e9+7;
const int Max = 4e6;
int N,K,fac[4001000],Ifac[4001000],f[2020][2020];
inline ll ksm(ll x,ll y){ll res=1;while(y){if(y&1) res=res*x%mod;x=x*x%mod;y>>=1;} return res;}
inline int add(int x,int y){x+=y;return x>=mod?x-mod:x;}
inline int C(int x,int y){return 1ll*fac[x]*Ifac[y]%mod*Ifac[x-y]%mod;}
inline void Init(){
	fac[0]=Ifac[0]=1;
	for(rint i=1;i<=Max;++i) fac[i]=1ll*fac[i-1]*i%mod;
	Ifac[Max]=ksm(fac[Max],mod-2);
	for(rint i=Max-1;i>=1;--i) Ifac[i]=1ll*Ifac[i+1]*(i+1)%mod;
}
int main(){
	cin>>N>>K;
	if(K==1){
		cout<<1<<endl;
		exit(0);
	}
	Init();
	f[0][0]=1;
	for(rint i=1;i<=N;++i) {
		for(rint j=0;j<=i;++j) {
			f[i][j]=add(f[i][j],f[i-1][j]);
			if(j)
			f[i][j]=add(f[i][j],1ll*(N-j+1)*f[i][j-1]%mod*C(N-i+(K-1)*(N-j+1)-1,K-2)%mod);
		}
	}cout<<f[N][N];
	return 0;
}