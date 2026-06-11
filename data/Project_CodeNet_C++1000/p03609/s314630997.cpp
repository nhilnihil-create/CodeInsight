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

int main(int argc, char* argv[]) {

  int X;
  int t;
  
  cin >> X;
  cin >> t;
  
  if ( X > t ) {
    
    cout << X - t << endl;
  }
  
  else if ( X <= t ) {
    
    cout << 0 << endl;
  }
  
  return 0;
}



