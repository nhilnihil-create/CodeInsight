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
    int n, k;
    cin >> n >> k;
    vvi edges(n), rev(n);
    int ret = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        a--;
        if (i == 0 && a != 0) {
            ret++;
            a = 0;
        }
        edges[i].push_back(a);
        rev[a].push_back(i);
    }
    vi dist(n, -1);
    queue<int> q;
    q.push(0);
    dist[0] = 0;
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (auto &v : rev[p]) {
            if (dist[v] != -1)
                continue;
            dist[v] = dist[p] + 1;
            q.push(v);
        }
    }
    vector<pii> distp;
    for (int i = 0; i < n; ++i) {
        distp.emplace_back(dist[i], i);
    }
    sort(distp.begin(), distp.end(), greater<pii>());
    vector<bool> ok(n, false);
    for (int i = 0; i < n; ++i) {
        int idx = distp[i].second;
        int d   = distp[i].first;
        if (d <= k || ok[idx])
            continue;
        for (int j = 0; j < k - 1; ++j) {
            idx = edges[idx].front();
        }
        queue<int> q;
        q.push(idx);
        ok[idx] = true;
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            for (auto &u : rev[v]) {
                if (ok[u])
                    continue;
                ok[u] = true;
                q.push(u);
            }
        }
        ret++;
    }
    cout << ret << "\n";
    return 0;
}