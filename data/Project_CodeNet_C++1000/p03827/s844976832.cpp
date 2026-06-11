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
  int N;
  string S;
  cin >> N >> S;

  int x=0;
  int max_x=0;
  for(int i=0;i<S.size();i++){
    if(S.at(i)=='I') ++x;
    else --x;
    max_x=max(max_x,x);
  }

  cout << max_x << endl;
  
  return 0;
}
