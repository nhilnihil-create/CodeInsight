#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  // 単純に国ごとのカウントをすればそれが道路の本数となる
  vector<int> counts(N, 0);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    counts[--a]++;
    counts[--b]++;
  }

  for (int c : counts) {
    cout << c << endl;
  }
}