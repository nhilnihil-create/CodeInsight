#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#define MOD (1000000007l)
#define rep(i, n) for(long i = 0; i < n; i++)

using namespace std;

void solve() {
  string s;
  cin >> s;
  string foo = s.substr(0, 4);
  string bar = s.substr(4, 8);
  cout << foo << " " << bar << endl;
}

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout.precision(12);
  solve();
  return 0;
}
