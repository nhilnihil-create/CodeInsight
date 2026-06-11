#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
  ll h,w;
  cin>>h>>w;
  char oi[h][w];
  char ei[2*h][w];
  
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin>>oi[i][j];
    }
    for(int j=0;j<w;j++){
      ll ni=2*i;
      ei[ni][j]=oi[i][j];
      ei[ni+1][j]=oi[i][j];
    }
  }
  
  for(int i=0;i<2*h;i++){
    for(int j=0;j<w;j++){
      cout<<ei[i][j];
    }
    cout<<endl;
  }
  
  return 0;
}
