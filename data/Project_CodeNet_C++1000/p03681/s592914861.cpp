#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (ll i = 0; i < n; ++i)
#define P pair<ll, ll>
#define Graph vector<vector<ll>>
#define fi first
#define se second
constexpr ll mod = 1000000007;
constexpr ll INF = (1ll << 60);
constexpr double pi = 3.14159265358979323846;
template <typename T> inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T> inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

ll modfact(ll n){
    ll ret=1;
    while(n){
        ret*=n;
        ret%=mod;
        n--;
    }
    return ret;
}

int main(){
    ll n,m;cin>>n>>m;
    if(abs(n-m)>=2){
        cout<<0<<endl;
        return 0;
    }

    ll num = (modfact(n) * modfact(m));
    if (abs(n - m) == 1){
        cout<<num%mod<<endl;
    }else {
        cout<<(2*num)%mod<<endl;
    }
    return 0;
}