#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int a[199999];
bool b[199999];
bool ok(int k) {
  for (int i = 0; i < 2 * n - 1; ++i) {
    b[i] = a[i] >= k;
  }
  
  vector<pair<bool, bool>> v;
  for (int i = 0; i < n - 1; ++i) {
    v.push_back(make_pair(b[n - 1 + i], b[n + i]));
    v.push_back(make_pair(b[n - 1 - i], b[n - 2 - i]));
  }
  
  for (auto p : v) {
    if (p.first == p.second) return p.first;
  }
  
  return b[0];
}

int main() {
  cin >> n;
  for (int i = 0; i < 2 * n - 1; ++i) cin >> a[i];
  
  int lo = 0;
  int hi = 2 * n;
  
  while (hi - lo > 1) {
    int mid = (lo + hi) / 2;
    if (ok(mid)) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  
  cout << lo << endl;
}