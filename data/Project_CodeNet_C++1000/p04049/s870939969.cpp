#include <bits/stdc++.h>
using namespace std;

const int N = 2 * 1000 + 10;

int n, k, ans = N * 2;
vector <int> adj[N];
queue <int> Q;
bool mark[N];
int Lvl[N];

void input() {
    int u, v;
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        u--, v--;
        adj[v].push_back(u) ;
        adj[u].push_back(v) ;
    }
    return;
}

void Clean() {
    for (int i = 0; i < n; i++) {
        mark[i] = false;
        Lvl[i] = 0;
    }
    return;
}

void UpdateAns() {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (Lvl[i] > k / 2)
            cnt++;
    ans = min(cnt, ans) ;
    return;
}

void bfs() {
        while (!Q.empty()) {
            int v = Q.front() ;
            Q.pop() ;
            for (int i = 0; i < adj[v].size() ; i++) {
                int u = adj[v][i];
                if (!mark[u]) {
                    Lvl[u] = Lvl[v] + 1;
                    mark[u] = true;
                    Q.push(u) ;
                }
            }
        }
    UpdateAns() ;
    Clean() ;
    return;
}

void solve() {
    if (k % 2)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < adj[i].size() ; j++) {
                Q.push(i) ;
                Q.push(adj[i][j]) ;
                mark[i] = mark[adj[i][j]] = true;
                bfs() ;
            }
    else
        for (int i = 0; i < n; i++) {
            Q.push(i) ;
            mark[i] = true;
            bfs() ;
        }
    return;
}

int main() {
    input() ;
    solve() ;
    cout << ans << endl;
    return 0;
}
