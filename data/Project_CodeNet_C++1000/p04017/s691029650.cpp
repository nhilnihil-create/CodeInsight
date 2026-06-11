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
  vector<ll> x(n);
  for(int i=0;i<n;++i) {
    cin >> x[i];
  }
  ll l; cin >> l;
  vector<vector<int>> r(31, vector<int>(n));
  for(int i=0;i<n;++i) {
    auto it = upper_bound(x.begin(), x.end(), x[i] + l);
    int pos = distance(x.begin(), it);
    r[0][i] = pos - 1;
  }
  for(int i=1;i<31;++i) {
    for(int j=0;j<n;++j) {
      r[i][j] = r[i-1][r[i-1][j]];
    }
  }
  int q; cin >> q;
  while(q > 0) {
    q--;
    int a, b; cin >> a >> b;
    a--; b--;
    if(a > b) swap(a, b);
    int ans = 0;
    int now = a;
    for(int i=29;i>=0;--i) {
      if(r[i][now] < b) {
        ans += 1<<i;
        now = r[i][now];
      }
    }
    cout << ans + 1 << endl;
  }
}
