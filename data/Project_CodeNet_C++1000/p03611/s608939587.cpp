#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) cin >> A.at(i);
  vector<int> V(1e5);
  for (int i = 0; i < N; i++) {
    V.at(A.at(i))++;
  }
  int ans = 0;
  for (int i = 0; i + 2 < 1e5; i++) {
    ans = max(ans, V.at(i) + V.at(i + 1) + V.at(i + 2));
  }
  cout << ans << "\n";
}