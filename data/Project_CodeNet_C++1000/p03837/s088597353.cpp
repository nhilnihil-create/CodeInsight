#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int inf = 1e9;

int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> adj(n, vector<int>(n, inf));
    for(int i=0; i<n; i++){
        adj[i][i] = 0;
    }
    vector<int> a(m),b(m),c(m);
    for(int i=0; i<m; i++){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--; b[i]--;
        adj[a[i]][b[i]] = adj[b[i]][a[i]] = c[i];
    }
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                adj[i][j] = min(adj[i][j], adj[i][k] +adj[k][j]);
            }
        }
    }
    int ans = 0;
    for(int i=0; i<m; i++){
        bool ok = false;
        for(int j=0; j<n; j++){
            for(int k=0; k<n; k++){
                if(adj[j][k] == adj[j][a[i]] +c[i] +adj[b[i]][k]){
                    ok = true;
                }
            }
        }
        if(!ok) ans++;
    }
    cout << ans << endl;
    return 0;
}