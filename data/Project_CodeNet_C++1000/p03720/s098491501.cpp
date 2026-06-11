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
  int N,M;
  cin >> N >> M;
  vector<int> load(N);
  int a,b;
  for(int i=0;i<M;++i){
    cin >> a >> b;
    --a; --b;
    load.at(a)++;
    load.at(b)++;
  }

  for(int i=0;i<N;++i) cout << load.at(i) << endl;

  return 0;
}
