/*
Though leaves are many , the root is one.
Through all the lying days of my youth
I swayed my leaves and flowers in the sun.
Now I may wither into the truth.
	  	  	- William Butler Yeats
*/
//#pragma GCC optimize("Ofast,no-stack-protector")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
//#pragma GCC target("avx,tune=native")
#include<bits/stdc++.h>
#pragma comment("-Wl,--stack=1024000000")
//#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
//using namespace __gnu_pbds;
const int inf=0x3f3f3f3f;
const double eps=1e-6;
const int mod=1000000007;
typedef long long ll;
#ifndef LOCAL
#define cerr if(0)cout
#define eprintf(...) 0
#else
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#endif
inline string getstr(string &s,int l,int r){string ret="";for(int i=l;i<=r;i++)ret.push_back(s[i]);return ret;}
int modpow(int x,int y,int md=mod){int ret=1;do{if(y&1)ret=(ll)ret*x%md;x=(ll)x*x%md;}while(y>>=1);return ret;}
inline int Rand(){return rand()*32768+rand();}
int dp[2005][2005],fact[4000005],inv[4000005];
inline int C(int nn,int mm){
	return (ll)fact[nn]*inv[mm]%mod*inv[nn-mm]%mod;
}
inline void add(int &x,int y){
	x+=y;if(x>=mod)x-=mod;
}
int main(){
	fact[0]=1;
	for(int i=1;i<=4e6;i++)fact[i]=(ll)fact[i-1]*i%mod;
	inv[4000000]=modpow(fact[4000000],mod-2);
	for(int i=4e6-1;i>=0;i--)inv[i]=(ll)inv[i+1]*(i+1)%mod;
	int n,k;cin>>n>>k;
	if(k==1){
		puts("1");
		return 0;
	}
	dp[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			dp[i][j]=(dp[i-1][j]+(!j?0ll:1ll*dp[i][j-1]*C(n-i+n-j+(n-j+1)*(k-2),k-2)%mod))%mod;
//			cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
		}
	}
	cout<<(ll)dp[n][n]*fact[n]%mod<<endl;
	return 0;
}