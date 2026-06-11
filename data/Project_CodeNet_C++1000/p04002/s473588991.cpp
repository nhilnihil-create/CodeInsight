/*-- ILSH  --*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < ll > 
#define pii pair< ll, ll > 
#define len length 
#define fi first
#define se second
#define dt cout<<"HEre\n";
#define sz(x) (ll)x.size()
const ll inf=1e18+1e17;
const ll mod = 1e9+7;

ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}
const ll N=2e5+5;

void solve(){
	map<pair< ll, ll > ,ll > m;
	ll h,w,n;
	cin>>h>> w>>n;
	for ( ll i=0;i<n;i++){
		ll a, b;
		cin>>a>>b;
		for ( ll i=max(1ll,a-2);i<=min(h-2,a);i++){
			for ( ll j=max(1ll,b-2);j<=min(w-2,b);j++){
				m[mp(i,j)]++;
			}
		}
	}
	ll cnt=0,ans[10]={0};

	for ( auto i:m ){
		cnt++;
		ans[i.se]++;
	}
	ans[0]=(h-2)*(w-2)-cnt;
	for ( ll i=0;i<10;i++)
		cout<<ans[i]<<'\n';
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
//	cin>>t;
	for ( ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
    	solve();
    }
    //	cout << clock() / double(CLOCKS_PER_SEC) << endl;
}
