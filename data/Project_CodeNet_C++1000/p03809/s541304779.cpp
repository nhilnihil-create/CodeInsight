#include <cstdio>
#include <vector>
#include <cstdlib>
#include <stdint.h>

std::vector<int64_t> edges[100005];

int64_t as[100005];

void fail(){
  printf("NO\n");
  exit(0);
}

int64_t dfs(int64_t node,int64_t parent){
  if(edges[node].size()==1&&node!=parent) return as[node];//leaf
  int64_t ac=0;
  int64_t max=0;
  for(int64_t child:edges[node]){
    if(child==parent) continue;
    int64_t tmp=dfs(child,node);
    ac+=tmp;
    max=std::max(max,tmp);
  }
  if(max>as[node]||as[node]>ac||2*as[node]<ac) fail();
  if(edges[node].size()==1) return 0;
  //printf("%ld: %ld\n",node,2*as[node]-ac);
  return 2*as[node]-ac;
}

int main(){
  int64_t N;
  scanf("%ld",&N);
  for(int64_t i=0;i<N;i++){
    scanf("%ld",&as[i]);
  }
  for(int64_t i=0;i<N-1;i++){
    int64_t A,B;
    scanf("%ld %ld",&A,&B);
    A--,B--;
    edges[A].push_back(B);
    edges[B].push_back(A);
  }
  if(dfs(0,0)) fail();
  printf("YES\n");
  return 0;
}
