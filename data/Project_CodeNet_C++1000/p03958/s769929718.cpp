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

int main(){
    ll k,t;cin>>k>>t;
    vector<ll> a(t);
    rep(i,t) cin>>a[i];

    sort(a.begin(),a.end(),greater<ll>());
    ll sum=0;
    rep(i,t){
        if(i!=0) sum+=a[i];
    }

    cout<<max(0ll,a[0]-sum-1)<<endl;
    return 0;
}