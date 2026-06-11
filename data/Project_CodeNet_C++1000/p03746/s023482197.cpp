// Why am I so dumb? :c
#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair

#define all(x) (x).begin(), (x).end()

#define fi first
#define se second

using namespace std;

typedef long long ll;

const int MAXN = (int)1e5 + 5;

vector<int> adj[MAXN];

bool u[MAXN];

int n, m;

void solve() {
    scanf("%d %d", &n, &m);

    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        adj[u].pb(v);
        adj[v].pb(u);
    }

    deque<int> q;
    u[1] = 1;
    q.pb(1);

    for (int i = 1; i <= n; ++i) {
        {
            int v = q.front();

            for (int to : adj[v]) {
                if (!u[to]) {
                    q.push_front(to);
                    u[to] = 1;
                    break;
                }
            }
        }

        {
            int v = q.back();

            for (int to : adj[v]) {
                if (!u[to]) {
                    q.pb(to);
                    u[to] = 1;
                    break;
                }
            }
        }
    }

    printf("%d\n", q.size());

    while (!q.empty()) {
        printf("%d ", q.front());
        q.pop_front();
    }
}

int main() {
    int tt = 1;

    while (tt--) {
        solve();
    }

    return 0;
}