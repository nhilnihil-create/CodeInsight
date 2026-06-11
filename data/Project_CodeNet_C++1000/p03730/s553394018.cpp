#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  int n = a;
  for (int i = 0; i < b; i++) {
    if (n % b == c) {
      puts("YES");
      return 0;
    }
    n += a;
  }
  puts("NO");
}