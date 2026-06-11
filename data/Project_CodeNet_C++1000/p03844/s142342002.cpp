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
  string op;
  int B;
  
  cin >> A;
  cin >> op;
  cin >> B;
  
  if ( op == "+" ) {
   
    cout << A + B << endl;
  }

  else if ( op == "-" ) {
    
    cout << A - B << endl;
  }
	
  return 0;
}