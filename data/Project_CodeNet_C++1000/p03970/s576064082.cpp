#include <bits/stdc++.h>

#define REP(i, x) REPI(i, 0, x)
#define REPI(i, a, b) for (int i = int(a); i < int(b); ++i)
#define ALL(x) (x).begin(), (x).end()

typedef long long ll;
using namespace std;

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  string S;
  cin >> S;
  string correct = "CODEFESTIVAL2016";
  int l = S.length();
  int ans = 0;
  REP(i, l) {
    if (S[i] != correct[i]) {
      ++ans;
    }
  }

  cout << ans << endl;

  return 0;
}
