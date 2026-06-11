#include<bits/stdc++.h>

using namespace std;

const int INF = 1000000000;

struct Edge{
  int a;
  int b;
  int c;
};

int main(){
  int N, M;
  scanf("%d%d", &N, &M);
  
  int dist[N][N];
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if(i == j) dist[i][j] = 0;
      else dist[i][j] = INF;
    }
  }
  
  Edge edge[M];
  for(int e = 0; e < M; e++){
    scanf("%d%d%d", &edge[e].a, &edge[e].b, &edge[e].c);
    edge[e].a--;
    edge[e].b--;
    dist[edge[e].a][edge[e].b] = edge[e].c;
    dist[edge[e].b][edge[e].a] = edge[e].c;
  }
  
  for(int k = 0; k < N; k++){
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
      }
    }
  }
  
  int candidates = 0;
  
  for(int e = 0; e < M; e++){
    int s = 0;
    for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
        if(dist[i][edge[e].a] + edge[e].c + dist[edge[e].b][j] == dist[i][j]){
          s = 1;
        }
      }
    }
    
    if(!s) candidates++;
  }
  
  printf("%d\n", candidates);
  
  return 0;
}