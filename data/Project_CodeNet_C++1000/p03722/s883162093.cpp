#include <bits/stdc++.h>
using namespace std;
template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return 1;
    }
    return 0;
}
void debug() { cerr << "\n"; }
template <class T> void debug(const T &x) { cerr << x << "\n"; }
template <class T, class... Args> void debug(const T &x, const Args &... args) {
    cerr << x << " ";
    debug(args...);
}
template <class T> void debugVector(const vector<T> &v) {
    for(const T &x : v) {
        cerr << x << " ";
    }
    cerr << "\n";
}
using ll = long long;

#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
const double EPS = 1e-7;
const int INF = 1 << 30;
const ll LLINF = 1LL << 60;
const double PI = acos(-1);
constexpr int MOD = 1000000007;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//-------------------------------------

struct edge {
    int from, to;
    ll cost;
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<edge> edges(n);
    for(int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges.emplace_back(edge{a - 1, b - 1, c});
    }
    vector<ll> d(n, -LLINF);
    vector<bool> neg(n, false);
    d[0] = 0;
    for(int i = 0; i < n; i++) {
        for(auto e : edges) {
            if(d[e.from] != -LLINF && d[e.to] < d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        for(auto e : edges) {
            if(d[e.from] != -LLINF && d[e.to] < d[e.from] + e.cost) {
                d[e.to] = d[e.from] + e.cost;
                neg[e.to] = true;
            }
            if(neg[e.from]) {
                neg[e.to];
            }
        }
    }
    if(neg[n - 1]) {
        cout << "inf" << endl;
    } else {
        cout << d[n - 1] << endl;
    }
}