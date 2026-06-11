// https://atcoder.jp/contests/abc050/tasks/abc050_a
#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  char c;
  cin >> A >> c >> B;

  (c == '+') ? cout << A + B : cout << A - B;
  return 0;
}
