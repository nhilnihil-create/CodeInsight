#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int A, B;
  cin >> A >> B;

  if (A + B >= 10)
    cout << "error" << endl;
  else
    cout << A + B << endl;
  return 0;
}