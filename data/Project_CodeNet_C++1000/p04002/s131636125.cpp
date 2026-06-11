#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
static const int MAX = 1e9;
ll H, W, N;

signed main()
{
    cin >> H >> W >> N;
    map<pair<ll, ll>, ll> mp;
    rep(i, N)
    {
        ll a, b;
        cin >> a >> b;
        --a, --b;
        for (ll da = -1; da <= 1; ++da) {
            for (ll db = -1; db <= 1; ++db) {
                ll na = a + da;
                ll nb = b + db;
                if (na < 1 || H - 1 <= na || nb < 1 || W - 1 <= nb) {
                    continue;
                }
                mp[make_pair(na, nb)]++;
            }
        }
    }
    vector<ll> res(10);
    res[0] = (H - 2) * (W - 2);
    for (auto& kv : mp) {
        res[kv.second]++;
        res[0]--;
    }

    for (auto x : res) {
        cout << x << endl;
    }

    return 0;
}