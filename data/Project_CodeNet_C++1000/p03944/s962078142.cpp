#include<bits/stdc++.h>
using namespace std;

int main(){
  int W,H,N;
  scanf("%d%d%d",&W,&H,&N);
  vector<int> X(N),Y(N),a(N);
  for(int i=0;i<N;i++) scanf("%d%d%d",&X[i],&Y[i],&a[i]);
  //vector<bool> Ver(H,true),Hor(W,true);
  int l=0,r=W,d=0,u=H;
  for(int i=0;i<N;i++){
    switch(a[i]){
      case 1:
        l=max(l,X[i]);
        break;
      case 2:
        r=min(r,X[i]);
        break;
      case 3:
        d=max(d,Y[i]);
        break;
      case 4:
        u=min(u,Y[i]);
        break;
    }
  }
  int ans=max(0,r-l)*max(0,u-d);
  printf("%d\n",ans);
}