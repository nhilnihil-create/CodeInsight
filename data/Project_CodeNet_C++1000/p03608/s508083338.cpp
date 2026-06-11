#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
 
int main(){
  int n, m, r;
  cin >> n >> m >> r;
  int INF = 1000000007;
  vector<vector<int>> dist(n, vector<int>(n, INF));
  vector<int> d(r);
  for(int i=0; i<r; i++){
    int k;
    cin>>k;
    k--;
    d[i] = k;
  }
  sort(d.begin(), d.end());
  
  for(int i=0; i<m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    dist[a][b] = c;
    dist[b][a] = c;
  }
  for(int k=0; k<n; k++){
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  int ans=INF;
  do{
    int tmp=0;
    for(int i=1; i<r; i++){
      tmp += dist[d[i-1]][d[i]];
    }
    ans = min(ans, tmp);
  }while(next_permutation(d.begin(), d.end()));
  cout << ans << endl;
  return 0;
}
