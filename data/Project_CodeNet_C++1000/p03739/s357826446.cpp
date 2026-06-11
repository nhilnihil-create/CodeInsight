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
ll psum1[100005], psum2[100005];
int main() {
  IOS;
  ll sum = 0, ans1 = 0, ans2 = 0;
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    psum1[i] = psum1[i - 1] + a[i];
    psum2[i] = psum2[i - 1] + a[i];
    if (i % 2 == 1 && psum1[i] <= 0)
      ans1 += 1 - psum1[i], psum1[i] = 1;
    else if (i % 2 == 0 && psum1[i] >= 0)
      ans1 += psum1[i] + 1, psum1[i] = -1;
    if (i % 2 == 0 && psum2[i] <= 0)
      ans2 += 1 - psum2[i], psum2[i] = 1;
    else if (i % 2 == 1 && psum2[i] >= 0)
      ans2 += psum2[i] + 1, psum2[i] = -1;
  }
  cout << min(ans1, ans2) << endl;
}