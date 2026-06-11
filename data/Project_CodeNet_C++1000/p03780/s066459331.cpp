#include <bits/stdc++.h>
using namespace std;
const int maxN = 5e3 + 10;
typedef long long ll;

int n, k;
int a[maxN];
bool dp[2][maxN];
int pre[maxN];

bool ok(int mid) {
  if (k <= a[mid]) return true;
  bitset<5000> bs;
  bs.set(0, 1);

  for (int i = 1; i <= n; ++i) {
    if (i == mid) continue;
    bs = bs | (bs << a[i]);
  }
  int l = k - a[mid], r = k - 1;

  for (int i = l; i <= r; ++i) {
    if (bs.test(i) == 1) return true;
  }
  return false;
}

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n >> k;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  sort(a+1, a+n+1);
  int l = 1, r = n;
  while (l <= r) {
    int mid = (l + r) / 2;
    if (ok(mid)) r = mid - 1;
    else l = mid + 1;
  }
  cout << r << '\n';
  return 0;
}
