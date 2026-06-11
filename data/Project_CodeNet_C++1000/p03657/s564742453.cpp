/**
 * auther: moririn_cocoa
 */

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
#include <stdio.h>
#include <stdlib.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
#define fi first
#define se second


int main(int argc, const char * argv[]) {
  
  int A;
  int B;
  
  cin >> A;
  cin >> B;
  
  if ( A % 3 == 0 ) {
    
    cout << "Possible" << endl;
  }
  
  else if ( B % 3 == 0 ) {
    
    cout << "Possible" << endl;
  }
  
  else if ( ( A + B ) % 3 == 0 ) {
    
    cout << "Possible" << endl;
  }
  
  else {
    
    cout << "Impossible" << endl;
  }
  
  return 0;
}
