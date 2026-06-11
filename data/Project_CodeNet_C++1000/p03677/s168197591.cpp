#include <bits/stdc++.h>

using namespace std;

#define SZ(x) (int)(x.size())

using ll = long long;
using ld = long double;
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
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  int n, m; cin >> n >> m;
  vi a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
    a[i]--;
  }

  vector<ll> b(m);

  for(int i=0;i<n-1;++i) {
    if(a[i] != m-1) b[a[i]+1]--;
    b[a[i+1]]++;
    if(a[i] > a[i+1] && a[i] != 0) {
      b[0]--;
    }
  }

  vll su(m);
  su[0] = b[0];
  for(int i=1;i<m;++i) {
    su[i] = su[i-1] + b[i];
  }
  
  for(int i=1;i<n;++i) {
    su[a[i]] += (a[i] + m - a[i-1]) % m - 1;
  }
  //printv(su);

  ll ans = 0;
  for(int i=1;i<n;++i) {
    ans += min((a[i] + m - a[i-1]) % m, a[i] + 1);
  }
  //cout << ans << endl;

  ll mi = ans;
  for(int i=0;i<m;++i) {
    ans += su[i];
    mi = min(mi, ans);
  }
  cout << mi << endl;

}
