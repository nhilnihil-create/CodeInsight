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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        g[i].emplace_back(a - 1);
    }
    queue<int> que;
    vector<int> d(n, INF);
    d[0] = 0;
    que.push(0);
    while(que.size()) {
        int now = que.front();
        que.pop();
        for(auto nxt : g[now]) {
            if(d[nxt] > d[now] + 1) {
                d[nxt] = d[now] + 1;
                que.push(nxt);
            }
        }
    }
    cout << (d[1] >= INF ? -1 : d[1]) << "\n";
}