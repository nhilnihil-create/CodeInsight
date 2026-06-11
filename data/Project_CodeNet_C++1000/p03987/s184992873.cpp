#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
#define all(obj) (obj).begin(), (obj).end()
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;

signed main()
{
    int N;
    cin >> N;
    vector<ll> place(N + 1); // place[a] := aという値がどのindexにあるか
    for (int i = 1; i <= N; i++) {
        ll a;
        cin >> a;
        place[a] = i;
    }

    ll ans = 0;
    set<ll> used = { 0, N + 1 }; // すでに見た要素のindexを記録


    // ある要素よりも小さい値で,最も近いものを探索する
    // usedには今の要素よりも小さい要素しか入っていない
    for (int i = 1; i <= N; i++) { // i := 要素
        ll r, l;

        auto iter = used.lower_bound(place[i]);
        r = *iter; // 右端を調べる
        l = *(--iter); // その1つ前が左端

        ans += i * (place[i] - l) * (r - place[i]);
        used.insert(place[i]);
    }

    cout << ans << endl;

    return 0;
}