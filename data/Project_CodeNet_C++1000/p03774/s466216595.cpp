#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  vector<int> a(N), b(N), c(M), d(M);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i) >> b.at(i);
  }
  for (int i = 0; i < M; i++) {
    cin >> c.at(i) >> d.at(i);
  }
  for (int i = 0; i < N; i++) {
    long long e = 10000000000, f, g;
    for (int j = 0; j < M; j++) {
      int h = a.at(i) - c.at(j), k = b.at(i) - d.at(j);
      if (h < 0) {h *= -1;}
      if (k < 0) {k *= -1;}
      f = h + k;
      if (e > f) {
        e = f;
        g = j + 1;
      }
    }
    cout << g << endl;
  }
}