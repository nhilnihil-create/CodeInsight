#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;

  if (A == 1) A += 13;
  if (B == 1) B += 13;

  if (A > B)
    cout << "Alice" << endl;
  else if (B > A)
    cout << "Bob" << endl;
  else
    cout << "Draw" << endl;
  return 0;
}