#include <bits/stdc++.h>

#include <iostream>
using namespace std;
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> ln(n);
  for (auto& li : ln) {
    cin >> li;
  }
  sort(ln.begin(), ln.end(), std::greater<int>());
  int total = 0;
  for (int i = 0; i < k; ++i) {
    total += ln[i];
  }
  cout << total << endl;
  return 0;
}
