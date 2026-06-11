#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  string S;
  cin >> S;
  bool done = false;
  int hidari = 0;
  int migi = 0;
  while (!done) {
    hidari = 0;
    migi = 0;
    for (int i = 0; i < S.size(); i++) {
      if (S[i] == '(') {
        hidari++;
      } else {
        migi++;
      }
      if (migi > hidari) {
        S.insert(S.begin(), '(');
        break;
      }
      if (i == S.size() - 1) {
        done = true;
      }
    }
  }
  for (int i = 0; i < hidari - migi; i++) {
    S.insert(S.end(), ')');
  }
  cout << S << endl;
}