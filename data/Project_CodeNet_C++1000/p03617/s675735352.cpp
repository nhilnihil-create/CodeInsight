#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i=ll(a);i<ll(b);i++)
#define irep(i,a,b) for(ll i=ll(a);i>=ll(b);i--)
#define pb push_back
#define mp make_pair
#define F .first
#define S .second 
using ll=long long;
using ld=long double;
using namespace std;
const ll mod=1e9+7;
ll GCD(ll a, ll b) { return b ? GCD(b, a%b) : a; }
pair<ld,ll> a[4];
int main(){
    ld n,tmp;
    rep(i,0,4){cin>>tmp;a[i]F=tmp*8/powl(2,i);a[i]S=pow(2,i);}
    cin>>n;
    n*=4;
    sort(a,a+4);
    ll cnt=n,ans=0,t;
    rep(i,0,4){ans+=(cnt/a[i]S)*(a[i]F*a[i]S/8);cnt%=a[i]S;}
    cout<<ans<<endl;
}
