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
    int n;
    cin >> n;
    vvi edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int x, y;
        cin >> x >> y;
        x--, y--;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vi grundy(n, -1);
    function<int(int, int)> dfs = [&](int c, int p) {
        int child = 0;
        for (auto &v : edges[c]) {
            if (v == p)
                continue;
            else
                child ^= dfs(v, c);
        }
        return grundy[c] = child + 1;
    };
    dfs(0, -1);
    int gs = 0;
    for (auto &v : edges[0]) {
        gs ^= grundy[v];
    }
    if (gs == 0)
        cout << "Bob"
             << "\n";
    else
        cout << "Alice"
             << "\n";
    return 0;
}