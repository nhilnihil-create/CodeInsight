#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e5 + 5, INF = 1e5 + 5;
int N, dist[2][MAX_N];
vector<int> E[MAX_N];

void bfs(int s, int c){
    dist[c][s] = 0;
    queue<int> q; q.push(s);

    while(!q.empty()){
        int u = q.front(); q.pop();
        for(auto v : E[u]){
            if(dist[c][v] == INF){
                dist[c][v] = dist[c][u] + 1;
                q.push(v);
            }
        }
    }
}

int main(){
    cin >> N;
    for(int i=0;i<N-1;i++){
        int a, b; cin >> a >> b;
        E[a].push_back(b); E[b].push_back(a);
    }

    for(int i=0;i<2;i++) for(int j=1;j<=N;j++) dist[i][j] = INF;
    bfs(1, 0); bfs(N, 1);

    int cnt = 0;
    for(int i=1;i<=N;i++) if(dist[1][i]<dist[0][i]) cnt++;

    if((N+1)/2<=cnt) cout << "Snuke" << endl;
    else cout << "Fennec" << endl;
    return 0;
}