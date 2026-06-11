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
  int N,K;
  cin >> N >> K;

  cout << (ll)K*(ll)pow(K-1,N-1) << endl;

  return 0;
}
