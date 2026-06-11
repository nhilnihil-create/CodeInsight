#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  vector<long long> A(N);
  for (int i = 0; i < N; ++i) cin >> A[i];
  sort(A.begin(), A.end(), greater<long long>());
  long long res = 0;
  for (int i = 0; i < K; ++i) res += A[i];
  cout << res << endl;
}