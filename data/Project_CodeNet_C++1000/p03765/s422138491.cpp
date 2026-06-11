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

const int OVER_N=300000;

int main(){
    string S,T;
    int q;
    cin >> S >> T >> q;
    int s=S.size(),t=T.size();
    vector<int> sa(s+1,0),sb(s+1,0),ta(t+1,0),tb(t+1,0);
    rep(i,s){
        sa[i+1]=sa[i],sb[i+1]=sb[i];
        if (S[i]=='A') ++sa[i+1];
        else ++sb[i+1];
    }
    rep(i,t){
        ta[i+1]=ta[i],tb[i+1]=tb[i];
        if (T[i]=='A') ++ta[i+1];
        else ++tb[i+1];
    }
    rep(i,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        --a,--c;
        int sc=(sa[b]-sa[a]-sb[b]+sb[a]+OVER_N)%3;
        int tc=(ta[d]-ta[c]-tb[d]+tb[c]+OVER_N)%3;
        if (sc==tc) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}