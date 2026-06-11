#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  string S1, S2; cin >> S1 >> S2;
  long long ans = 1;
  long long MOD = 1000000007;
  for (int i = 0; i < N; i++) {
    if (i == 0) {
      if (S1.at(0) == S2.at(0)) ans *= 3;
      else { ans *= 6; i++; }
    }
    else if (S1.at(i) == S2.at(i)) {
      if (S1.at(i-1) == S2.at(i-1)) { ans *= 2; ans %= MOD; }
    }
    else {
      if (S1.at(i-1) == S2.at(i-1)) { ans *= 2; ans %= MOD; }
      else { ans *= 3; ans %= MOD; }
      i++;
    }
  }
  cout << ans << endl;
}