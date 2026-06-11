#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N, K;
  cin >> N >> K;
  vector<int> x(N);
  int mid = K/2;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    cin >> x[i];
    if (x[i] > mid) ans += 2*(K-x[i]);
    else ans += 2*x[i];
  }
  cout << ans << endl;
}
