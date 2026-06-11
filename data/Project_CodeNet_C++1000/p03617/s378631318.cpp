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
  int Q,H,S,D,N;
  cin >> Q >> H >> S >> D >> N;
  int L1_cost=min(min(4*Q,2*H),S);
  int L2_cost=min(2*L1_cost,D);

  cout << (ll)L2_cost*(N/2)+(ll)L1_cost*(N%2) << endl;

  return 0;
}
