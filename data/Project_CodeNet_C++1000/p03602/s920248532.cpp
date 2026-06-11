#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> P;

int main(){
  ll N;
  cin >> N;
  vector<vector<ll>> dist(N, vector<ll>(N));
  ll sum = 0;
  for(int i=0;i<N;i++)
    for(int j=0;j<N;j++){
      cin >> dist[i][j];
      sum += dist[i][j];
    }
  bool ans = true;
  set<P> iran;
  for(int k=0;k<N;k++)
    for(int i=0;i<N;i++)
      for(int j=0;j<N;j++){
        if(i == j)
          continue;
        if(dist[i][j] > dist[i][k] + dist[k][j])
          ans = false;
        else if(dist[i][j] == dist[i][k] + dist[k][j] && k!=i && k!=j){
          iran.insert(P(i, j));
        }
      }
  if(ans){
    for(auto x : iran){
      ll f, t;
      tie(f, t) = x;
      sum -= dist[f][t];
    }
    cout << sum/2 << endl;
  }else
    cout << -1 << endl;
  return 0;
}
