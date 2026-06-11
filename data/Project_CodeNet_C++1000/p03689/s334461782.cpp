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
    int H,W,h,w;
    cin >> H >> W >> h >> w;
    if (H%h==0&&W%w==0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    int x=-1-(h*w-2+26000);
    rep(i,H){
        rep(j,W){
            if (i%h==0&&j%w==0) cout << 26000;
            else if (i%h==h-1&&j%w==w-1) cout << x;
            else cout << 1;
            if (j!=W-1) cout << ' ';
            else cout << endl;
        }
    }
}