#include <bits/stdc++.h>
using namespace std;

int main() {
  int A = 0, B = 0;
  char op = 0;
  cin >> A >> op >> B;
  int ans = 0;
  if (op == '+') {
    ans = A+B;
  } else {
    ans = A-B;
  }
  cout << ans << endl;
}
