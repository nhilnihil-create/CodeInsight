#include <bits/stdc++.h>
using namespace std;

int main(){
  int w,h;
  cin >> h >> w;
  vector<vector<char>>hyo(h*2,vector<char>(w));
  for(int i=0;i<h;i++){
    for(int j=0;j<w;j++){
      cin >> hyo.at(i*2).at(j);
      hyo.at(i*2+1).at(j)=hyo.at(i*2).at(j);
    }
  }
  for(int i=0;i<h*2;i++){
    for(int j=0;j<w;j++){
      cout << hyo.at(i).at(j);
    }
    cout << endl;
  }
  exit(0);
}