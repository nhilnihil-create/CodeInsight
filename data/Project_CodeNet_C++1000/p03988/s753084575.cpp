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
    int N;
    cin >> N;
    vector<int> cnt(N,0);
    int M=0;
    rep(i,N){
        int a;
        cin >> a;
        ++cnt[a],chmax(M,a);
    }
    bool ans=true;
    rep(i,M+1){
        if (i<(M+1)/2&&cnt[i]>0) ans=false;
        if (i==(M+1)/2){
            if (M%2==0&&cnt[i]!=1) ans=false;
            if (M%2==1&&cnt[i]!=2) ans=false;
            continue;
        }
        if (i>(M+1)/2&&cnt[i]<2){
            ans=false;
        }
    }
    if (ans) cout << "Possible" << endl;
    else cout << "Impossible" << endl;
 }