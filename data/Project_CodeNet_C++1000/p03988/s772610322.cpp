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
  vector<int> a(n);
  map<int, int> mp;
  int mi = INF, ma = 0;
  for(int i=0;i<n;++i) {
    cin >> a[i];
    mp[a[i]]++;
    mi = min(mi, a[i]);
    ma = max(ma, a[i]);
  }
  bool ok = false;
  if(mp[mi] == 1) {
    ok = mi * 2 == ma;
    for(int i=mi+1;i<ma;++i) {
      if(mp[i] < 2) {
        ok = false;
        break;
      }
    }
  } else if(mp[mi] == 2) {
    ok = mi * 2 == ma + 1;
    for(int i=mi+1;i<ma;++i) {
      if(mp[i] < 2) {
        ok = false;
        break;
      }
    }
  }
  cout << (ok ? "Possible" : "Impossible") << endl;
}
