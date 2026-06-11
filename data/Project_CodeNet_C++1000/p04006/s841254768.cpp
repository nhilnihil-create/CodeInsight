// by newbiechd
#include <bits/stdc++.h>
using namespace std;

#define debug(x) cerr << #x << " = " << x << endl

const int N_MAX = 2003;
int a[N_MAX], b[N_MAX], c[N_MAX];
long long dp[N_MAX];
int que[N_MAX], head, tail;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin >> n >> m;
  int mnIdx = 1;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (a[i] < a[mnIdx])
      mnIdx = i;
  }
  for (int i = mnIdx; i <= n; ++i)
    b[i - mnIdx + 1] = a[i];
  for (int i = 1; i < mnIdx; ++i)
    b[i + n - mnIdx + 1] = a[i];
  long long ans = 0x3f3f3f3f3f3f3f3f;
  memcpy(c + 1, b + 1, sizeof(b[0]) * n);
  for (int l = 1; l <= n; ++l) {
    long long temp = 0;
    for (int i = 1; i <= n; ++i)
      temp += c[i];
    ans = std::min(1ll * m * (l - 1) + temp, ans);
    for (int i = l + 1; i <= n; ++i)
      c[i] = std::min(b[i - l], c[i]);
  }
  cout << ans << endl;
  return 0;
}
