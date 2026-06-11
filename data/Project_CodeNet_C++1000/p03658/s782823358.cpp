#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L.at(i);
  sort(L.rbegin(), L.rend());
  cout << accumulate(L.begin(), L.begin() + K, 0L) << "\n";
}