#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1e9+7;
const ll INF=1e9;
const ll IINF=1e18;
const double EPS=1e-8;
const double pi=acos(-1);

template<class T> inline bool chmin(T &a,T b){
    if (a>b){
        a=b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T &a,T b){
    if (a<b){
        a=b;
        return true;
    }
    return false;
}

int main(){
    ll n,m;
    cin >> n >> m;
    vector<ll> a(n);
    rep(i,n) cin >> a[i],--a[i];
    vector<vector<ll>> dat(m,vector<ll>(2,0));
    rep2(i,1,n){
        if (a[i]==m-1) continue;
        ++dat[a[i]+1][0];
        ll x=a[i]-a[i-1];
        if (a[i-1]>a[i]) x+=m;
        dat[a[i]+1][1]+=x;
    }
    vector<ll> covered(m,0);
    rep2(i,1,n){
        if (a[i]-a[i-1]==1||(a[i]==m-1&&a[i]==0)) continue;
        if (a[i-1]<a[i]){
            ++covered[a[i-1]+2];
            if (a[i]<m-1) --covered[a[i]+1];
        }
        else {
            ++covered[0],--covered[a[i]+1];
            if (a[i-1]<m-2) ++covered[a[i-1]+2];
        }
    }
    rep(i,m-1) covered[i+1]+=covered[i];
    ll cnt=0;
    rep2(i,1,n){
        if (a[i-1]<=a[i]) cnt+=a[i]-a[i-1];
        else cnt+=a[i]+1;
    }
    ll ans=cnt;
    rep2(i,1,m){
        cnt-=covered[i];
        cnt+=dat[i][1]-dat[i][0];
        chmin(ans,cnt);
    }
    cout << ans << endl;
}