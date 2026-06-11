#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K; cin >> N >> K;
  vector<int> A(N); for (auto &x : A) cin >> x;
  sort(A.begin(), A.end(), greater<int>());
  int ans = 0;
  for (int i = 0; i < K; i++) {
    ans += A[i];
  }
  cout << ans << endl;
}