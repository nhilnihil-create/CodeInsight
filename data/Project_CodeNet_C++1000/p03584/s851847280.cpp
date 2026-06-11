#include <bits/stdc++.h>
using namespace std;

//const double PI = acos(-1);
using ll = long long;
using ull = unsigned long long;
const int inf = 2e9;
const ll INF = 4e18;
const ll MOD = 1e9+7;

int n, k;
int a[100010];
ll b[100010];

ll f(int mask) {
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if ((a[i]|mask) == mask) ans += b[i];
  }
  return ans;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

  int mask = 0;
  ll ans = 0;
  for (int i = 30; i >= 0; i--) {
    if (k & (1<<i)) {
      mask += (1<<i);
      ans = max(ans, f(mask-1));
    }
  }
  cout << max(ans, f(k)) << endl;
  return 0;
}
