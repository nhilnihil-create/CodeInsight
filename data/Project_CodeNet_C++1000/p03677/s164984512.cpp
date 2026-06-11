#include <bits/stdc++.h>
#define FOR(i, a, n) for(ll i = (ll)a; i < (ll)n; i++)
#define rep(i, n) FOR(i, 0, n)
#define REP(i, n) FOR(i, 1, ll(n) + 1)
#define ALL(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;

constexpr ll mod = 1e9 + 7;
constexpr ll inf = 1LL << 60;

template <typename T> inline bool chmax(T &a, const T b) {
    if(a >= b) return false;
    a = b;
    return true;
}
template <typename T> inline bool chmin(T &a, const T b) {
    if(a <= b) return false;
    a = b;
    return true;
}

/*-------------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    vector<int> imos(m + 1), cnt(m + 1);

    ll num = 0, x = 1;
    int a, b;
    cin >> a;
    rep(i, n - 1) {
        cin >> b;
        num += min(b < a ? b + m - a : b - a, b);
        a = (a == m ? 1 : a + 1);
        cnt[b] += b - a;
        imos[a]++;
        imos[b]--;
        if(b < a) {
            imos[0]++;
            cnt[b] += m;
        }
        a = b;
    }
    rep(i, m) imos[i + 1] += imos[i];

    ll ans = num;
    while(x < m) {
        num += cnt[x] - imos[x++];
        chmin(ans, num);
    }
    cout << ans << endl;
}