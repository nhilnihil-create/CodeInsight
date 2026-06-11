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
    vector<string> a(n),b(m);
    rep(i,n) cin>>a[i];
    rep(i,m) cin>>b[i];

    bool allin=false;

    rep(i,n)rep(j,n){
        if(i+m-1>=n || j+m-1>=n) continue;
        bool in=true;
        rep(k,m)rep(l,m){
            if(a[i+k][j+l]!=b[k][l]) in=false;
        }
        if(in) allin=true;
    }

    if(allin) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}