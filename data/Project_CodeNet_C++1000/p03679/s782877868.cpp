#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int x, a, b;
  cin >> x >> a >> b;

  if (a >= b) {
    puts("delicious");
    return 0;
  }

  if (b - a <= x) {
    puts("safe");
    return 0;
  }

  puts("dangerous");
  return 0;
}