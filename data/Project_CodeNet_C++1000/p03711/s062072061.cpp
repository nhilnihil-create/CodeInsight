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

#include <set>
void solve() {
  int x, y; cin >> x >> y;
  set<int> S1 { 1, 3, 5, 7, 8, 10, 12 };
  set<int> S2 { 4, 6, 9, 11 };
  set<int> S3 { 2 };
  
  auto f = [&](int x) {
    if (S1.count(x)) return 0;
    if (S2.count(x)) return 1;
    return 2;
  };
  
  vector<string> A { "No", "Yes" };
  cout << A[f(x) == f(y)] << endl;
}
