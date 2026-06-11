#include <cstdio>
#include <vector>
#include <algorithm>

std::vector<int> edges[100005];

int vs[100005];
int ds[100005];
int cs[100005];

int vis[100005];
int color[100005];

void paint(int V,int D,int C){
  if(vis[V]>=D) return;
  vis[V]=D;
  if(!color[V]) color[V]=C;
  for(int W:edges[V]){
    paint(W,D-1,C);
  }
}

int main(){
  int N,M,Q;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int A,B;
    scanf("%d %d",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  std::fill(vis,vis+N,-1);

  scanf("%d",&Q);
  for(int i=0;i<Q;i++){
    scanf("%d %d %d",&vs[i],&ds[i],&cs[i]);
    vs[i]--;
  }
  for(int i=Q-1;i>=0;i--){
    paint(vs[i],ds[i],cs[i]);
  }
  for(int i=0;i<N;i++){
    printf("%d\n",color[i]);
  }
  return 0;
}
