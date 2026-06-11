#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
#define rep(i,n) for (ll i=0;i<n;++i)
#define rep2(i,a,b) for (ll i=a;i<b;++i)
const ll MOD=1000000007;
string alp="abcdefghijklmnopqrstuvwxyz";

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

ll ref(ll x,ll y){
    if (x==0||y==0){
        return 0;
    }
    if (y%x==0){
        return (y/x*3-1)*x;
    }
    if (x>y){
        return x/y*2*y+ref(x%y,y);
    }
    return 2*y+y/x*x+ref(x-y%x,y%x);
}

int main(){
    ll N,X;
    cin >> N >> X;
    ll ans=X+ref(X,N-X);
    cout << ans << endl;
}