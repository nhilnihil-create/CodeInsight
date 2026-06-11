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
    int N; cin >> N;
    Graph G(N);
    for(int i = 0; i < N; i++) {
        int a; cin >> a; a--;
        G[i].push_back(a);
    }
    
    queue<int> que;
    vector<int> visit(N), dist(N);
    que.push(0);
    while(!que.empty()) {
        int u = que.front(); que.pop();
        for(auto v : G[u]) {
            if(visit[v] == 0) {
                visit[v] = 1;
                dist[v] = dist[u] + 1;
                que.push(v);
            }
        }
    }
    if(visit[1]) cout << dist[1] << endl;
    else cout << -1 << endl;
    return 0;
}