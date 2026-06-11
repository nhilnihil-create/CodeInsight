#include <stdlib.h>
#include <cmath>
#include <cstdio>
#include <cstdint>
#include <string>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long;

int main(){
  int H,W;
  cin >> H >> W;
  vector<vector<char>> C(H,vector<char>(W));

  for(int i=0;i<H;++i)
    for(int j=0;j<W;++j) cin >> C.at(i).at(j);

  for(int i=0;i<2*H;++i){
    for(int j=0;j<W;++j){
      cout << C.at(i/2).at(j);
    }
    cout << endl;
  }

  return 0;
}
