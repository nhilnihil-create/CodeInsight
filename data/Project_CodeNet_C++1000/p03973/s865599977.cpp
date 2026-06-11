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
  int n; cin >> n;
  vector<ll> a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
  }
  ll ans = a[0] - 1;
  ll now = 2;
  for(int i=1;i<n;++i) {
    if(a[i] == now) {
      now++;
    } else {
      ans += (a[i] - 1) / now;
    }
  }
  cout << ans << endl;
}
