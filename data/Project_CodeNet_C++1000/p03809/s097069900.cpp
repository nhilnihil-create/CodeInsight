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
    vi a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vvi edges(n);
    for (int i = 0; i < n - 1; ++i) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    vi depth(n, -1);
    depth[0] = 0;
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (auto &u : edges[v]) {
            if (depth[u] != -1)
                continue;
            depth[u] = depth[v] + 1;
            q.push(u);
        }
    }
    vector<pii> di;
    for (int i = 0; i < n; ++i) {
        di.emplace_back(depth[i], i);
    }
    sort(di.begin(), di.end());
    bool ok = true;
    for (int i = n - 1; i >= 0; --i) {
        int c = di[i].second;
        int d = di[i].first;
        vi childs;
        int maxi = 0;
        int sum  = 0;
        for (auto &u : edges[c]) {
            if (depth[u] < d)
                continue;
            childs.push_back(a[u]);
            chmax(maxi, a[u]);
            sum += a[u];
        }
        if (childs.size() == 0)
            continue;
        int amari = max(0, maxi - (sum - maxi));
        int mini  = (sum - amari) / 2 + amari;
        if (c == 0) {
            if (childs.size() == 1) {
                if (a[c] != sum)
                    ok = false;
            } else {
                if (amari != 0 || sum % 2 == 1 || sum / 2 != a[c])
                    ok = false;
            }
        }
        if (mini <= a[c] && a[c] <= sum) {
            a[c] = 2 * a[c] - sum;
        } else {
            ok = false;
            break;
        }
    }
    if (ok)
        cout << "YES"
             << "\n";
    else
        cout << "NO"
             << "\n";
    return 0;
}