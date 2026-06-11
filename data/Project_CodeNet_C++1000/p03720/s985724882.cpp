#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> cnt(2 * M);
  for (int i = 0; i < 2 * M; i++) {
    cin >> cnt.at(i);
  }
  vector<int> count(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 2 * M; j++) {
      if (i + 1 == cnt.at(j)) count.at(i)++;
    }
  }
  for (int i = 0; i < N; i++) cout << count.at(i) << endl;
}
