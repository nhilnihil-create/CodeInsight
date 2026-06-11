/*-- ILSH  --*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < int >
#define vll vector < ll > 
#define dt cout<<"HERE\n";
#define pii pair < int , int >
#define pll pair < ll , ll >
#define vpi vector < pll >
#define vpl vector < pll >
#define fi first
#define se second 
#define sz size 
#define len length 

const ll inf=1e18+1e17;
const ll mod =1e9+7;
//const ll mod = 998244353;

ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}


const ll N =5e5+5;



void solve(){
	string s,t;
	cin>>s>> t;
	ll n=s.len(),m=t.len();
	ll arr[n+1],brr[m+1];
	arr[0]=0;brr[0]=0;
	for ( int i=1;i<=n;i++)
		arr[i]=arr[i-1]+( s[i-1]=='A'?1:0);
	for ( int i=1;i<=m;i++)
		brr[i]=brr[i-1]+( t[i-1]=='A'?1:0);
	ll q;
	cin>>q;
	while ( q-- ){
		ll aa,bb,cc,dd;
		cin>>aa>>bb>>cc>>dd;
		aa--,cc--;
		ll a1=arr[bb]-arr[aa],a2=brr[dd]-brr[cc],b1=bb-aa-a1,b2=dd-cc-a2;
		ll cal1=b1*2+a1;
		ll cal2=b2*2+a2;
		cal1=cal1%3;
		cal2=cal2%3;
		if ( cal1==cal2)
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie( NULL);
	cout.tie(NULL);
	// #ifndef
	// 	freopen( "INPUT.txt", "r" , stdin);
	// 	freopen( "OUTPUT.txt","w", stdout);
	// #endif

	int t=1;

	//cin>>t;

	for ( int i=1;i<=t;i++){
   // 	cout<<"Case #"<<i<<": ";
    	solve();
 	}
}