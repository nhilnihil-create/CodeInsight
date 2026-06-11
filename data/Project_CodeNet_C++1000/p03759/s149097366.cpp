#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  puts(b - a == c - b ? "YES" : "NO");

  return 0;
}