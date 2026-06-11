#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i=0; i<n; i++)
#define REP(i, n) for(int i=0; i<=n; i++)
#define repr(i, n) for(int i=n; i>0; i--)
#define REPR(i, n) for(int i=n; i>=0; i--)
#define FOR(i, a, b) for(int i=a; i<b; i++)
#define ALL(v) v.begin(),v.end()
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, ll> pil;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
const int INF = 1e9;
const ll LLINF = 1e18;
const ll MOD = 1e9+7;
template<class T> void puts(T x) { std::cout << x << std::endl; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

ll minArea(ll a, ll b, ll c) {
    return min(a, min(b, c));
}

ll maxArea(ll a, ll b, ll c) {
    return max(a, max(b, c));
}

int main() {
    ll H, W; cin >> H >> W;

    ll ans = LLINF;
    for (ll ah = 1; ah < H; ah++) {
        ll bh = (H - ah) / 2;
        ll ch = H - ah - bh;
        chmin(ans, W*maxArea(ah,bh,ch) - W*(minArea(ah,bh,ch)));
    }
    for (ll ah = 1; ah < H; ah++) {
        ll bh = H - ah;
        ll bw = W / 2;
        ll cw = W - bw;
        chmin(ans, maxArea(ah*W, bh*bw, bh*cw) - minArea(ah*W, bh*bw, bh*cw));
    }
    swap(H, W);
    for (ll ah = 1; ah < H; ah++) {
        ll bh = (H - ah) / 2;
        ll ch = H - ah - bh;
        chmin(ans, W*maxArea(ah,bh,ch) - W*(minArea(ah,bh,ch)));
    }
    for (ll ah = 1; ah < H; ah++) {
        ll bh = H - ah;
        ll bw = W / 2;
        ll cw = W - bw;
        chmin(ans, maxArea(ah*W, bh*bw, bh*cw) - minArea(ah*W, bh*bw, bh*cw));
    }
    cout << ans << endl;
}
