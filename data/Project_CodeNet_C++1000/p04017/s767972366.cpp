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

const ll LOG_N=30;

int main(){
    ll N;
    cin >> N;
    vector<ll> x(N);
    rep(i,N) cin >> x[i];
    ll L,Q;
    cin >> L >> Q;
    vector<vector<ll>> next(LOG_N,vector<ll>(N,-1));
    rep(i,N){
        ll y=upper_bound(x.begin(),x.end(),x[i]+L)-x.begin()-1;
        next[0][i]=y;
    }
    rep(i,LOG_N-1){
        rep(j,N){
            next[i+1][j]=next[i][next[i][j]];
        }
    }
    rep(i,Q){
        ll a,b,ans=0;
        cin >> a >> b;
        if (a>b) swap(a,b);
        --a,--b;
        for (int i=LOG_N-1;i>=0;--i){
            if (next[i][a]<b){
                ans+=1<<i;
                a=next[i][a];
            }
        }
        ++ans;
        cout << ans << endl;
    }
}