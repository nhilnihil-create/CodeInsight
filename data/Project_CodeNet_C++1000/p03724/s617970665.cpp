#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> V(N);
  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    V.at(a)++;
    V.at(b)++;
  }
  string ans = "YES";
  for (int i = 0; i < N; i++) {
    if (V.at(i) % 2 != 0) ans = "NO";
  }
  cout << ans << endl;
}