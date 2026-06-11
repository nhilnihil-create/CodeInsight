#include <bits/stdc++.h>

using namespace std;

int main() {
  int x;
  cin >> x;
  int n = 0, sum = 0;
  while (sum < x) {
    n++;
    sum += n;
  }
  cout << n << '\n';
  return 0;
}