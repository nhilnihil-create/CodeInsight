#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < n; i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int n;
  cin >> n;
  ll d = 1e9+7;
  int zero = 0;
  vector<int> vec(1e5+1, 0);
  rep(i, n) {
    int x;
    cin >> x;
    vec[x]++;
  }
  int l = n - 1;
  bool ok = true;
  int cnt = 0;
  while(l > 0) {
    cnt++;
    if (vec[l] != 2) {
      ok = false;
      break;
    }
    l -= 2;
  }
  if (n%2 && vec[0] != 1) {
    ok = false;
  }
  if (ok) {
    ll ans = 1;
    rep(i, cnt) {
      ans *= 2;
      ans %= d;
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}