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
    ll N;
    cin >> N;
    vector<Pll> a(N+1);
    rep(i,N){
        ll b;
        cin >> b;
        a[i]=Pll(b,i);
    }
    a[N]=Pll(0,0);
    sort(a.begin(),a.end());
    reverse(a.begin(),a.end());
    vector<ll> ans(N);
    ll pre=a[0].second;
    rep(i,N){
        if (a[i].first==a[i+1].first) continue;
        ll x=a[i].first-a[i+1].first;
        chmin(pre,a[i].second);
        ans[pre]+=(i+1)*x;
    }
    rep(i,N) cout << ans[i] << endl;
}