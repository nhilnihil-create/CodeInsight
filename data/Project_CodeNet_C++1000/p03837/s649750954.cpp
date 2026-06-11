#include<bits/stdc++.h>
using namespace std;
int dist[101][101];
int n, m;
bool isUsed(int a, int b, int c){
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      if(dist[i][j] == dist[i][a] + c + dist[b][j]) return false;
    }
  }
  return true;
}
int main(){
  cin >> n >> m;
  for(int i=0; i<n; i++) for(int j=0; j<n; j++) dist[i][j] = (i == j ? 0 : 1e9);
  vector<int> a(m), b(m), c(m);
  for(int i=0; i<m; i++){
    cin >> a[i] >> b[i] >> c[i];
    dist[--a[i]][--b[i]] = c[i];
    dist[b[i]][a[i]] = c[i];
  }
  for(int k=0; k<n; k++) for(int i=0; i<n; i++) for(int j=0; j<n; j++) dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
  int ans = 0;
  for(int i=0; i<m; i++) ans += isUsed(a[i], b[i], c[i]);
  cout << ans << endl;
}