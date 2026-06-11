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

#define ull unsigned long long
void solve() {
  string s; cin >> s;
  int n = s.size();
  for (int count=2; count<n; count += 2) {
    string s2 = s.substr(0, n-count);
    int m = s2.size()/2;
    if (s2.substr(0, m) == s2.substr(m)) {
      cout << m*2 << endl;
      return;
    }
  }
  cout << -1 << endl;
}
