#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

const ll INF=10000000000000000;

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
    ll N,x;
    cin >> N >> x;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
    }
    vector<ll> minp(N,INF);
    ll move=0,ans=INF;
    rep(i,N){
        ll count=x*i;
        rep(j,N){
            chmin(minp[j],a[(j+i)%N]);
            count+=minp[j];
        }
        chmin(ans,count);
    }
    cout << ans << endl;
}