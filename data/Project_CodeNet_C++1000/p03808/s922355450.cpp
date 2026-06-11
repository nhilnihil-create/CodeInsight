#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define maxn 200010

ll a[maxn];
ll n;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//  freopen("abc.inp", "r", stdin); freopen("abc.out", "w", stdout);
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  ll sum; sum = accumulate(a + 1, a + n + 1, 0ll);
  if (sum % (n * (n+1) / 2)) {
    cout << "NO";
    return 0;
  }
  ll cnt = sum / (n * (n+1) / 2);
  a[n+1] = a[1];
  for (int i = 1; i <= n; ++i) {
    ll dif = a[i] - a[i+1];
    if (dif + cnt < 0 || (dif + cnt) % n) {
      cout << "NO";
      return 0;
    }
  }
  cout << "YES";
  return 0;
}
/// :D
