#include <bits/stdc++.h>
using namespace std;

int main() {
  int h,w;
  cin>>h>>w;
   vector<vector<string>> data(h, vector<string>(w));
 
  // 入力 (2重ループを用いる)
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      cin >> data.at(i).at(j);
    }
  }
  int gyo;
  char retu;
  string atoz="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (int i = 0; i < h; i++) {
    for (int j = 0; j < w; j++) {
      if(data.at(i).at(j)=="snuke"){
        gyo=i+1;
        retu=atoz.at(j);
      }
    }
  }
  cout<<retu<<gyo;
}