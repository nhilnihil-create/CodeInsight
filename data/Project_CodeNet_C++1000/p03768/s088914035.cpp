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
    int n, m;
    cin >> n >> m;
    vvi edges(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    int q;
    cin >> q;
    vi v(q), d(q), c(q);
    for (int i = 0; i < q; ++i) {
        cin >> v[i] >> d[i] >> c[i];
        v[i]--;
    }
    vvi colors(n, vi(11, 0));
    for (int i = 0; i < q; ++i) {
        colors[v[i]][d[i]] = i + 1;
    }
    for (int i = 10; i >= 1; --i) {
        for (int j = 0; j < n; ++j) {
            chmax(colors[j][i - 1], colors[j][i]);
            for (auto &ne : edges[j]) {
                chmax(colors[ne][i - 1], colors[j][i]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (colors[i][0] == 0)
            cout << 0 << "\n";
        else
            cout << c[colors[i][0] - 1] << "\n";
    }
    return 0;
}