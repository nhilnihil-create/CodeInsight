#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll mod = 1000000007;
const ll INF = 9223372036854775807;
#define Sort(a) sort(a.begin(), a.end())
#define Bsort(a) sort(a.begin(), a.end(), greater<ll>())
#define Pi acos(-1)

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> n >> m;
  vector<ll> a(n);
  vector<ll> b(n);
  b[0]++;
  for (int i = 0; i < m; i++) {
    int p, q;
    cin >> p >> q;
    a[p-1]--;
    a[q-1]++;
    if (b[p-1] != 0) {
      if (a[p-1] == -1) {
        b[p-1] = 0;
        b[q-1]++;
      }
      else {
        b[q-1]++;
      }
    }
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (b[i] != 0) {
      ans ++;
    }
  }
  cout << ans << '\n';
}