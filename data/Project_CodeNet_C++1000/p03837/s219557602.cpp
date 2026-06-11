#include<bits/stdc++.h>
using namespace std;
#define rep(i, V) for (int i = 0; i < V; i++)
#define _GLIBCXX_DEBUG

int N, M;
int INF =  10000;
int ans = 0;

int main(){
    cin >> N >> M;
    vector<vector<int>> dist(N, vector<int>(N, INF));
    vector<vector<int>> edges(M, vector<int>(3));
    rep(i, M){
        int a, b, c;
        cin >> a >> b >> c;
      	a -= 1;
      	b -= 1;
        edges[i][0] = a;
        edges[i][1] = b;
        edges[i][2] = c;
        dist[a][b] = c;
        dist[b][a] = c;
    }

    rep(k, N){
        rep(i, N){
            rep(j, N) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        }
    }

  	rep(i, N){
   		dist[i][i] = 0;
    }
  
    rep(i, M){
        bool flag = false;
        int a = edges[i][0];
        int b = edges[i][1];
        int c = edges[i][2];
        rep(s, N){
            if (flag == true){
            	break;
            }
            rep(t, N){
                if (dist[s][a] + c + dist[b][t] == dist[s][t]){
                	flag = true;
                  	break;
                }
            }
        }
        if (flag == false) ans++;
    }
    cout << ans;
}