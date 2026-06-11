#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
int main() {
  int W,H,N,x,y,a; cin>>W>>H>>N;
  int ans[W][H]={0};
  
  for(int i=0; i<N; i++){
    cin>>x>>y>>a;
    if(a==1){
      for(int j=0; j<x; j++){
        for(int k=0; k<H; k++) ans[j][k]=1;
      }       
    }
    else if(a==2){
      for(int j=x; j<W; j++){
        for(int k=0; k<H; k++) ans[j][k]=1;
      }
    }
    else if(a==3){
      for(int j=0; j<W; j++){
        for(int k=0; k<y; k++) ans[j][k]=1;
      }
    }
    else{
      for(int j=0; j<W; j++){
        for(int k=y; k<H; k++) ans[j][k]=1;
      }
    }
  }
  int cnt=0;
  rep(i,W){
    rep(j,H) if(!ans[i][j]==1) cnt++;
  }
  cout<<cnt;
}