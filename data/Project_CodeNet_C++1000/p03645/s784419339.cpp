#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for(int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    queue<int> q; q.push(0);
    vector<int> visit(N, -1), dist(N, 0);
    visit[0] = 1;
    while(!q.empty()) {
        int u = q.front(); q.pop();
        for(auto p: G[u]) {
            if(visit[p] == -1) {
                visit[p] = 1;
                q.push(p);
                dist[p] = dist[u] + 1;
            }
        }
    }
    if(dist[N - 1] == 2) cout << "POSSIBLE" << endl;
    else cout << "IMPOSSIBLE" << endl;
    return 0;
}