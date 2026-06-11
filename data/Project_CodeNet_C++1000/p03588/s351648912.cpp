#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int A = 0, B = 1000000007, ans = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > A) {
      A = a;
      B = b;
      ans = a + b;
    }
  }
  cout << ans << endl;
}