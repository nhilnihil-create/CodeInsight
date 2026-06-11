#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;
  vector<long long> a(N), b(N), c(M), d(M), checkpoint(N, 0);
  for (int i = 0; i < N; ++i) {
    cin >> a.at(i) >> b.at(i);
  }
  for (int i = 0; i < M; ++i) {
    cin >> c.at(i) >> d.at(i);
  }

  for (int i = 0; i < N; ++i) {
    long long min_place = 1000000000;
    for (int j = 0; j < M; ++j) {
      long long place = abs(a.at(i) - c.at(j)) + abs(b.at(i) - d.at(j));
      if (min_place > place) {
        checkpoint.at(i) = j + 1;
        min_place = place;
      }
    }
  }

  for (int i = 0; i < N; ++i) {
    cout << checkpoint.at(i) << endl;
  }

  return 0;
}
