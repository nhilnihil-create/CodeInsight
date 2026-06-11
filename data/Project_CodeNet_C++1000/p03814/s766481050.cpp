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

  int A_index=-1,Z_index;
  for(int i=0;i<S.size();++i){
    if(S.at(i)=='A' && A_index==-1) A_index=i;
    if(S.at(i)=='Z') Z_index=i;
  }

  cout << Z_index-A_index+1 << endl;

  return 0;
}
