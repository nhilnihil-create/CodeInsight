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
#define int long long
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
int modpow(int x,int y,int md=mod){if(y==0)return 1;int ret=modpow(x,y>>1,md);ret=(ll)ret*ret%md;if(y&1)ret=(ll)ret*x%md;return ret;}
int n,a[100005];
char c[100005];
int dp[100005][2];
int suf[100005];
inline int f(char x){
	return x=='+'?1:-1;
}
signed main(){
	cin>>n;cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>c[i]>>a[i];
	}
	for(int i=n;i>=1;i--)suf[i]=suf[i+1]+abs(a[i]);
	memset(dp,0xf7,sizeof dp);
	dp[1][0]=a[1];
	for(int i=2;i<=n;i++){
		dp[i][0]=max(dp[i-1][0]+f(c[i])*a[i],dp[i-1][1]+f(c[i])*a[i]);
		dp[i][1]=dp[i-1][1]-f(c[i])*a[i];
		if(c[i]=='-')dp[i][1]=max(dp[i][1],dp[i-1][0]+f(c[i])*a[i]);
	}
	ll ans=dp[n][0];
	for(int i=2;i<=n;i++)if(c[i]=='-')ans=max(ans,dp[i-1][1]+suf[i]);
	cout<<ans<<endl;
	return 0;
}