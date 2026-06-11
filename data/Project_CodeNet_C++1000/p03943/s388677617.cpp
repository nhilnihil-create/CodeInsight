#include <bits/stdc++.h>

using namespace std;

int main(int argc, const char *argv[]) {
  int a, b, c;
  cin >> a >> b >> c;

  int total = a + b + c;
  if (total % 2 == 1) {
    cout << " No" << '\n';
  } else {
    int half = total / 2;
    bool ans = a == half || b == half || c == half;
    cout << (ans ? "Yes" : "No") << '\n';
  }
  return 0;
}