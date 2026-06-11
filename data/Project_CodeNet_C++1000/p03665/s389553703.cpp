#include <iostream>
using namespace std;

long long nCr (const int &n, int r) {
  if (r == 0) return 1;

  long long ret = 1;
  if (r > n-r) r = n-r;

  for (int i = n-r+1; i <= n; i++) ret *= i;
  for (int i = r; i > 0; i--) ret /= i;

  return ret;
}

int main() {
  int n, p;
  cin >> n >> p;

  int cnt[] = {0, 0};

  for (int i = 0; i < n; i++) {
    int tmp;
    cin >> tmp;
    cnt[tmp%2]++;
  }

  long long ans = 0;
  for (int i = p; i <= cnt[1]; i += 2) {
    ans += (1LL << cnt[0]) * nCr(cnt[1], i);
  }

  cout << ans << endl;
  return 0;
}