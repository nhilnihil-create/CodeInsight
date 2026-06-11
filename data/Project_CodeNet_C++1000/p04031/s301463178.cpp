#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define REP(i,x,n) for(int i = (x); i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1);


int main(void)
{
    ll n,ans=INF; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll mini=*min_element(all(a)),maxi=*max_element(all(a));
    for(int i=mini;i<=maxi;i++){
        ll tmp=0;
        rep(j,n){
            tmp += (a[j]-i)*(a[j]-i);
        }
        ans = min(ans,tmp);
    }
    cout<<ans<<endl;
    return 0;
}