#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  int res = 0, maxi = 0;
  for (int i = 0; i < N; i++) {
    int a, b;
    cin >> a >> b;
    if (a > maxi) {
      maxi = a;
      res = a + b;
    }
  }
  cout << res << '\n';
  return 0;
}
