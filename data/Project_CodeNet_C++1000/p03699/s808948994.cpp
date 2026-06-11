#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  long long sum = 0;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    if (x % 10) {
      a.push_back(x);
    }
    sum += x;
  }
  sort (a.begin(), a.end());
  for (auto x : a) {
    if (sum % 10) break;
    sum -= x;
  }
  if (sum % 10 == 0) {
    sum = 0;
  }
  cout << sum;

}
