#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll N,K;
  cin >> N >> K;
  ll A[N];
  ll gcd = A[0];
  ll m = -1;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    m = max(A[i],m);
  }
  for (int i = 1; i < N; i++) {
    gcd = __gcd(gcd,A[i]);
  }
  //m - gcd * (n) = K に出来たらOK
  if (m >= K && (K - m) % gcd == 0) {
    cout << "POSSIBLE" << endl;
  } else {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
