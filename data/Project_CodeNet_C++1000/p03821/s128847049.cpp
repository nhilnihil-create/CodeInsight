#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll ans = 0;
  for (int i = N - 1; i >= 0; i--) {
    if (i == N - 1 && (A[i] == 0 || A[i] % B[i] == 0)) continue;
    A[i] += ans;
    if (A[i] != 0 && A[i] % B[i] != 0) {
      ans += B[i] - (A[i] % B[i]);
    }
  }
  cout << ans << endl;
  return 0;
}
