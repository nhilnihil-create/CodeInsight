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
  int L,N;
  cin >> N >> L;
  vector<string> S(N);
  for(int i=0;i<N;++i) cin >> S.at(i);
  sort(S.begin(),S.end());

  for(int i=0;i<N;++i) cout << S.at(i);
  cout << endl;

  return 0;
}
