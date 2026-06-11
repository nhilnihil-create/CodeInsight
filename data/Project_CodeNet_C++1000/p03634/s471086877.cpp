#include <string>
#include <iostream>
#include <vector>
#include <stack>
#include <math.h>
#include <iomanip>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MAX 100000
#define LARGENUM 1000000007
#define INF 9223372036854775807
#define ull unsigned long long 
int color[MAX], n;
ull d[MAX];
typedef pair <ull, int> P;
vector <P> adj[MAX];

void dijkstra(int s){
    priority_queue<P> PQ;
    rep(i, n) {
        d[i] = INF;
        color[i] = WHITE;
    }
    d[s] = 0;
    PQ.push(P(0, s));
    color[0] = GRAY;
    while (!PQ.empty()){
        P f = PQ.top(); PQ.pop();
        int u = f.second;
        color[u] = BLACK;
        if (d[u] < f.first * -1) continue;
        rep(j, adj[u].size()){
            int v = adj[u][j].second;
            if (color[v] == BLACK) continue;
            if (d[v] > d[u] + adj[u][j].first){
                d[v] = d[u] + adj[u][j].first;
                PQ.push(make_pair(d[v] * -1, v));
                color[v] = GRAY;
            }
        }
    }
}

int main(){
    int m, a, b, c, Q, K, x, y;
    cin >> n;
    m = n - 1;
    rep(i, m){
        cin >> a >> b >> c;
        adj[a-1].push_back(P(c, b-1));
        adj[b-1].push_back(P(c, a-1));
    }
    cin >> Q >> K;
    dijkstra(K-1);
    rep(i, Q){
        cin >> x >> y;
        cout << d[x-1] + d[y-1] << endl;
    }
    return 0;
}
