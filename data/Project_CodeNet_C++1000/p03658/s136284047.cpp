#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, k;
  cin >> n >> k;

  vector<int> l(n);
  for (int i = 0; i < n; ++i) {
    cin >> l.at(i);
  }
  sort(l.begin(), l.end());

  int leng = 0;
  for (int i = 0; i < k; ++i) {
    leng += l.at(n - 1 - i);
  }
  cout << leng << endl;
}