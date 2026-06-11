#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    ll ans=1,f=0,s=0;
    rep(i,n-1){
        if(a[i] < a[i+1]) f=1;
        if(a[i] > a[i+1]) f=-1;

        if(f==-1 && s==1 || f==1 && s==-1){
            ++ans;
            f=s=0;
            continue;
        }
        s = f;
    }
    cout<<ans<<endl;
    return 0;
}