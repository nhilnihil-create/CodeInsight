#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> L(N*2);
  for (int i = 0; i < N*2; i++) cin >> L.at(i);
  sort(L.begin(), L.end());

  int ans = 0;
  for (int i = 0; i < 2 * N - 1; i += 2) {
    ans += min(L.at(i), L.at(i + 1));
  }

  cout << ans << endl;
}