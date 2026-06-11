#include <bits/stdc++.h>
using namespace std;
#define repd(i,a,b) for (ll i=(a);i<(b);i++)
#define rep(i,n) repd(i,0,n)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef long long ll;
const long long INF = 1LL << 60;
int main()
{
    ll H, W;
    cin >> H >> W;

    ll ans = INF;
    repd(i, 0, H + 1) {
        ll A = i * W;
        ll w = W / 2;
        ll B = (H - i) * w;
        ll C = H * W - A - B;
        ll max_D = max(A, max(B, C));
        ll min_D = min(A, min(B, C));
        ans = min(ans, max_D - min_D);
    }

    repd(i, 0, W + 1) {
        ll A = i * H;
        ll h = H / 2;
        ll B = (W - i) * h;
        ll C = H * W - A - B;
        ll max_D = max(A, max(B, C));
        ll min_D = min(A, min(B, C));
        ans = min(ans, max_D - min_D);
    }

    if (H % 3 == 0) ans = 0;
    else ans = min(ans, W);

    if (W % 3 == 0) ans = 0;
    else ans = min(ans, H);

    cout << ans << endl;
    return 0;
}