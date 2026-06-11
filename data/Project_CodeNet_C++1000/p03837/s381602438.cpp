#include<cstdio>
#include <iostream>
#include<algorithm>
int g[101][101],a[1000],b[1000],c[1000];
int const infty=10000000;

int main(){
  int n,m,answer=0;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++){
    for(int j=1;j<=n;j++){
      g[i][j]=infty;
    }
  }
  for(int i=0;i<m;i++){
  std::cin >> a[i] >> b[i] >> c[i];
    g[a[i]][b[i]]=g[b[i]][a[i]]=c[i];
  }
  for(int k=1;k<=n;k++){
    for(int i=1;i<=n;i++){
      for(int j=1;j<=n;j++){
        g[i][j]=std::min(g[i][k]+g[k][j],g[i][j]);
      }
    }
  }
  for(int i=0;i<m;i++){
    bool use=false;
    for(int j=1;j<=n;j++){
      if(j==a[i]||j==b[i]){
        if(c[i]==g[a[i]][b[i]])use=true;
      // }else if(g[a[i]][j]==c[i]+g[b[i]][j])use=true;
      }
    }
    if(!use)answer++;
  }
  printf("%d",answer);
  return 0;
}