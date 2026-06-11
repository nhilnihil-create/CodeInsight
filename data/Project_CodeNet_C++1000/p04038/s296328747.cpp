#include<bits/stdc++.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define ld long double
#define F first
#define S second

using namespace :: std;

const ll maxn=2100;
const ll mod=1e9+7;
const ll inf=1e9+500;


ll dp[maxn][2*maxn];
ll par[maxn][2*maxn];


ll fac[maxn*maxn];
ll rfac[maxn*maxn];

ll  ent(ll n,ll k){
	if(k>n || k<0){
		return 0;
	}
	return (((fac[n]*rfac[n-k])%mod)*rfac[k])%mod;
}	
ll poww(ll a,ll b){
	ll ans=1;
	while(b>0){
		if(b&1){
			ans=(ans*a)%mod;
		}
		a=(a*a)%mod;
		b=(b>>1);
	}
	return ans;
}
int main(){

	fac[0]=1;
	for(ll i=1;i<maxn*maxn;i++){
		fac[i]=(fac[i-1]*i)%mod;
	}	
	for(ll i=0;i<maxn*maxn;i++){
		rfac[i]=poww(fac[i],mod-2);
	}




	ll n,k;
	cin>>n>>k;

	if(k==1){
		cout<<1;
		return 0;
	}
	dp[1][1]=1;
	par[1][1]=1;
	for(ll j=2;j<2*maxn;j++){
		par[1][j]=par[1][j-1];
	}
	for(ll i=2;i<=n;i++){
		for(ll j=1;j<2*i;j++){
			dp[i][j]=ent(j+(k-2)*i-1,k-2)*par[i-1][j-1];
			par[i][j]=(par[i][j-1]+dp[i][j])%mod;
		}
		for(ll j=2*i;j<2*maxn;j++){
			par[i][j]=par[i][j-1];
		}
	}
	cout<<(par[n][2*maxn-5]*fac[n])%mod<<endl;

}








/*    
	  .      _______    __    ___     ________      ________       _________     _________   ________
	  .     /       \  |  |  /  /    /        \    |        \     /         \   |        |  |   __   \
	  .    /   _____/  |  | /  /    /    ___   \   |   ___   \   |   _______/   |  ______|  |  |  \   \
	  .   /   /        |  |/  /    /    /   \   \  |  |   \   \  |  (______     |  |_____   |  |__/   /
	  .   |  |         |     /     |   /     \  |  |  |    |  |   \        \    |        |  |      __/
	  .   |  |         |     \     |   \     /  |  |  |    |  |    \______  \   |  ______|  |      \
	  .   \   \_____   |  |\  \    \    \___/   /  |  |___/   /    _______) |   |  |_____   |   |\  \
	  .    \        \  |  | \  \    \          /   |         /    /         /   |        |  |   | \  \
	  .     \_______/  |__|  \__\    \________/    |________/     \________/    |________|  |___|  \__\
 */

