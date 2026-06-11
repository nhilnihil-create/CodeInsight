#include <bits/stdc++.h>
using namespace std;

int main(void) {
  long long N, A, B;
  cin >> N >> A >> B;
  if (A > B) {
    cout << 0 << endl;
  } else if (N == 1) {
    cout << (A == B ? 1 : 0) << endl;
  } else {
    cout << (N - 2) * (B - A) + 1 << endl;
  }
  return 0;
}