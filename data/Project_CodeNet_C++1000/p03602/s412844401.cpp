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
    
int calcDist(int a, int b) {
//     return realDist[a][b];
    int best = 1e9 + 5;
    for (int i = 1; i <= n; i++) {
        if (i == a || i == b) continue;
        best = min(best, A[a][i] + A[i][b]);
    }
    return best;
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
    
//    for (int k = 1; k <= n; k++) {
//        for (int i = 1; i <= n; i++) {
//            for (int j = 1; j <= n; j++) {
//                A[i][j] = min(A[i][j], A[i][k] + A[k][j]);
//         }
//     }
// }

for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
        cerr << A[i][j] << " ";
    }
    cerr << endl;
}
    
    sort(dists.begin(), dists.end());
    for (auto p : dists) {
        int dist = p.first;
        int a = p.second.first;
        int b = p.second.second;
        int d = calcDist(a, b);
//         cerr << d << endl;
        if (d == dist) {
            continue;
        } else if (d < dist) {
            printf("-1\n");
            return 0;
        } else {
            ans += dist;
        }
    }
    
    printf("%lld\n", ans / 2);
    
    return 0;
}