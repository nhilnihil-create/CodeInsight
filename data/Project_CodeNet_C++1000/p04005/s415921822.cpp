#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ll A, B, C;
  cin >> A >> B >> C;
  if (A % 2 == 0 || B % 2 == 0 || C % 2 == 0) {
    cout << 0 << endl;
    return 0;
  }
  if (A < B) swap(A, B);
  if (A < C) swap(A, C);
  cout << B * C << endl;
}