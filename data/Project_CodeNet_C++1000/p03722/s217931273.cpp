#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1ll << 50;
static const ll MOD = 1e9 + 7;
int N, M;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> M;

    const int NMAX = 1000;
    const int MMAX = 2000;
    int a[MMAX], b[MMAX];
    ll c[MMAX];

    rep(i, M)
    {
        cin >> a[i] >> b[i] >> c[i];
        --a[i], --b[i];
        c[i] *= -1; // コストに負をかけて最短経路を求める
    }

    ll dist[NMAX];

    rep(i, N)
    {
        dist[i] = INF;
    }

    dist[0] = 0; // 頂点1の最短距離は0

    rep(i, N - 1) // 経路の長さは最大でN-1なので最短距離の更新はN-1回行う
    {
        rep(j, M)
        {
            if (dist[a[j]] == INF) { // a[j]には行けない
                continue;
            }
            if (dist[b[j]] > dist[a[j]] + c[j]) { //
                dist[b[j]] = dist[a[j]] + c[j];
            }
        }
    }

    ll ans = dist[N - 1]; // 頂点への最短距離(負を掛けているので)

    bool negative[NMAX]; // 負経路を検出するための配列
    memset(negative, false, sizeof(negative));

    // 負経路の影響がある点を計測する
    // この時,N番目のノードにまで影響があれば"inf"
    rep(i, N)
    {
        rep(j, M)
        {
            if (dist[a[j]] == INF) {
                continue;
            }
            if (dist[b[j]] > dist[a[j]] + c[j]) {
                dist[b[j]] = dist[a[j]] + c[j];
                negative[b[j]] = true;
            }
            if (negative[a[j]] == true) {
                negative[b[j]] = true;
            }
        }
    }

    if (negative[N - 1]) {
        cout << "inf" << endl;
    } else {
        cout << -ans << endl;
    }

    return 0;
}