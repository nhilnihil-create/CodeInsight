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
  
  cin >> A;
  cin >> B;
  cin >> C;
  
  if ( A <= C && C <= B ) {
    
    cout << "Yes" << endl;
  }
  
  else {
    
    cout << "No" << endl;
  }
  
  return 0;
}
