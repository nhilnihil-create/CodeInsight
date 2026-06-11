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
  string S;
  cin >> S;

  vector<int> NWSE(4,-1);
  for(int i=0;i<S.size();++i){
    if(S.at(i)=='N') NWSE.at(0)=1;
    if(S.at(i)=='W') NWSE.at(1)=1;
    if(S.at(i)=='S') NWSE.at(2)=1;
    if(S.at(i)=='E') NWSE.at(3)=1;
  }

  string ans="Yes";
  for(int i=0;i<2;++i){
    if(NWSE.at(i)*NWSE.at(i+2)<0) ans="No";
  }

  cout << ans << endl;
  
  return 0;
}
