#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  if (N == 1) {
    int a;
    cin >> a;
    cout << a/2 << endl;
    return 0;
  }
  ll A[N];
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N; i++) {
  ans += (A[i-1] + A[i]) / 2;
  if (A[i-1] == 1 && A[i] == 0) {
    continue;
  }
    if ((A[i-1] + A[i]) % 2 == 0) {
      A[i-1] = 0;
      A[i] = 0;
    } else {
      A[i-1] = 0;
      A[i] = 1;
    }
  }
  cout << ans << endl;
  return 0;
}