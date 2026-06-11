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
  cin >> N;
  vector<int> a(N);
  for(int i=0;i<N;++i){
    cin >> a.at(i);
    --a.at(i);
  }

  int next=0;
  int ans=0;
  while(1){
    ++ans;
    next=a.at(next);
    if(next==1) break;
    if(ans>N){
      ans=-1;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
