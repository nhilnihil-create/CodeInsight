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
    ll n;cin>>n;
    
    deque<ll> ans;
    rep(i,n){
        ll a;cin>>a;
        if(i%2==0) ans.push_back(a);
        else ans.push_front(a);
    }

    if(n%2==0){
        rep(i,n){
            ll now=ans.front();
            ans.pop_front();
            cout<<now<<" ";
        }
    }else{
        rep(i,n){
            ll now=ans.back();
            ans.pop_back();
            cout<<now<<" ";
        }
    }
    cout<<endl;

    return 0;
}