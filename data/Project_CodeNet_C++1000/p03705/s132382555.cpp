#include <bits/stdc++.h>
using namespace std;

int main() {
  long long int N, A, B;
  cin >> N >> A >> B;
  if (N == 1 && A == B) cout << 1 << endl;
  else if (N == 1) cout << 0 << endl;
  else {
    long long int ans = (N - 2) * (B - A) + 1;
    if (ans > 0) cout << ans << endl;
    else cout << 0 << endl;
  }
}