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
    ll W,H,N;cin>>W>>H>>N;
    ll a1_max=0,a2_min=W,a3_max=0,a4_min=H;
    rep(i,N){
        ll x,y,a;cin>>x>>y>>a;
        if(a==1){
            chmax(a1_max,x);
        }else if(a==2){
            chmin(a2_min,x);
        }else if(a==3){
            chmax(a3_max,y);
        }else{
            chmin(a4_min,y);
        }
    }

    ll ans=W*H;
    ans=ans*max(0ll,(a2_min-a1_max))/W;
    ans=ans*max(0ll,(a4_min-a3_max))/H;

    cout<<ans<<endl;
    return 0;
}