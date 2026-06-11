#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin>>H>>W;
  vector<vector<char>>c(H,vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>c.at(i).at(j);
    }
  }
  vector<vector<char>>ans(2*H,vector<char>(W));
  for(int i=0;i<2*H;i++){
    for(int j=0;j<W;j++){
      ans.at(i).at(j)=c.at(i/2).at(j);
    }
  }
  for(int i=0;i<2*H;i++){
    for(int j=0;j<W;j++){
      cout<<ans.at(i).at(j);
      if(j==W-1){
        cout<< endl;
      }
    }
  }
}