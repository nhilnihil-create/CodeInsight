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
  vector<ll> A(3);
  cin >> A[0] >> A[1] >> A[2];
  sort(A.begin(),A.end());

  if(A.at(0)%2==0 || A.at(1)%2==0 || A.at(2)%2==0) cout << 0 << endl;
  else cout << A.at(0)*A.at(1) << endl;
  
  return 0;
}
