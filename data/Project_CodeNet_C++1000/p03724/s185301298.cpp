#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii =  pair<int, int>;
using pll =  pair<long long, long long>;
constexpr char ln =  '\n';
constexpr long long MOD = 1000000007LL;
constexpr long long INF = 1000000009LL;
#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int i=0;i<(n);i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    int n, m; cin >> n >> m;
    bool fg = true;
    map<int, int> mp;
    rep(i, m){
        int a, b; cin >> a >> b; a--; b--;
        mp[a]++; mp[b]++;
    }
    for(auto m: mp){
        if(m.second%2 == 1) fg = false;
    }

    if(fg) cout << "YES" << ln;
    else cout << "NO" << ln;
}
