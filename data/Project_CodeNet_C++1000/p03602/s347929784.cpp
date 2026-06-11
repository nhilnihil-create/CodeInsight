#include <bits/stdc++.h>
    
using namespace std;
    
const int N = 305;
const long long INF = 1e18 + 5;
    
int n;
int A[N][N];
vector<pair<int, pair<int, int> > > dists;
vector<pair<int, int> > V[N];
long long dist[N];
bool vis[N];
long long realDist[N][N];
    
long long calcDist(int a, int b) {
    return realDist[a][b];
}
    
long long ans;
void addEdge(int a, int b, int dist) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            realDist[i][j] = min(realDist[i][j], realDist[i][a] + dist + realDist[b][j]);
        }
    }
    ans += dist;
}
    
int main() {
    
    scanf("%d", &n);
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            realDist[i][j] = INF;
            scanf("%d", &A[i][j]);
            dists.push_back({A[i][j], {i, j}});
        }
    }
    
    for (int i = 1; i <= n; i++) {
        realDist[i][i] = 0;
    }
    
    sort(dists.begin(), dists.end());
    for (auto p : dists) {
        int dist = p.first;
        int a = p.second.first;
        int b = p.second.second;
        long long d = calcDist(a, b);
        if (d == dist) {
            continue;
        } else if (d < dist) {
            printf("-1\n");
            return 0;
        } else {
            addEdge(a, b, dist);
            addEdge(b, a, dist);
        }
    }
    
    printf("%lld\n", ans / 2);
    
    return 0;
}