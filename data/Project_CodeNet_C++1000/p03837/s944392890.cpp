#include <bits/stdc++.h>
using namespace std;

// computational complexity : O(V^3)

const long long int INF = 1e6;
int V,E;// number of (vertices, edges)
vector<vector<long long int>> d;// d[i][j] = shortest distances between i and j

int main(){
    cin >> V >> E;
    d.assign(V, vector<long long int>(V, INF));
    for (int i=0; i<V; i++){
        d[i][i] = 0;
    }

    vector<int> a(E), b(E), c(E);
    for (int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u -= 1;
        v -= 1;
        d[u][v] = w;
        d[v][u] = w;

        a[i] = u;
        b[i] = v;
        c[i] = w;
    }

    // naive DP
    for (int k=0; k<V; k++){// potential relay points
        for (int i=0; i<V; i++){
            for (int j=0; j<V; j++){
                d[i][j] = min(
                    d[i][j],// without going through k
                    d[i][k] + d[k][j]// with going through k
                );
            }
        }
    }

    int ans = E;
    for (int i=0; i<E; i++){
        bool used = false;
        for (int j=0; j<V; j++){
            if(d[j][a[i]] + c[i] == d[j][b[i]]) used = true;
        }
        if(used == true) ans -= 1;
    }
    cout << ans << endl;
    return 0;
}