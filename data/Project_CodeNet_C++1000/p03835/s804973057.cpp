#include <bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i=(a); i<(b); i++)

int main() {
  int K,S;
  cin >> K >> S;
  int ans = 0;
  FOR(x,0,K+1) {
    FOR(y,0,K+1) {
      if ((0 <= S-x-y) && (S-x-y <= K)) ans++;
    }
  }
  cout << ans << endl;
  return 0;
}