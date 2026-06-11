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

int dfs(int p, vvi &edges) {
    int nc = edges[p].size();
    vi ch(nc);
    for (int i = 0; i < nc; ++i) {
        ch[i] = dfs(edges[p][i], edges);
    }
    sort(ch.begin(), ch.end(), greater<int>());
    int ret = 0;
    for (int i = 0; i < nc; ++i) {
        chmax(ret, ch[i] + i + 1);
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    vvi edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int a;
        cin >> a;
        a--;
        edges[a].push_back(i + 1);
    }
    cout << dfs(0, edges) << "\n";
    return 0;
}