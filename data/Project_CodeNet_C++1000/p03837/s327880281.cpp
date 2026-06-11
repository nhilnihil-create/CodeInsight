#include<bits/stdc++.h>
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const int inf = 1001001001;
int main(){
  int N,M,i,j,k,a,b,c;scanf("%d%d",&N,&M);
  int D[N][N];bool unuse[N][N];
  memset(unuse,0,sizeof(unuse));
  for(i=0;i<N;i++){
    fill(D[i],D[i]+N,inf);
    D[i][i] = 0;
  }
  for(i=0;i<M;i++){
    scanf("%d%d%d",&a,&b,&c);a--;b--;
    D[a][b] = D[b][a] = c;
    unuse[a][b] = unuse[b][a] = 1;
  }
  int prev[N][N];
  for(i=0;i<N;i++) fill(prev[i],prev[i]+N,-1);
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      if(unuse[i][j]) prev[i][j] = i;
    }
  }
  for(k=0;k<N;k++){
    for(i=0;i<N;i++){
      for(j=0;j<N;j++){
        if(D[i][j] > D[i][k]+D[k][j]){
          D[i][j] = D[i][k]+D[k][j];
          prev[i][j] = prev[k][j];
        }
      }
    }
  }
  int ns,bs,ans = 0;
  for(i=0;i<N;i++){
    for(j=0;j<N;j++){
      bs = j;ns = prev[i][bs];
      while(ns != -1){
        unuse[ns][bs] = 0;
        bs = ns;
        ns = prev[i][bs];
      }
    }
  }
  for(i=0;i<N;i++) ans += accumulate(unuse[i],unuse[i]+N,0);
  printf("%d\n",ans/2);
}