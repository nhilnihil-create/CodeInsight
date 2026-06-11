#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll n,m; cin>>n>>m;
    vector<ll> a(n),b(n),c(m),d(m);
    rep(i,n) cin>>a[i]>>b[i];
    rep(i,m) cin>>c[i]>>d[i];

    rep(i,n){
        ll mdist=abs(a[i]-c[0])+abs(b[i]-d[0]),cp=1;
        for(int j=1;j<m;j++){
            ll nowdist=abs(a[i]-c[j])+abs(b[i]-d[j]);
            if(mdist>nowdist){
                mdist=nowdist;
                cp=j+1;
            }
        }
        cout<<cp<<endl;
    }
    return 0;
}