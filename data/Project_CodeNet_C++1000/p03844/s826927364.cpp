#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  string op;
  cin >> A >> op >> B;

  if (op == "+")
    cout << A + B << endl;
  else
    cout << A - B << endl;
  return 0;
}