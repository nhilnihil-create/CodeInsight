#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;

  cin >> N >> M;

  vector<int> a(M), b(M);
  vector<int> count(N);

  for (int i = 0; i < M; i++) {
    cin >> a.at(i) >> b.at(i);
    count.at(a.at(i) - 1)++;
    count.at(b.at(i) - 1)++;
  }

  for (int i = 0; i < N; i++) {
    cout << count.at(i) << endl;
  }
}
