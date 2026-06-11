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

int main(){
    ll N,A,B,C,D;
    cin >> N >> A >> B >> C >> D;
    N--;
    ll dif=abs(A-B);
    bool ans=false;
    rep(i,N+1){
        ll c=i*(C+D)-N*D;
        ll d=i*(C+D)-N*C;
        if (c<=dif&&dif<=d){
            ans=true;
        }
    }
    if (ans){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}