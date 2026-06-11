#include <bits/stdc++.h>
using namespace std;
#define INF INT_MAX/3

int main(){
    int N,M,R;cin >> N >> M >> R;
    vector<int> vis;
    vector<vector<int> >dist(N);
    for(int i = 0 ; i < R ; i++){
        int r;cin >> r;r--;
        vis.push_back(r);
    }
    for(int i = 0 ; i < N ; i++){
        dist[i].resize(N);
        for(int j = 0; j < N ; j++){
            if(i == j)dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 0; i < M ; i++){
        int u,v,cost;
        cin >> u >> v >> cost;u--;v--;
        dist[u][v] = cost;
        dist[v][u] = cost;
    }
    //warshall_floyd
    
    for(int k = 0 ; k < N ; k++){
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                dist[i][j] = min(dist[i][j],dist[k][j]+dist[i][k]);
            }
        }
    }
    int res = INF;

    sort(vis.begin(), vis.end());
    do {
        int tmp = 0;
        for (int i = 1; i < vis.size(); ++i) tmp += dist[vis[i]][vis[i-1]];
        res = min(res, tmp);
    } while (next_permutation(vis.begin(), vis.end()));
    

    cout << res << endl;

    return 0;
}
