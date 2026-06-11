#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> s(N);
  int score = 0;
  for (int i = 0; i < N; i++) {
    cin >> s[i];
    score += s[i];
  }
  if (score % 10 != 0) {
    cout << score << endl;
    return 0;
  }
  sort(s.begin(), s.end());
  int tmp = 999;
  for (int i = 0; i < N; i++) {
    if (s[i] % 10 != 0) {
      tmp = i;
      break;
    }
  }
  if (tmp == 999) cout << 0 << endl;
  else cout << score - s[tmp] << endl;
}
