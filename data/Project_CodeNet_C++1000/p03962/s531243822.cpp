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
  
  int a;
  int b;
  int c;
  
  cin >> a;
  cin >> b;
  cin >> c;
  
  if ( a == b && b == c ) {
    
    cout << 1 << endl;
  }
  
  else if ( a != b && b != c && a != c ) {
    
    cout << 3 << endl;
  }
  
  else {
    
    cout << 2 << endl;
  }
	

return 0;
}
