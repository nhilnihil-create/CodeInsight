#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m, R;
  cin >> n >> m >> R;
  
  vector<ll> r(R);
  for (int i = 0; i < R; i++){
    cin >> r[i];
    r[i]--;
  }

  vector<vector<ll>> dist(n, vector<ll>(n, INF));
  for (int i = 0; i < n; i++){
    dist[i][i] = 0;
  }
  for (int i = 0; i < m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  
  for (int k = 0; k < n; k++){
    for (int i = 0; i < n; i++){
      for (int j = 0; j < n; j++){
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }

  ll res = INF;
  sort(r.begin(), r.end());
  
  
  do {

    ll t = 0;
    for (int i = 0; i < R - 1; i++){
      t += dist[r[i]][r[i + 1]];
    }

    res = min(res, t);

  } while(next_permutation(r.begin(), r.end()));


  cout << res << endl;

  return 0;
}
