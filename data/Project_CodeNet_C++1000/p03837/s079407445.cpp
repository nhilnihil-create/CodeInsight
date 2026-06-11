#include <iostream>
#include <vector>
#include <queue>
#define rep(i, n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

static const int N = 100;
static const int M = 21000;
static const int INF = N * M + 1;
vector<P> adj[N];
int a[M], b[M], c[M];
int n, mat[N][N], p[N][N];

void dijkstra(int s){
    bool reached[n];
    priority_queue<P> PQ;
    rep(i, n){
        reached[i] = false;
        mat[s][i] = INF;
    }
    mat[s][s] = 0;
    p[s][s] = -1;
    PQ.push(make_pair(-mat[s][s], s));

    while(!PQ.empty()){
        P f = PQ.top(); PQ.pop();
        int u = f.second;
        reached[u] = true;
        if(-f.first > mat[s][u]) continue;

        rep(i, adj[u].size()){
            int v = adj[u][i].first;
            if(reached[v]) continue;
            if(mat[s][u] + adj[u][i].second < mat[s][v]){
                mat[s][v] = mat[s][u] + adj[u][i].second;
                p[s][v] = u;
                PQ.push(make_pair(-mat[s][v], v));
            }
        }
    }
    return;
}

int main(){
    int m;
    cin >> n >> m;
    rep(i, m){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
        adj[a[i]].push_back(make_pair(b[i], c[i]));
        adj[b[i]].push_back(make_pair(a[i], c[i]));
    }

    rep(i, n) dijkstra(i);

    int ans = m;
    rep(i, m){
        bool used = false;
        rep(j, n){
            if(mat[j][a[i]] + c[i] == mat[j][b[i]]) used = true;
            //if(p[j][a[i]] == b[i] || p[j][b[i]] == a[i]) used = true;
        }
        if(used) ans--;
    }
    cout << ans << endl;
    return 0;
}