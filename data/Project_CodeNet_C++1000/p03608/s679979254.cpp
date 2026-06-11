#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, m, r;
  cin >> n >> m >> r;
  vector<int> place(r);
  for(int i=0; i<r; i++) cin >> place[i];
  sort(place.begin(), place.end());
  vector<vector<int>> dist(n+1, vector<int> (n+1,1e9));
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for(int k=1; k<n+1;k++){
    for(int i=1; i<n+1; i++){
      for(int j=1; j<n+1; j++){
        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
      }
    }
  }
  int ans = 1e9;
  do{
    int cnt = 0;
    for(int i=0; i<r-1; i++) cnt += dist[place[i]][place[i+1]];
    ans = min(ans, cnt);
  }while(next_permutation(place.begin(), place.end()));
  cout << ans << endl;
}