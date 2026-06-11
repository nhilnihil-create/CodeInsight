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

const ll LAP_MAX=1e9;

int main(){
    ll N,L,T; cin >> N >> L >> T;
    vector<ll> X(N),pos(N);
    vector<int> W(N);
    rep(i,N){
        cin >> X[i] >> W[i];
        if (W[i]==1) pos[i]=(X[i]+T)%L;
        else pos[i]=(X[i]-T+LAP_MAX*L)%L;
    }
    ll now=0;
    rep2(i,1,3){
        ll j=3-i;
        if (W[0]==i){
            vector<ll> collision;
            rep(k,N) if (W[k]==j) collision.push_back(X[k]);
            ll cnt=collision.size();
            ll lap=2*T/L,rest=2*T-lap*L;
            if (i==1){
                now=(cnt*lap)%N;
                ll last=lower_bound(collision.begin(),collision.end(),X[0]+rest)-collision.begin();
                now=(now+last)%N;
            }
            else{
                now=(N-(cnt*lap)%N)%N;
                ll last=collision.end()-lower_bound(collision.begin(),collision.end(),X[0]-rest+L);
                now=(now-last+N)%N;
            }
        }
    }
    ll pos_now=pos[0];
    sort(pos.begin(),pos.end());
    ll start=lower_bound(pos.begin(),pos.end(),pos_now)-pos.begin();
    vector<ll> ans(N);
    rep(i,N) ans[(now+i)%N]=pos[(start+i)%N];
    rep(i,N) cout << ans[i] << endl;
}