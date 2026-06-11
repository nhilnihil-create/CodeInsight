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
const int N=1e5+5;
ll arr[N];
void solve(){
	int n;
	cin>>n;
	map < int , int > m1,m2;
	set< int > s;
	for ( int i=0;i<n;i++){
		cin>>arr[i];
		s.insert( arr[i]);
		if ( i%2)
			m1[arr[i]]++;
	}
	sort( arr,arr+n);
	for ( int i=0;i<n;i++){
		if ( i%2)
			m2[arr[i]]++;
	}
	int tot=0;
	for ( auto i: s){
		tot+=abs(m1[i]-m2[i]);
	}
	cout<<tot/2<<'\n';
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	ll t=1;
	//cin>>t;
	for ( ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
    	solve();
    }
}