#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, T, A, mi;
  cin >> N >> T >> mi;
  map<int, int> MA;
  while (cin >> A) {
    if (A > mi) MA[A - mi]++;
    mi = min(mi, A);
  }
  cout << MA.rbegin() -> second << "\n";
}