#include <bits/stdc++.h>
using namespace std;

int main(){
  int H, W;
  cin>>H>>W;
  vector<vector<char>> data(H, vector<char>(W));
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++){
      cin>>data.at(i).at(j);
    }
  }
  vector<vector<char>> ans(H+2, vector<char>(W+2));
  for(int i=0;i<W+2;i++){
    ans.at(0).at(i) = '#';
    ans.at(H+1).at(i) = '#';
  }
  for(int i=1;i<H+1;i++){
    ans.at(i).at(0) = '#';
    ans.at(i).at(W+1) = '#';
    for(int j=1;j<W+1;j++){
      ans.at(i).at(j) = data.at(i-1).at(j-1);
    }
  }
  for(int i=0;i<H+2;i++){
    for(int j=0;j<W+2;j++){
      cout<<ans.at(i).at(j);
    }
    cout<<endl;
  }
}