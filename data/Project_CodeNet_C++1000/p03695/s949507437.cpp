#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(long long i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n; cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];
    ll maxi=0,mini=0;
    vector<bool> color(8,false);
    rep(i,n){
        if(a[i]<3200) color[a[i]/400]=true;
        else maxi++;
    }
    rep(i,8) if(color[i]) mini++;
    maxi+=mini;
    if(mini==0) mini=1;
    cout << mini << " " << maxi << endl;
    return 0;
}