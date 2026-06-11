#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int x, a, b;
  cin >> x >> a >> b;
  int dist_a = abs(x - a), dist_b = abs(x - b);
  if (dist_a < dist_b) {
    cout << "A" << '\n';
  } else {
    cout << "B" << '\n';
  }

  return 0;
}