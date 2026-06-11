#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i<(n); i++)
#define chmax(x, y) x = max(x, y)
#define chmin(x, y) x = min(x, y)
using namespace std;
typedef long long ll;

const ll INF = (1LL << 60);
const int MAX_N = 1010;

vector<int> to[MAX_N];
vector<int> rto[MAX_N];
bool reachableFrom1[MAX_N];
bool reachableFromN[MAX_N];
bool ok[MAX_N];

void dfs(int v) {
    if (reachableFrom1[v]) return;
    reachableFrom1[v] = true;
    for (int u: to[v]) {
        dfs(u);
    }
}

void r_dfs(int v) {
    if (reachableFromN[v]) return;
    reachableFromN[v] = true;
    for (int u: rto[v]) {
        r_dfs(u);
    }
}

typedef tuple<int, int, ll> Edge;

int main() {
    int N, M;
    cin >> N >> M;
    vector<Edge> edges;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        edges.emplace_back(a, b, -c);
        to[a].push_back(b);
        rto[b].push_back(a);
    }

    dfs(0);
    r_dfs(N - 1);
    rep(i, N) ok[i] = reachableFrom1[i] && reachableFromN[i];

    {
        // bellman-ford
        vector<ll> d(N, INF);
        d[0] = 0;
        bool upd = true;
        int step = 0;
        while (upd) {
            upd = false;
            rep(i, M) {
                ll a, b, c;
                tie(a, b, c) = edges[i];
                if (!ok[a]) continue;
                if (!ok[b]) continue;

                ll newD = d[a] + c;
                if (newD < d[b]) {
                    upd = true;
                    d[b] = newD;
                }
            }

            step++;
            if (step > N) {
                cout << "inf" << endl;
                return 0;
            }
        }

        cout << d[N - 1] * -1 << endl;
    }
}