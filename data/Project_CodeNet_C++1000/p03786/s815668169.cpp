#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) cin >> A[i];
  sort(A.begin(), A.end());
  long long ans = 1;
  for (int i = 0; i < N - 1; i++) {
    if (A[i + 1] <= A[i] * 2) {
      ans++;
    } else
      ans = 1;
    A[i + 1] += A[i];
  }
  cout << ans << endl;
}