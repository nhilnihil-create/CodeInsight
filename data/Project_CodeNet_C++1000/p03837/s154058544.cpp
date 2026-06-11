#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m;
    cin >> n >> m;
    vector<int>u(m + 3), v(m + 3), w(m + 3);
    int path[n + 3][n + 3];
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            path[i][j] = 1e8;
        }
        path[i][i] = 0;
    }
    for(int i = 1; i <= m; i++){
        cin >> u[i] >> v[i] >> w[i];
        path[u[i]][v[i]] = w[i];
        path[v[i]][u[i]] = w[i];
    }
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(path[i][k] + path[k][j] < path[i][j]){
                    path[i][j] = path[i][k] + path[k][j];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1; i <= m; i++){
        if(path[u[i]][v[i]] < w[i]){
            ans++;
        }
    }
    cout << ans;
    return 0;
}