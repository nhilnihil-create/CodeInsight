#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int a;
  int b;
  string op;
  int ans;
  cin >> a >> op >> b;

  if (op == "+") {
    ans = a + b;
  } else {
    ans = a - b;
  }
  cout << ans << endl;
}
