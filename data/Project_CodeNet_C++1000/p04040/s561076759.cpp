#include <bits/stdc++.h>
typedef long long int ll;
typedef long double ld;
#define pb push_back
#define pii pair < int, int >
#define F first
#define S second
#define int  long long int
#define sync ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#pragma GCC optimize ("Ofast")
#pragma GCC optimize ("unroll-loops")
using namespace std;
/// khodaya komak kon
const int N=2e5;
ll mod=1e9+7;

ll fac[N];
ll power(ll n, ll k){
    if (k==0){
        return 1;
    }
    else{
        if (k%2==0){
            ll x=power(n,k/2);
            return x*x%mod;
        }
        else{
            ll x=power(n,k/2);
            x=x*x%mod;
            return x*n%mod;
        }
    }
}
ll fm[N];
ll ent(ll k, ll n){
	if (k==0 || k==n){
        return 1;
	}

	return (((fac[n]*fm[k])%mod)*fm[n-k])%mod;
}

int32_t main(){
    fac[0] = 1;

	for(int i=1;i<N;i++) {
        fac[i]=(fac[i-1]*i)%mod;
	}
	for(int i=0;i<N;i++) {
        fm[i]=power(fac[i],mod-2);
	}
	ll n,m;
	cin >> n >> m;
	ll a,b;
	cin >> a >> b;
	ll ans=0;
	for (int i=1;i<=n-a;i++){
        ans+=ent(b-1,i-1+b-1)*ent(m-b-1,n-i+m-b-1)%mod;
        ans%=mod;
	}
	cout << ans << endl;

}








