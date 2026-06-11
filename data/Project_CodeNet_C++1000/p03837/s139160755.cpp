#include <iostream>
using namespace std;

int main(){
  const int inf = 1000000;
  int N, M;
  cin >> N >> M;
  
  int a[1000], b[1000], c[1000], dist[100][100];
  
  for(int i = 0; i < M; i++){
    cin >> a[i] >> b[i] >> c[i];
    a[i]--, b[i]--;
  }
  
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i==j)
        dist[i][j] = 0;
      else
        dist[i][j] = inf;
  	}
  }
  
  for(int i = 0; i < M; i++){
    dist[a[i]][b[i]] = min(dist[a[i]][b[i]], c[i]);
    dist[b[i]][a[i]] = min(dist[b[i]][a[i]], c[i]);
  }
  
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }
  
  int ans = M;
  for(int i = 0; i < M; i++){
    bool flag = false;
    for(int j = 0; j < N; j++){
      if(dist[j][a[i]]+c[i] == dist[j][b[i]])
        flag = true;
    }
    if(flag)
      ans--;
  }
  
  cout << ans << endl;
  
  return 0;
}