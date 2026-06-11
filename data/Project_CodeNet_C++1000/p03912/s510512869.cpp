#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
const double eps = 1e-10;
const int MOD = 1000000007;
const int INF = 1000000000;
const ll LINF = 1ll<<50;
template<typename T>
void printv(const vector<T>& s) {
  for(int i=0;i<(int)(s.size());++i) {
    cout << s[i];
    if(i == (int)(s.size())-1) cout << endl;
    else cout << " ";
  }
}
int main() {
  cin.tie(0);
  cout << fixed << setprecision(10);
  ll n, m; cin >> n >> m;
  vector<ll> x(n);
  for(int i=0;i<n;++i) {
    cin >> x[i];
  }
  sort(x.begin(), x.end());
  vector<ll> v(m), odd(m);
  ll now = x[0];
  ll cnt = 1;
  for(int i=1;i<n;++i) {
    if(x[i] == x[i-1]) {
      cnt++;
    } else {
      v[now%m] += cnt;
      odd[now%m] += cnt % 2;
      now = x[i];
      cnt = 1;
    }
  }
  v[now%m] += cnt;
  odd[now%m] += cnt % 2;
  ll ans = n;
  ans -= odd[0]%2;
  for(int i=1;i<=m/2;++i) {
    if(i * 2 == m) {
      ans -= odd[i]%2;
    } else {
      if(odd[i] > odd[m-i]) {
        odd[i] -= odd[m-i];
        ans -= odd[i] % 2;
        odd[i] -= odd[i] % 2;
        ans -= max(0ll, odd[i] - (v[m-i] - odd[m-i]));
      } else if(odd[m-i] > odd[i]) {
        odd[m-i] -= odd[i];
        ans -= odd[m-i] % 2;
        odd[m-i] -= odd[m-i] % 2;
        ans -= max(0ll, odd[m-i] - (v[i] - odd[i]));
      }
    }
  }
  cout << ans / 2 << endl;
}
