/**
 * author: moririn_cocoa       
**/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

int main(void) {
  
  int A;
  int B;
  int C;
  int D;
  
  cin >> A;
  cin >> B;
  cin >> C;
  cin >> D;
  
  if ( A * B >= C * D ) {
    
    cout << A * B << endl;
  }
  
  else {
    
    cout << C * D << endl;
  }
  
  return 0;
}