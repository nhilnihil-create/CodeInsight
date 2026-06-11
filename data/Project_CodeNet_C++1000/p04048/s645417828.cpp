/*-- ILSH  --*/
#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < ll >
#define vll vector < ll > 
#define dt cout<<"HERE\n";
#define pii pair < ll , ll >
#define pll pair < ll , ll >
#define vpi vector < pii >
#define vpl vector < pll >
#define fi first
#define se second 
#define sz size 
#define len length 
const ll inf=1e18+1e17;
const ll mod =1e9+7;
//const ll mod = 998244353;

ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=	(a*a)%mod;b>>=1;}return (res%mod);}

const int N=2e5+5;
void solve(){
	ll n;
	cin>>n;
	ll x;
	cin>>x;
	ll p=x;
	ll ans=0;
	ans+=p;
	ll tt=n-x;
	while ( true){
		if (p%tt==0){
			ans+=p*2;
			break;
		}
		else{
			ll val=p/tt;
			ll x=p-val*tt;
			val=val*2+1;
			ans+=tt*val;
			p=tt-x;
			tt=x;
			ans+=tt;
		}
	}
	cout<<ans<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen ("INPUT.txt" , "r" , stdin);
		freopen ("OUTPUT.txt", "w" , stdout);
	#endif
	ll t=1;
	//cin>>t;
	for ( ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
    	solve();
    }
}