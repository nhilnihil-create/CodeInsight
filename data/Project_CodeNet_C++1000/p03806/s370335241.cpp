#include "bits/stdc++.h"
using namespace std;
using ll     = long long;
using pii    = pair<int, int>;
using pll    = pair<ll, ll>;
using vi     = vector<int>;
using vl     = vector<ll>;
using vvi    = vector<vi>;
using vvl    = vector<vl>;
const ll INF = 1LL << 60;
const ll MOD = 1000000007;
template <class T>
bool chmax(T &a, const T &b) {
    return (a < b) ? (a = b, 1) : 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    return (b < a) ? (a = b, 1) : 0;
}
template <class C>
void print(const C &c, std::ostream &os = std::cout) {
    std::copy(std::begin(c), std::end(c), std::ostream_iterator<typename C::value_type>(os, " "));
    os << std::endl;
}

int main() {
    int n, ma, mb;
    cin >> n >> ma >> mb;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i] >> c[i];
    }
    vvl dp(401, vl(401, INF));
    dp[0][0] = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 400; j >= 0; --j) {
            for (int k = 400; k >= 0; --k) {
                if (j - a[i] >= 0 && k - b[i] >= 0)
                    chmin(dp[j][k], dp[j - a[i]][k - b[i]] + c[i]);
            }
        }
    }
    ll ret = INF;
    for (int i = 1; i <= 400; ++i) {
        int aa = ma * i;
        int bb = mb * i;
        if (aa <= 400 && bb <= 400) {
            chmin(ret, dp[aa][bb]);
        } else
            break;
    }
    if (ret == INF)
        cout << -1 << "\n";
    else
        cout << ret << "\n";
    return 0;
}