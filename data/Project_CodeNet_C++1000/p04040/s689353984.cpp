/* Dsingh_24 */

#include<bits/stdc++.h>
#define ll          long long
#define pb          push_back
#define	endl		'\n'
#define pii         pair<ll int,ll int>
#define vi          vector<ll int>
#define all(a)      (a).begin(),(a).end()
#define F           first
#define S           second
#define sz(x)       (ll int)x.size()
#define hell        1000000007
#define rep(i,a,b)	for(ll int i=a;i<b;i++)
#define lbnd        lower_bound
#define ubnd        upper_bound
#define bs          binary_search
#define mp          make_pair
#define ios	    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;

#define N  200005
ll h,w,a,b,f[N];
ll expo(ll base, ll exponent, ll mod) {								//return base^exponent modulo modulus
    ll ans = 1;
    while(exponent !=0 ) {
        if((exponent&1) == 1) {
            ans = ans*base ;
            ans = ans%mod;
        }
        base = base*base;
        base %= mod;
        exponent>>= 1;
    }
    return ans%mod;
}
ll inv(ll x){
	return expo(x,hell-2,hell);
}
ll cal(ll x,ll y){
	return ((f[x]*inv(f[y]))%hell*inv(f[x-y]))%hell;
}
int main()
{
	ios
	ll i,j;
	f[0]=1;
	for(i=1;i<N;i++)
		f[i]=(f[i-1]*i)%hell;
	cin>>h>>w>>a>>b;
	ll ans=0;
	for(i=1;i<=h-a;i++){
		ans+=(cal(i+b-2,i-1)*cal(w-(b+1)+h-i,w-(b+1)))%hell;
		ans%=hell;
	}
	cout<<ans;
	return 0;
}