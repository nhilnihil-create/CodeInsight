#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<bool> S(N);
  for (int i = 0; i < N; i++) {
    char s;
    cin >> s;
    S[i] = s == 'o';
  }
  for (int t = 0; t < (1 << 2); t++) {
    vector<bool> T(N);
    T[0] = (t & 1) == 1;
    T[1] = ((t >> 1) & 1) == 1;
    for (int i = 2; i < N; i++) {
      T[i] = S[i - 1] ^ T[i - 1] ^ T[i - 2];
    }
    if (S[N - 1] == (T[N - 2] ^ T[N - 1] ^ T[0]) &&
        S[0] == (T[N - 1] ^ T[0] ^ T[1])) {
      for (int i = 0; i < N; i++) {
        cout << (T[i] ? 'S' : 'W');
      }
      cout << '\n';
      return 0;
    }
  }
  cout << -1 << '\n';
  return 0;
}
