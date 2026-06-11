#include <bits/stdc++.h>

using namespace std;

int main() {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<bool> W(30 + 35), S(3000 + 35);
  W[0] = S[0] = true;
  for (int i = 0; i <= 30; i++) {
    if (W[i]) {
      W[i + A] = W[i + B] = true;
    }
  }
  for (int i = 0; i <= 3000; i++) {
    if (S[i]) {
      S[i + C] = S[i + D] = true;
    }
  }
  int max_a = 100 * A, max_b = 0;
  auto chmax = [&](int a, int b) {
    // b / (a+b) > max_b / (max_a+max_b)
    if (b * (max_a + max_b) > max_b * (a + b)) {
      max_a = a;
      max_b = b;
    }
  };
  for (int i = 0; i <= 30; i++) {
    if (!W[i]) continue;
    for (int j = 0; j <= 3000; j++) {
      if (!S[j]) continue;
      if (i * E < j) continue;
      if (i * 100 + j > F) continue;
      chmax(i * 100, j);
    }
  }
  cout << max_a + max_b << " " << max_b << endl;

  return 0;
}
/* vim:set fdm=marker: */
