///////////////////////////////////////////////////////////////////////////
// /*Dis = size of the program || TLE. */
/*
#ifndef LOCAL
#pragma GCC optimize("O3")
#endif
*/
// #pragma GCC target("avx,avx2,fma")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//#pragma GCC optimize("unroll-loops") /* D = Too many loops */
#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;
#define endl '\n'
#define mod 1000000007
typedef long long ll;
//////////////////////////////////////////////////////////////////////////
/* Custom function starts here */

/* Custom function ends here: */
//////////////////////////////////////////////////////////////////////////////

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.precision(20);

  /* MAIN Code STARTS here: */
  long long a, b, x;
  cin >> a >> b >> x;

  if (a % x == 0) {
    cout << ((b / x) - (a / x) + 1) << endl;
  } else {
    cout << ((b / x) - (a / x)) << endl;
  }

  /* MAIN Code ENDS here: */
  cerr << "\nTime elapsed: " << 1000 * clock() / CLOCKS_PER_SEC << "ms\n";
}

/*!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!*/