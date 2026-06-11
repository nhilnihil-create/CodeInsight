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

int N, M, Q;
vector<vint> G(100005);
int color[100005] = {};
int size[100005] = {};
void bfs(int s, int d, int c) {
        if (size[s] >= d) return;
        queue<int> que;
        que.push(s);
        size[s] = d;
        if (color[s] == 0) color[s] = c;
        while (!que.empty()) {
                int v = que.front(); que.pop();
                for (auto &u : G[v]) {
                        int nd = size[v] - 1;
                        if (size[u] >= nd) continue;
                        size[u] = nd;
                        if (color[u] == 0) color[u] = c;
                        que.push(u);
                }
        }
}

int main() {
        cin >> N >> M;
        for (int i = 0; i < M; i++) {
                int a, b;
                cin >> a >> b; --a, --b;
                G[a].push_back(b);
                G[b].push_back(a);
        }
        cin >> Q;
        vint v(Q), d(Q), c(Q);
        for (int i = Q - 1; i >= 0; i--) {
                cin >> v[i] >> d[i] >> c[i]; --v[i];
        }

        for (int i = 0; i < Q; i++) {
                bfs(v[i], d[i] + 1, c[i]);
        }
        for (int i = 0; i < N; i++) {
                cout << color[i] << el;
        }
        return (0);
}