#include <bits/stdc++.h>
#include <math.h>
#define _GLIBCXX_DEBUG
using namespace std;
int main() {
  
  int H,W;
  cin>>H>>W;
  
  vector<vector<char>> vec(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>vec[i][j];
    }
  }
  
  vector<vector<char>> ans(H+2,vector<char>(W+2));
  for(int i=0;i<H+2;i++){
    for(int j=0;j<W+2;j++){
      if(i==0){
        ans[i][j]='#';
      }
      else if(i==H+1){
        ans[i][j]='#';
      }
      else{
        if(j==0||j==W+1){
          ans[i][j]='#';
        }
        else{
          ans[i][j]=vec[i-1][j-1];
        }
      }
    }
  }
  
  for(int i=0;i<H+2;i++){
    for(int j=0;j<W+2;j++){
      cout<<ans[i][j];
    }
    cout<<endl;
  }
}