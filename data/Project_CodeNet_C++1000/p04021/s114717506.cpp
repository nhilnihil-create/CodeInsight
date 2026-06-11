#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> A(N), B;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i % 2 == 0) B.emplace_back(A[i]);
  }
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  int res = 0;
  for (int i = 1; i < N; i += 2) {
    if (binary_search(B.begin(), B.end(), A[i])) res++;
  }
  cout << res << '\n';
  return 0;
}
