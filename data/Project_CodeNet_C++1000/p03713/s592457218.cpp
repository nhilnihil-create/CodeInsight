#pragma region
#pragma GCC target("avx2")
#pragma GCC optimize("03")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std; typedef long double ld; typedef long long ll;
typedef unsigned long long ull;
#define endl "\n"
#define MP make_pair
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORR(x,arr) for(auto& x:arr)
#define PII pair<int, int>
#define PLL pair<ll, ll>
#define VPII vector<PII>
#define VPLL vector<PLL>
#define FI first 
#define SE second
#define ALL(x) (x).begin(), (x).end()
constexpr int INF=1<<30; constexpr ll LINF=1LL<<60; constexpr ll mod=1e9+7; constexpr int NIL = -1;
template<class T>inline bool chmax(T &a, const T &b) { if (a<b) { a = b; return 1; } return 0; }
template<class T>inline bool chmin(T &a, const T &b) { if (b<a) { a = b; return 1; } return 0; }
#pragma endregion
//-------------------
ll diff(PLL a, PLL b, PLL c) {
    ll max=0, min=LINF;
    chmax(max, a.first*a.second);
    chmax(max, b.first*b.second);
    chmax(max, c.first*c.second);
    chmin(min, a.first*a.second);
    chmin(min, b.first*b.second);
    chmin(min, c.first*c.second);
    return max - min;
}

int solve(ll h, ll w) {
    ll ans = LINF;
    FOR(i,0,h) {
        int mid = (i+h)/2;
        chmin(ans, diff({i,w}, {mid-i,w}, {h-mid,w}));
        mid = w/2;
        chmin(ans, diff({i,w}, {h-i, mid}, {h-i, w-mid}));
    }
    return ans;
}

int main(){
    cin.tie(0); ios::sync_with_stdio(false); //cout << fixed << setprecision(15);
    ll h,w; cin >> h >> w;
    cout << min(solve(h,w), solve(w,h)) << endl;
    return 0;
}
