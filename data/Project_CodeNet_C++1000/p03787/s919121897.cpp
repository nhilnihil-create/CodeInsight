#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using Pi = pair<int, int>;
using Pl = pair<ll, ll>;
using vint = vector<int>;
using vll = vector<ll>;
template<typename T> using uset = unordered_set<T>;
template<typename T1, typename T2> using umap = unordered_map<T1, T2>;

constexpr int INF = (1 << 30) - 1;
constexpr ll LLINF = 1LL << 60;
constexpr int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};
constexpr int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
constexpr char el = '\n';
constexpr int mod = 1000000007;

template<typename T> T gcd(T a, T b) { return (b ? gcd(b, a % b) : a); }
template<typename T> T lcm(T a, T b) { return (a / gcd(a, b) * b); }
template<typename T1, typename T2> inline void chmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1 &a, T2 b) { if (a < b) a = b; }

int N, M;
vector<vint> G(100005);
bool flag[100005] = {};
int color[100005];

int dfs(int v, int c = 0) {
    int ret = 1;
    if (color[v] != -1 && c != color[v]) return (0);
    color[v] = c;
    if (flag[v]) return (1);
    flag[v] = true;
    for (auto &u : G[v]) ret &= dfs(u, 1 - c);
    return (ret);
}

int main() {
    cin >> N >> M;
    fill_n(color, 100005, -1);
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v; --u, --v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int colorable = 0;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if (!flag[i] && G[i].size() > 0) {
            if (dfs(i)) colorable++;
            else cnt++;
        }
    }
    int rem = count(flag, flag + N, false);

    ll ans = (ll)rem * 2 * N - (ll)rem * rem;

    ans += 2 * (ll)colorable * colorable;
    ans += 2 * (ll)colorable * cnt + cnt * cnt;

    cout << ans << endl;
    return (0);
}