#include<bits/stdc++.h>
using namespace std;

int main(){
  int h,w;
  char c[102][102];
  cin>>h>>w;
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cin>>c[i][j];
    }
  }
  for(int i=1;i<=h;i++){
    for(int j=1;j<=w;j++){
      cout<<c[i][j];
    }
    cout<<endl;
    for(int j=1;j<=w;j++){
      cout<<c[i][j];
    }
    cout<<endl;
  }
}
      
