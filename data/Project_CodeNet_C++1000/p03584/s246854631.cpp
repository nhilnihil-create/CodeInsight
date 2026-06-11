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
  ll n, k; cin >> n >> k;
  vector<ll> a(n), b(n);
  for(int i=0;i<n;++i) {
    cin >> a[i] >> b[i];
  }
  vector<ll> pos = {k};
  for(int i=1;i<30;++i) {
    if(k & (1<<i)) {
      pos.push_back((k ^ (1<<i)) | ((1<<i) - 1));
    }
  }
  int sz = (int)(pos.size());
  ll ma = 0;
  for(int i=0;i<sz;++i) {
    ll now = 0;
    for(int j=0;j<n;++j) {
      if((pos[i] | a[j]) == pos[i]) now += b[j];
    }
    ma = max(ma, now);
  }
  cout << ma << endl;
}
