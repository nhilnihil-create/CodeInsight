#include <cstdio>
#include <vector>

int vis[100005];

std::vector<int> edges[100005];

int dfs(int node,int c=1){
  int size=1;
  vis[node]=c;
  for(int child:edges[node]){
    if(!vis[child]) size+=dfs(child,c^3);
    if(vis[child]&c) vis[node]=3;
  }
  return size;
}

int main(){
  int N,M;
  scanf("%d %d",&N,&M);
  for(int i=0;i<M;i++){
    int U,V;
    scanf("%d %d",&U,&V);
    U--,V--;
    edges[U].push_back(V);
    edges[V].push_back(U);
  }
  int nccs=0;
  int bipart=0;
  int solo=0;
  for(int i=0;i<N;i++){
    if(!vis[i]){
      if(dfs(i)==1){
	solo++;
      }else{
	bipart+=(vis[i]!=3);
	nccs++;
      }
    }
  }
  printf("%lld\n",1LL*nccs*nccs+1LL*bipart*bipart+1LL*N*N-1LL*(N-solo)*(N-solo));
  return 0;
}
