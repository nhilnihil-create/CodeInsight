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
  //vector<set> like(N);
  int ans=0;
  for(int i=0;i<N;++i){
    cin >> a.at(i);
    --a.at(i);
    if(a.at(i)<i){
      if(a.at(a.at(i))==i) ++ans;
    }
  }

  cout << ans << endl;
  
  return 0;
}
