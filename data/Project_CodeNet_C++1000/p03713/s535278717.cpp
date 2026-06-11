#include <bits/stdc++.h>
#define REP(i, m, n) for(int (i) = (m); (i) < (n); ++i)
#define rep(i, n) REP(i, 0, n)
#define all(x) (x).begin(), (x).end()
using namespace std;
using Graph = vector<vector<int>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
typedef long long ll;
typedef pair<ll, ll> P;
const int INF = 1e9+7;
const ll LINF = 1LL<<60;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    ll H, W;
    cin >> H >> W;

    ll ans = H * W;
    ll s[3];
    rep(i, 2) {
        for (ll h = 1; h < H; ++h) {
            s[0] = h * W;
            s[1] = (H - h) * (W / 2);
            s[2] = H * W - (s[0] + s[1]);
            sort(s, s + 3);
            ans = min(ans, s[2] - s[0]);

            s[0] = h * W;
            s[1] = ((H - h) / 2) * W;
            s[2] = H * W - (s[0] + s[1]);
            sort(s, s + 3);
            ans = min(ans, s[2] - s[0]);
        }
        swap(H, W);
    }

    cout << ans << endl;

    return 0;
}