#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n, k;
  cin >> n >> k;
  map<int, long long> num;
  for (int i = 0; i < n; i++) {
    int i1, i2;
    cin >> i1 >> i2;
    num[i1] += i2;
  }
  long long total = 0;
  for (auto x : num) {
    total += x.second;
    if (total >= k) {
      cout << x.first << endl;
      break;
    }
  }
}