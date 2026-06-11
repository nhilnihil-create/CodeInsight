#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N];
  ll now[N];
  ll ans = 0;
  now[0] = 1;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N; i++) {
    if (A[i] == now[i-1] + 1) {
      now[i] = now[i-1] + 1;
    } else {
      now[i] = now[i-1];
    }
  }
  ans += (A[0] - 1);
  for (int i = 1; i < N; i++) {
    ans += (A[i] - 1) / (now[i] + 1);
  }
  cout << ans << endl;
  return 0;
}