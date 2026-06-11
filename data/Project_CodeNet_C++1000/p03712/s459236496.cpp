#include <bits/stdc++.h>
using namespace std;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> a(H, vector<char>(W)), b(102, vector<char>(102));
  
  
  for (int i=0; i<102; i++){
    for (int j=0; j<102; j++){
      b.at(i).at(j) = '#';
    };
  };
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      cin >> a.at(i).at(j);
    };
  };
  for (int i=0; i<H; i++){
    for (int j=0; j<W; j++){
      b.at(i+1).at(j+1) = a.at(i).at(j);
    };
  };
  for (int i=0; i<H+2; i++){
    for (int j=0; j<W+2; j++){
      if (j==W+1){
        cout<<b.at(i).at(j)<<endl;
      }else{
        cout<<b.at(i).at(j);
      }
    };
  };
  
}