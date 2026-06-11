#ifdef ConanYu
#include "local.hpp"
#else
#pragma GCC optimize("-O3")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void Main();
#define debug(...) do { } while(0)
int main() {
  ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  Main();
}
#endif

const int N = 105;
int a[N << 1];

void Main() {
  int n; cin >> n;
  for(int i = 0; i < 2 * n; i++) {
    cin >> a[i];
  }
  sort(a, a + 2 * n);
  int ans = 0;
  for(int i = 0; i < n; i++) {
    ans += a[i * 2];
  }
  cout << ans << "\n";
}
