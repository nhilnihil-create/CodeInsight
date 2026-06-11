/*
 * atcoder/abc089/b.cpp
 */

// C++ 14
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring> // memset
#include <cassert>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve();
int main() { solve(); return 0; }

#define ld long double
void solve() {
  int n=3;
  vector<string> S(n);
  loop(i,0,n) cin >> S[i];
  loop(i,0,n) cout << (char)toupper(S[i][0]);
  cout << endl;
}
