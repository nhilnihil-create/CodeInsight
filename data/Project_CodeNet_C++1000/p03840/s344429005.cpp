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
    vector<ll> a(7);
    rep(i,7) cin >> a[i];
    ll ans=a[1],cnt=0;
    vector<ll> use={a[0],a[3],a[4]};
    if (use[0]==0||use[1]==0||use[2]==0){
        rep(i,3) ans+=use[i]/2*2;
        cout << ans << endl;
        return 0;
    }
    rep(i,3) if (use[i]%2==1) ++cnt;
    rep(i,3) ans+=(use[i]-1)/2*2;
    if (cnt==0) ans+=6;
    if (cnt==1) ans+=4;
    if (cnt>=2) ans+=3;
    cout << ans << endl;
}
