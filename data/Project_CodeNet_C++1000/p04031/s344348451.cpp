#include<bits/stdc++.h>
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
template <typename T>inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll ans=INF,n;cin>>n;
    vector<ll> a(n);
    rep(i,n) cin>>a[i];

    
    for(ll i=-100;i<=100;i++){
        ll sum=0;
        rep(j,n){
            sum+=(a[j]-i)*(a[j]-i);
        }

        chmin(ans,sum);
    }

    cout<<ans<<endl;

    return 0;
}