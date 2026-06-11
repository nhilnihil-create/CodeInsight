#include<bits/stdc++.h>
using namespace std;

int main(){
  int H,W;cin>>H>>W;
  char C[H][W];
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++) cin>>C[i][j];
  }
  char ans[2*H][W];
  for(int i=0;i<2*H;i++){
    int k=i/2;
    for(int j=0;j<W;j++){
      ans[i][j]=C[k][j];
    }
  }
  for(int i=0;i<2*H;i++){
    for(int j=0;j<W;j++) cout<<ans[i][j];
    cout<<"\n";
  }
}