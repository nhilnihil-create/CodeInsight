#include <bits/stdc++.h>
using namespace std;

int main() {
  long N, A, B;
  cin >> N >> A >> B;
  if (A > B) return cout << 0 << "\n", 0;
  if (N == 1 && A != B) return cout << 0 << "\n", 0;
  long mx = A + B * (N - 1);
  long mi = A * (N - 1) + B;
  cout << mx - mi + 1 << "\n";
}