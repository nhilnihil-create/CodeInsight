#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD = 1000000007;

int main() {
  ll N, M;
  cin >> N >> M;
  ll ans = min(N, M/2);
  if (M<2) ans = 0LL;
  else if (M-2*N>=4) ans += (M-2*N)/4;
  cout << ans << endl;
}