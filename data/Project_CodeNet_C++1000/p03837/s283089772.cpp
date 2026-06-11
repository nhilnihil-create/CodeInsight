#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  ll a, b, c;
  vector<tuple<int, int, ll>> edge(m);
  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  for (int i = 0; i < m; i++){
    cin >> a >> b >> c;
    a--; b--;
    edge[i] = make_tuple(a, b, c);
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for (int i = 0; i < n; i++){
    dist[i][i] = 0;
  }


  

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
      }
    }
  }

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
//      cout << i << " " << j << " " << dist[i][j] << endl;
    }
  }

  ll res = 0;
  for (int i = 0; i < m; i++){
    int ok = 0;
    for (int j = 0; j < n; j++){
      for (int k = 0; k < n; k++){
        if (dist[j][k] == dist[j][get<0>(edge[i])] + dist[get<1>(edge[i])][k] + get<2>(edge[i]))
          ok = 1;
      }
    }
    if (!ok)
      res++;
  }

  cout << res << endl;

  return 0;
}
