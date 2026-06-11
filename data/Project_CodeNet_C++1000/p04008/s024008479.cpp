#include <cstdio>
#include <vector>

std::vector<int> children[100000];
int to[100000];
int N,K;

int cost=0;

int dfs(int node){
  int height=1;
  for(int child:children[node]){
    height=std::max(height,dfs(child)+1);
  }
  if(height==K&&to[node]!=0){
    cost++;
    return 0;
  }else{
    return height;
  }
}

int main(){
  scanf("%d %d",&N,&K);
  int R;
  scanf("%d",&R);
  if(R!=1){
    cost++;
  }
  for(int i=1;i<N;i++){
    int A;
    scanf("%d",&A);
    children[A-1].push_back(i);
    to[i]=A-1;
  }
  dfs(0);
  printf("%d\n",cost);
  return 0;
}
