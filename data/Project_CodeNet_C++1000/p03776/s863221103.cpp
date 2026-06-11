#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)n; ++i)
static const int dx[4] = { 0, 1, 0, -1 };
static const int dy[4] = { 1, 0, -1, 0 };
static const char dir[4] = { 'u', 'r', 'd', 'l' };
static const ll INF = 1 << 21;
static const ll MOD = 1e9 + 7;
ll N, A, B;
ll comb[51][51]; // comb[i][j] = i個からj個を取る場合の数
void comInit()
{
    comb[0][0] = comb[1][0] = comb[1][1] = 1;
    for (int i = 1; i < 51; ++i) {
        for (int j = 0; j <= i; ++j) {
            comb[i][j] = comb[i - 1][j] + comb[i - 1][j - 1];
        }
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> N >> A >> B;
    vector<double> v(N);
    rep(i, N) { cin >> v[i]; }
    sort(v.begin(), v.end(), greater<double>());
    comInit();

    double ave = accumulate(v.begin(), v.begin() + A, 0.0) / (double)A;

    ll res = 0;
    int x = 0, y = 0;
    if (v[0] != v[A - 1]) {
        rep(i, N) {
            if (v[A-1] == v[i]) {
                ++x; // 全体の中でv[A-]となる値
            }
        }
        rep(i, A) {
            if (v[A-1] == v[i]) {
                ++y; // Aまででv[A-]となる値
            }
        }
        res = comb[x][y]; // 全体でx個あるv[A-1]のうちy個を使う
    } else { // 少なくともA個は最大値がある
        rep(i, N) {
            if (v[i] == v[0]) {
                ++x; // 全体の中でv[0]となる値
            }
        }
        for (int i = A; i <= B; ++i) {
            res += comb[x][i]; // x < iとなったら0になるのでおk
        }
    }
    cout << fixed << setprecision(20)<< ave << endl;
    cout << res << endl;
    return 0;
}