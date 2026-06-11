#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }
  
  long long ans = 0;
  int a, res = 0;
  for (int i = 0; i < N; i++) {
    a = A.at(i) - res;
    if (a < 0) {
      res = 0;
      continue;
    }
    ans += res;
    ans += a / 2;
    res = a % 2;
  }
  cout << ans << endl;
}
