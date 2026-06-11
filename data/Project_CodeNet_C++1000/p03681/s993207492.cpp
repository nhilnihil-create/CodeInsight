#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int MOD = 1e9 + 7;

ll fac(ll n){
    ll ans = 1;
    for(ll i=1; i<=n; i++){
        ans = ans*i%MOD;
    }
    return ans%MOD;
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m; cin>>n>>m;
    if(n>m) swap(n,m);
    if(m-n > 1) {
        cout<<0<<endl;
        return 0;
    } 
    else if(m == n+1){
        cout<<fac(n) * fac(m) % MOD << endl;
    }
    else{
        cout<<2 * fac(n) * fac(m) % MOD << endl;
    }
}

// arc076_a