#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> l(N);
  for (int i{}; i < N; ++i) {
    cin >> l[i];
  }
  sort(l.begin(), l.end(), greater<int>());
  int ans{};
  for (int i{}; i < K; ++i) {
    ans += l[i];
  }
  cout << ans << endl;
  return 0;
}
