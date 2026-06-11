#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll Mod = 1000000007;

int main() {
  int N;
  cin >> N;
  int L[2 * N];
  for (int i = 0; i < 2 * N; i++) {
    cin >> L[i];
  }
  sort(L,L+(2*N));
  int ans = 0;
  for (int i = 0; i < N; i++) {
    ans += L[2 * i];
  }
  cout << ans << endl;
  return 0;
}