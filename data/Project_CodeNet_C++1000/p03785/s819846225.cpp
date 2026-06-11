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
template <typename T>
inline bool chmax(T &a, T b){if (a < b){a = b;return 1;}return 0;}
template <typename T>
inline bool chmin(T &a, T b){if (a > b){a = b;return 1;}return 0;}

int main(){
    ll n,c,k;cin>>n>>c>>k;
    vector<ll> t(n);
    rep(i,n) cin>>t[i];
    sort(t.begin(),t.end());

    ll ans=0,key=0;
    while(1){
        ll var=t[key]+k;
        vector<ll>::iterator position;
        position = upper_bound(t.begin(), t.end(), var);
        ll ins = key;
        key = min((ll)(distance(t.begin(), position)), ins+c);
        ans++;
        if(key>=n) break;
    }

    cout<<ans<<endl;

    return 0;
}