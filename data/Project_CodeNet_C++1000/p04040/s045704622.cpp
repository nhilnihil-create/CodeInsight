/*-- ILSH  --*/

// Multipoll evaluation + Divide and Conquer
// Time ( Iterative ) < Time ( Recursive )

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef double ld;

#define pb push_back 
#define pop pop_back
#define mp make_pair
#define vii vector < ll > 
#define len length 
#define fi first
#define se second
#define dt cout<<"HEre\n";
#define sz(x) (ll)x.size()
const ll inf=1e18+1e17;
const ll mod = 1e9+7;

ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m == 1)return 0;while(a> 1){ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;}  
ll powm(ll a,ll b){a=a%mod;ll res=1;while(b){if(b&1)res=(res*a)%mod;a=(a*a)%mod;b>>=1;}return (res%mod);}
const int N=(1<<18);
ll fac[N],faci[N];
inline ll add ( ll a, ll b){
	if ( a+b>mod)
		return a+b-mod;
	return a+b;
}
void init(){
	fac[0]=1;faci[0]=1;
	for ( int i=1;i<N;i++){
		fac[i]=(fac[i-1]*i)%mod;
		faci[i]=modInverse(fac[i],mod);
	}
}
void solve(){
	int h,w,a,b;
	cin>>h>>w>>a>>b;
	int x=w-b;
	ll res=0;
	for ( int i=1;i<=h-a;i++){
		ll val1=(fac[i+b-2]*faci[i-1])%mod;
		val1=(val1*faci[b-1])%mod;
		int x1=h-i,x2=w-b-1;
//		cout<<x1<<' '<<x2<<'\n';
		ll val2=(fac[x1+x2]*faci[x1])%mod;
		val2=(val2*faci[x2])%mod;
		res=add(res,(val1*val2)%mod);
	}
	cout<<res<<'\n';
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
	init();
	for ( ll i=1;i<=t;i++){
		//cout<<"Case #"<<i<<": ";
    	solve();
    }
    //	cout << clock() / double(CLOCKS_PER_SEC) << endl;
}
