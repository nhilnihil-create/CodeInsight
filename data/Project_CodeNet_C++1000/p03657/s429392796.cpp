#include <bits/stdc++.h>
#define sz(arr) (int)arr.size()

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;

  puts(a % 3 == 0 || b % 3 == 0 || (a + b) % 3 == 0 ? "Possible"
                                                    : "Impossible");

  return 0;
}