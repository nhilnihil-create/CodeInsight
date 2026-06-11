#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vvl = vector<vl>;
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
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vvi edges(n);
    int s;
    int t;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
        if (i == 0) {
            s = a;
            t = b;
        }
    }
    deque<int> ret = {s, t};
    set<int> used;
    used.insert(s);
    used.insert(t);
    while (true) {
        bool ok = true;
        for (auto &n : edges[s]) {
            if (used.count(n) == 0) {
                used.insert(n);
                ret.push_front(n);
                s = n;
                ok = false;
                break;
            }
        }
        if (ok)
            break;
    }
    while (true) {
        bool ok = true;
        for (auto &n : edges[t]) {
            if (used.count(n) == 0) {
                used.insert(n);
                ret.push_back(n);
                t = n;
                ok = false;
                break;
            }
        }
        if (ok)
            break;
    }
    cout << ret.size() << "\n";
    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}