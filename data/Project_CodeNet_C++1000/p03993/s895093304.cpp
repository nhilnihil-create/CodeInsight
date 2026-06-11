#include <bits/stdc++.h>
#define IOS                                                                    \
  ios::sync_with_stdio(0);                                                     \
  cin.tie(0);                                                                  \
  cout.tie(0)
#define pb push_back
#define ff first
#define ss second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
using namespace std;
using ll = long long;
using vi = vector<int>;
using pii = pair<ll, ll>;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fLL;
ll bpow(ll b, ll p, ll m = 1000000007LL) {
  ll rt = 1;
  for (; p; p >>= 1, b = b * b % m)
    if (p & 1)
      rt = rt * b % m;
  return rt;
}
ll a[100005];
ll ans = 0;
int main() {
  IOS;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int i = 1; i <= n; i++) {
    if (i == a[a[i]]) {
      ans++;
    }
  }
  cout << ans / 2 << endl;
}
