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
  ll ans=1;
  for(int i=1;i<=N;++i){
    ans=ans*i;
    if(100000000<ans) ans=ans%(1000000000+7);
  }

  cout << ans << endl;

  return 0;
}
