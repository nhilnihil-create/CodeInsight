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
#define MAX 100
#define LARGENUM 1000000007
int color[MAX], d[MAX], n, M[MAX][MAX];
typedef pair <int, int> P;
vector <P> adj[MAX];

int ShortestPath[MAX][MAX];

void dijkstra(int s){
    priority_queue<P> PQ;
    vector <int> parent[MAX];
    rep(i, n) {
        d[i] = LARGENUM;
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
                while(!parent[v].empty()) parent[v].pop_back();
                parent[v].push_back(u);
            }
            else if(d[v] == d[u] + adj[u][j].first){
                d[v] = d[u] + adj[u][j].first;
                PQ.push(make_pair(d[v] * -1, v));
                color[v] = GRAY;
                parent[v].push_back(u);
            }
        }
    }
    rep(i, n){
        rep(j, parent[i].size()){
            ShortestPath[i][parent[i][j]] = WHITE;
        }
    }
}

int main(){
    int m, a, b, c, count = 0;
    cin >> n >> m;
    rep(i, m){
        cin >> a >> b >> c;
        M[a-1][b-1] = c;
        M[b-1][a-1] = c;
        adj[a-1].push_back(P(c, b-1));
        adj[b-1].push_back(P(c, a-1));
    }
    rep(i, n){
        rep(j, n){
            if (M[i][j] == 0) {
                ShortestPath[i][j] = BLACK;
            }
            else {
                ShortestPath[i][j] = GRAY;
            }
        }
    }
    rep(i, n) dijkstra(i);
    rep(i, n) {
        rep(j, n) if (ShortestPath[i][j] == GRAY) count++;
    }
    cout << count / 2 << endl;
    return 0;
}
