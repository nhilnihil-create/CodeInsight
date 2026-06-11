#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> button(N);
  for (int i=0; i < N; i++) {
    cin >> button.at(i);
    button.at(i) = button.at(i) - 1;
  }
  int ans, kasu, TLE;
  ans = 0;
  kasu = button.at(0);
  TLE = N + 10;
  for (int i=0; i < TLE; i++) {
    ans = i + 1;
    if (kasu == 1) {
      cout << ans << endl;
      break;
    }
    kasu = button.at(kasu);
  }
  if (ans == TLE) {
    cout << "-1" << endl;
  }
}