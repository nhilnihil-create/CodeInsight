#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define inf LLONG_MAX>>2
#define MAX 1000000
#define mod 1000000007
#define pb push_back
#define f(i,a,n,x) for ((i)=(a);(i)<(n);(i)+=(x))
#define fd(i,a,n,x) for ((i)=(a);(i)>=(n);(i)-=(x))
#define fi first
#define se second
#define mk make_pair
#define pi pair
#define vt vector
using namespace std;
void read(vt<ll> &a,ll n){ll i,temp;f(i,0,n,1){cin>>temp;a.pb(temp);}}
void solve(){
    ll n,i,ans=0,a,b;
    vt<ll> x;
    cin>>n>>a>>b;
    read(x,n);
    f(i,0,n-1,1)
        if ((x[i+1]-x[i])*a>b)
            ans+=b;
        else
            ans+=(x[i+1]-x[i])*a;
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t=1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}