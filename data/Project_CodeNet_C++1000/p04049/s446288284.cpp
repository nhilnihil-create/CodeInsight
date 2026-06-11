#include<cstdio>
#include<vector>
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int N = 2005;
int dis[N][N];
bool Map[N][N], Vis[N];
vector<int> G[N], Go[N];
queue<int> Q;
int BFS(int s, int k) {
    memset(Vis,0,sizeof(Vis));
    bool Can;
    int ans = 1, u, v;
    Vis[s] = true, Q.push(s);
    for(int j = 0; j < Go[s].size(); ++j) {
        Vis[Go[s][j]] = true;
    }    

    while(!Q.empty()) {
        u = Q.front(), Q.pop();
        for(int i = 0; i < G[u].size(); ++i) {
            v = G[u][i];
            if(!Vis[v]) {
                Vis[v] = true;
                for(int j = 0; j < Go[v].size(); ++j) {
                    Vis[Go[v][j]] = true;
                }
                Q.push(v);
                ++ans;
            }
        }
    }
    return ans;
}
struct P {
    int x, step;
};
queue<P> q;
void Dis(int s) {
    memset(Vis,0,sizeof(Vis));
    P u, v;
    u.x = s, u.step = 0, q.push(u);
    dis[s][s] = 0, Vis[s] = true;
    while(!q.empty()) {
        u = q.front(), q.pop();
        int x = u.x;
        for(int i = 0; i < G[x].size(); ++i) {
            v.x = G[x][i];
            if(!Vis[v.x]) {
                Vis[v.x] = true;
                v.step = u.step + 1;
                dis[s][v.x] = v.step;
                q.push(v);
            }
        }
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    int x, y;
    for(int i = 1; i < n; ++i) {
        cin >> x >> y;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    

    for(int i = 1; i <= n; ++i) Dis(i);

    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            if(dis[i][j] > k) {
                Go[i].push_back(j);
                Go[j].push_back(i);
            }

    int ans, Min = 0x7fffffff;
    for(int i = 1; i <= n; ++i) {
        ans = BFS(i,k);
        if(n-ans < Min) Min = n-ans;
    }
    
    cout << Min << '\n';
return 0;
}