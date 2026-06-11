#include <bits/stdc++.h>
#define ll long long int
#define MOD 1000000007
#define INF 1e18
#define PI 3.14159265358979

using namespace std;

int main(void){
  ll n, m;
  cin >> n >> m;
  
  vector<vector<pair<ll, ll>>> edge(n);
  for (int i = 0; i < m; i++){
    ll a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    edge[a].emplace_back(make_pair(b, c));
  }

  vector<ll> dist(n, -INF);
  dist[0] = 0;
  vector<bool> isinf(n, false);
  for (int i = 0; i < n + 1; i++){
    for (int j = 0; j < n; j++){
      for (int k = 0; k < edge[j].size(); k++){
        if (dist[j] + edge[j][k].second > dist[edge[j][k].first]){
          if (i == n - 1){
            isinf[j] = true;
          }
          dist[edge[j][k].first] = dist[j] + edge[j][k].second;
        }
        if (isinf[j]){
          isinf[edge[j][k].first] = true;
        }
      }
    }
  }

  if (isinf[n-1]){
    cout << "inf" << endl;
  }
  else 
    cout << dist[n-1] << endl;

  return 0;
}
