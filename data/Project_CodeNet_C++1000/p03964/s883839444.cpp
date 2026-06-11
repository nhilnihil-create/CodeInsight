#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1e16;
const ll mod = 1000000007;
#define rep(i, n) for (int i = 0; i < (ll)(n); i++)

int main() {
  ll n; cin >> n;
  ll t_1, t_2; cin >> t_1 >> t_2;
  rep(i, n-1) {
    ll a, b; cin >> a >> b;
    if (a == b) {
      t_1 = max(t_1, t_2);
      t_2 = t_1;
    } else if (a < b) {
      ll s_1 = t_1, s_2 = t_2;
      if (s_1%a) {
        s_1 = a*(s_1/a + 1);
      }
      if (s_1/a*b >= s_2) {
        t_1 = s_1; t_2 = s_1/a*b;
      } else {
        if (s_2%b) {
          s_2 = b*(s_2/b + 1);
        }
        t_1 = a*(s_2/b); t_2 = s_2;
      }
    } else {
      ll s_1 = t_1, s_2 = t_2;
      if (s_2%b) {
        s_2 = b*(s_2/b + 1);
      }
      if (s_2/b*a >= s_1) {
        t_1 = s_2/b*a; t_2 = s_2;
      } else {
        if (s_1%a) {
          s_1 = a*(s_1/a + 1);
        }
        t_1 = s_1; t_2 = b*(s_1/a);
      }
    }
  }
  cout << t_1 + t_2 << endl;
}