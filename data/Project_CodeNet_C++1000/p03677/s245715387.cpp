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
const ld eps = 1e-9;
const ll MOD = 1000000007;
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

template<typename T1, typename T2>
ostream& operator<<(ostream &os, const pair<T1, T2> p) {
  os << p.first << ":" << p.second;
  return os;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);

  ll n, m; cin >> n >> m;
  vll a(n);
  for(int i=0;i<n;++i) {
    cin >> a[i];
    a[i]--;
  }

  vll v(m);
  vll suin(2*m), suout(2*m);
  vll cntin(2*m), cntout(2*m);

  ll ans = 0;
  for(int i=0;i<n-1;++i) {
    int x = a[i], y = a[i+1];
    if(x > y) {
      y += m;
    }
    ans += y - x;
    suin[x] += x;
    cntin[x]++;
    suout[y] += x;
    cntout[y]++;
  }
  ll su = 0, cnt = 0;
  for(int i=0;i<2*m;++i) {
    v[i%m] += (i-1) * cnt - su;

    su += suin[i] - suout[i];
    cnt += cntin[i] - cntout[i];
  }
  //printv(v);

  ll ma = 0;
  for(int i=0;i<m;++i) {
    ma = max(ma, v[i]);
  }

  cout << ans - ma << endl;
}
